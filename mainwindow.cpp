#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "processcompile.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setupEditors();

    this->init_extension();

    this->create_menu_connections();
    this->create_editor_connections();
    this->create_list_widget_connections();

    readSettings();
    updateRecentExtensionActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_menu_connections()
{
    connect(this->ui->actionLoad_Extension, SIGNAL(triggered()),
            this, SLOT(actionLoad_Extension()));

    ui->actionSave_Current_Document->setShortcut(tr("Ctrl+S"));
    connect(this->ui->actionSave_Current_Document, SIGNAL(triggered()),
            this, SLOT(actionSave_Current_Document()));

    connect(this->ui->actionSave_All_Documents, SIGNAL(triggered()),
            this, SLOT(saveAll()));

    for(int i = 0; i < MaxRecentExtensions; ++i){
        recentExtensionActions[i] = new QAction(this);
        recentExtensionActions[i]->setVisible(false);
        connect(recentExtensionActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentExtension()));
    }

    // populate recent file menu items
    for(int i = 0; i < MaxRecentExtensions; ++i){
        ui->menuFile->addAction(recentExtensionActions[i]);
    }

    // add exit menu item
    ui->menuFile->addSeparator();

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    ui->menuFile->addAction(exitAction);
    connect(exitAction, SIGNAL(triggered()),
            this, SLOT(close()));

}

void MainWindow::setupEditors()
{
    fileChanged = false;

    // apply syntax highlighter
    highlighter_c_file = new Highlighter(this->ui->textEdit_cFile->document());
    highlighter_h_file = new Highlighter(this->ui->textEdit_hFile->document());
}

void MainWindow::create_editor_connections()
{
    connect(this->ui->textEdit_cFile, SIGNAL(textChanged()),
            this, SLOT(slot_cFile_textChanged()));

    connect(this->ui->textEdit_hFile, SIGNAL(textChanged()),
            this, SLOT(slot_hFile_textChanged()));

    connect(this->ui->plainTextEdit_config_m4, SIGNAL(undoAvailable(bool)),
            this, SLOT(slot_m4_textChanged()));

    connect(this->ui->plainTextEdit_config_w32, SIGNAL(undoAvailable(bool)),
            this, SLOT(slot_w32_textChanged()));

    connect(this->ui->pushButton_compileExtension, SIGNAL(clicked()),
            this, SLOT(slot_compile_extension()));

    connect(this->ui->pushButton_compileClearOutput, SIGNAL(clicked()),
            this, SLOT(slot_compile_clearOutputMessages()));

    connect(this->ui->tabWidget, SIGNAL(currentChanged(int)),
            this, SLOT(slot_tabWidget_currentChanged(int)));

}

void MainWindow::create_list_widget_connections()
{
    connect(this->ui->listWidget_extensionFiles, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(slot_listWidgetExtensionFile_changed(QListWidgetItem*)));

    connect(this->ui->listWidget_phpFE, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(slot_listWidgetPHPFE_changed(QListWidgetItem*)));
}

void MainWindow::openRecentExtension()
{
    if(okToContinue()){
        QAction *action = qobject_cast<QAction *>(sender());
        if(action)
            loadExtension(action->data().toString());
    }
}

bool MainWindow::hasPendingSaveOperations()
{

    for(int i = 0; i < ui->listWidget_extensionFiles->count(); i++){
        QListWidgetItem *it = ui->listWidget_extensionFiles->currentItem();
        if(it->textColor() == Qt::red){
            return true;
        }
    }

    return false;
}

void MainWindow::updateRecentExtensionActions()
{
    QMutableStringListIterator i(recentExtensions);

    while(i.hasNext()){
        if(!QFile::exists(i.next()))
            i.remove();
    }

    for(int j = 0; j < MaxRecentExtensions; ++j){
        if(j < recentExtensions.count()){
            QString text = tr("&%1 %2")
                    .arg(j + 1)
                    .arg(recentExtensions[j]);
            recentExtensionActions[j]->setText(text);
            recentExtensionActions[j]->setData(recentExtensions[j]);
            recentExtensionActions[j]->setVisible(true);
        } else {
            recentExtensionActions[j]->setVisible(false);
        }
    }

}

bool MainWindow::okToContinue()
{
    if(hasPendingSaveOperations()){
        int r = QMessageBox::warning(this, tr("PHPExtensionMaker"),
                                     tr("You have unsaved documents.\n"
                                        "Do you want to save your changes?"),
                                     QMessageBox::Yes | QMessageBox::No
                                     | QMessageBox::Cancel);
        if(r == QMessageBox::Yes){
            return saveAll();
        } else if (r == QMessageBox::Cancel){
            return false;
        }
    }
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(hasPendingSaveOperations()){
        if(okToContinue()){
            writeSettings();
            event->accept();
        } else {
            event->ignore();
        }
    }
}

void MainWindow::readSettings()
{
    QSettings settings("nicSoft", "PHPExtensionMaker");

    recentExtensions = settings.value("recentExtensions").toStringList();

}

void MainWindow::writeSettings()
{
    QSettings settings("nicSoft", "PHPExtensionMaker");

    settings.setValue("recentExtensions", recentExtensions);
}

// updated when we switch tabs, load a file, etc.
void MainWindow::setCurrentDocumentName(QString documentName)
{
    currentDocumentName = documentName;
    //qDebug() << "Current Document Name: " << currentDocumentName;
}

QString MainWindow::getCurrentDocumentName()
{
    return currentDocumentName;
}

bool MainWindow::saveAll()
{

    QHashIterator<QString, fileData> it(extension->files);

    while(it.hasNext()){

        it.next();

        if(it.value().dirty){

            QFile f(it.key());
            f.open(QIODevice::WriteOnly);
            QTextStream s(&f);
            s << extension->get_file(it.key());
            extension->files[it.key()].dirty = false;
            f.close();

        }

    }

    highlightDirtyFiles();

    return true;
}

void MainWindow::highlightDirtyFiles()
{

    for(int i = 0; i < ui->listWidget_extensionFiles->count(); i++){

        QListWidgetItem *item = ui->listWidget_extensionFiles->item(i);

        fileData d = extension->files.value(item->text());

        if(extension->files.value(item->text()).dirty){

            item->setTextColor(Qt::red);

        } else {

            item->setTextColor(Qt::black);

        }
    }

}

/**
  Called from constructor
  */
void MainWindow::init_extension()
{
    // create extension object
    extension = new Extension();

    // create conections for Extension
    connect(extension, SIGNAL(signal_extension_load_finished()),
            this, SLOT(slot_buildUI()));

    connect(extension, SIGNAL(signal_extension_load_failed(int, QString)),
            this, SLOT(slot_MessageCenter(int, QString)));

    QString loc = "";

    //extension->setLocation(loc);
}

/**
  SLOT: Called When We Use The Main Menu Item Load Extension Action.
  */
void MainWindow::actionLoad_Extension()
{

    // memory
    QSettings settings("nicSoft", "PHPExtensionMaker");

    // load existing ext directory if possible
    QString path = "/home";

    if(settings.value("phpExtPath").toString() != "defaultValue"){

        path = settings.value("phpExtPath").toString();

        // make sure path exists
        if(!QFile::exists(path))
            path = "/home";
    }

    // open/select directory dialog

    QString dir = QFileDialog::getExistingDirectory(
            this, tr("Select Extension Directory"),
            path,
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(dir != "") {

        // update any UI elements
        this->ui->statusBar->showMessage(dir);

        if(!extension->setLocation(dir))
            return;

        // update compile location UI elements
        ui->label_path_extBase->setText(extension->path_extBase);
        ui->label_path_compileBase->setText(extension->path_compileBase);
        ui->label_path_phpSDKBase->setText(extension->path_phpSDKBase);

        // send location to loadExtension()
        extension->loadExtension();

        // save path for next load though as main ext dir, not the current folder

#ifdef Q_OS_WIN32
        QStringList pathModified = dir.split("\\");
#else
        QStringList pathModified = dir.split("/");
#endif
        if(!pathModified.isEmpty()){

            dir = ""; // reset string

            pathModified.pop_back();

            QStringListIterator i(pathModified);

            while(i.hasNext())
                dir += i.next() + "/";
        }

        settings.setValue("phpExtPath", dir);
        settings.setValue("recentExtensions", recentExtensions);

    }

}

// called from recent extensions logic
bool MainWindow::loadExtension(QString dir)
{
    if(dir != "") {

        // get just the path 
        QFileInfo pathInfo(dir);

        if(pathInfo.isFile()){

            dir = pathInfo.path();

        }

        // update any UI elements
        this->ui->statusBar->showMessage(dir);

        // update model
        if(!extension->setLocation(dir))
            return false;


        // update compile location UI elements
        ui->label_path_extBase->setText(extension->path_extBase);
        ui->label_path_compileBase->setText(extension->path_compileBase);
        ui->label_path_phpSDKBase->setText(extension->path_phpSDKBase);

        // send location to loadExtension()
        extension->loadExtension();

        return true;

    } else {

        return false;

    }
}

void MainWindow::actionSave_Current_Document()
{

    int tabIndex = ui->tabWidget->currentIndex();

    QString fileData;

    switch(tabIndex){
    case 0 :
        fileData = this->ui->textEdit_cFile->toPlainText();
        break;
    case 1 :
        fileData = this->ui->textEdit_hFile->toPlainText();
    }

    QString savePath = getCurrentDocumentName();

    QFile f(savePath);
    f.open(QIODevice::WriteOnly);
    QTextStream s(&f);
    s << fileData;
    f.close();

    // update UI
    QListWidgetItem *item = ui->listWidget_extensionFiles->currentItem();

    // update model
    extension->files[item->text()].dirty = false;

    // set this rows proper color
    highlightDirtyFiles();

}

// Called via extention.cpp > signal_extension_load_finished()
bool MainWindow::slot_buildUI()
{

    // STEP: display extension files

    // clear any existing entires
    this->ui->listWidget_extensionFiles->clear();

    // load all files
    QHashIterator<QString, fileData> it(extension->files);

    while(it.hasNext()){

        it.next();

        new QListWidgetItem(it.key(), this->ui->listWidget_extensionFiles);

    }

    // set first file as active if possible
    if(ui->listWidget_extensionFiles->count() != 0){
        this->ui->listWidget_extensionFiles->setCurrentRow(0);

        // set this as the current document
        setCurrentDocumentName(ui->listWidget_extensionFiles->currentItem()->text());
    }

    // display this new file in the text editor

    if(ui->listWidget_extensionFiles->currentItem()->text().contains(".c")){

        this->ui->textEdit_cFile->setPlainText(extension->get_file(ui->listWidget_extensionFiles->currentItem()->text()));
        this->ui->textEdit_hFile->setPlainText(extension->get_h_file(ui->listWidget_extensionFiles->currentItem()->text()));

        this->ui->label_cFile->setText(ui->listWidget_extensionFiles->currentItem()->text());
        this->ui->label_hFile->setText(extension->current_h_file); // TODO: get key from this call

        extension->load_phpFE_phpME_entries(ui->listWidget_extensionFiles->currentItem()->text());
        extension->load_phpFunction_entries(ui->listWidget_extensionFiles->currentItem()->text());

        ui->tabWidget->setCurrentIndex(0);

    } else if(ui->listWidget_extensionFiles->currentItem()->text().contains(".h")){

        this->ui->textEdit_hFile->setPlainText(extension->get_file(ui->listWidget_extensionFiles->currentItem()->text()));
        this->ui->textEdit_cFile->setPlainText(extension->get_c_file(ui->listWidget_extensionFiles->currentItem()->text()));

        this->ui->label_cFile->setText(extension->current_c_file); // TODO: get key from these calls
        this->ui->label_hFile->setText(ui->listWidget_extensionFiles->currentItem()->text());

        ui->tabWidget->setCurrentIndex(1);
    }


    this->buildPHPFE_entries();
    this->buildPHPFunction_entries();


    // display config files
    this->ui->plainTextEdit_config_m4->setPlainText(extension->get_m4_file());
    this->ui->plainTextEdit_config_w32->setPlainText(extension->get_w32_file());

    // update recent extensions logic

    QFileInfo pathInfo(ui->listWidget_extensionFiles->currentItem()->text());
    QString dir = pathInfo.path();

    recentExtensions.removeAll(dir);
    recentExtensions.prepend(dir);

    updateRecentExtensionActions();

    // reset recent files
    for(int i = 0; i < ui->listWidget_extensionFiles->count(); i++){
        QListWidgetItem *it = ui->listWidget_extensionFiles->currentItem();
        it->setTextColor(Qt::black);
    }

    return true;
}

void MainWindow::slot_cFile_textChanged()
{

    if(ui->listWidget_extensionFiles->currentIndex().row() != -1){

        // which file is active
        QListWidgetItem *item = ui->listWidget_extensionFiles->currentItem();

        // highlight that row
        item->setTextColor(Qt::red);

        // update model
        extension->set_file(ui->label_cFile->text(),
                              ui->textEdit_cFile->toPlainText());

        highlightDirtyFiles();

        fileChanged = false;

    }


}

void MainWindow::slot_hFile_textChanged()
{

    if(ui->listWidget_extensionFiles->currentIndex().row() != -1){

        // which file is active
        QListWidgetItem *item = ui->listWidget_extensionFiles->currentItem();

        // highlight that row
        item->setTextColor(Qt::red);

        // update model
        extension->set_file(ui->label_hFile->text(),
                              ui->textEdit_hFile->toPlainText());

        highlightDirtyFiles();

        fileChanged = false;
    }

}

// SLOT: QListWidgetItems
void MainWindow::slot_listWidgetExtensionFile_changed(QListWidgetItem* item)
{

    fileChanged = true;

    // which tab is active, save that document
//    switch(ui->tabWidget->currentIndex()){
//    case 0 :
//        extension->set_file(currentDocumentName, this->ui->textEdit_cFile->toPlainText());
//        break;
//    case 1 :
//        extension->set_file(currentDocumentName, this->ui->textEdit_hFile->toPlainText());
//        break;
//    }

    qDebug() << "DATA" << extension->files["C:/php-sdk/php54dev/vc9/x86/php5.4-201204110330/ext/assembly/php_assembly.h"].data;

    // set current document before we load anything else!
    setCurrentDocumentName(ui->listWidget_extensionFiles->currentItem()->text());


    // display this new file in the text editor

    if(ui->listWidget_extensionFiles->currentItem()->text().contains(".c")){

        this->ui->textEdit_cFile->setPlainText(extension->get_file(ui->listWidget_extensionFiles->currentItem()->text()));

        // do not reload if the file is already showing
        QString existing = extension->get_h_file(ui->listWidget_extensionFiles->currentItem()->text());
        if(ui->textEdit_hFile->toPlainText() != existing){
            this->ui->textEdit_hFile->setPlainText(extension->get_h_file(ui->listWidget_extensionFiles->currentItem()->text()));
        }

        this->ui->label_cFile->setText(ui->listWidget_extensionFiles->currentItem()->text());
        this->ui->label_hFile->setText(extension->current_h_file); // TODO: get key from this call

        extension->load_phpFE_phpME_entries(item->text());
        extension->load_phpFunction_entries(item->text());

        ui->tabWidget->setCurrentIndex(0);

    } else if(ui->listWidget_extensionFiles->currentItem()->text().contains(".h")){

        this->ui->textEdit_hFile->setPlainText(extension->get_file(ui->listWidget_extensionFiles->currentItem()->text()));

        // do not reload if the file is already showing
        QString existing = extension->get_c_file(ui->listWidget_extensionFiles->currentItem()->text());
        if(ui->textEdit_cFile->toPlainText() != existing){
            this->ui->textEdit_cFile->setPlainText(extension->get_c_file(ui->listWidget_extensionFiles->currentItem()->text()));
        }

        this->ui->label_cFile->setText(extension->current_c_file); // TODO: get key from these calls
        this->ui->label_hFile->setText(ui->listWidget_extensionFiles->currentItem()->text());

        ui->tabWidget->setCurrentIndex(1);
    }

    this->buildPHPFE_entries();
    this->buildPHPFunction_entries();

    highlightDirtyFiles();

    fileChanged = false;

}

void MainWindow::slot_m4_textChanged()
{
    // update model
    extension->set_m4_file(ui->plainTextEdit_config_m4->toPlainText());

    // save file strait away
    QFile f(extension->location + "/config.m4");
    f.open(QIODevice::WriteOnly);
    QTextStream s(&f);
    s << extension->get_m4_file();
    f.close();

}

void MainWindow::slot_w32_textChanged()
{
    // update model
    extension->set_w32_file(ui->plainTextEdit_config_w32->toPlainText());

    // save file strait away
    QFile f(extension->location + "/config.w32");
    f.open(QIODevice::WriteOnly);
    QTextStream s(&f);
    s << extension->get_w32_file();
    f.close();
}

void MainWindow::slot_tabWidget_currentChanged(int index)
{
    switch(index){
    case 0 :
        this->currentDocumentName = ui->label_cFile->text();
        break;
    case 1 :
        this->currentDocumentName = ui->label_hFile->text();
        break;
    }

    // highlight this item in the listWidget
    for(int i = 0; i < ui->listWidget_extensionFiles->count(); i++){
        QList <QListWidgetItem *> l = ui->listWidget_extensionFiles->findItems(currentDocumentName, Qt::MatchExactly);
        if(l.count() != 0){
             ui->listWidget_extensionFiles->setCurrentItem(l.first());
        }
    }

}


void MainWindow::slot_compile_extension()
{

    // gather options
    process_compile = new ProcessCompile();

    connect(process_compile, SIGNAL(signal_compileStdOut(QString,Q_PID)),
            this, SLOT(slot_compile_OutputMessages(QString)));

    process_compile->startCompile(extension->extensionName,
                                  extension->path_extBase,
                                  extension->path_compileBase,
                                  extension->path_phpSDKBase);

}


void MainWindow::slot_compile_OutputMessages(QString message)
{
    ui->plainTextEdit_compile_out->appendPlainText(message);
}


void MainWindow::slot_compile_clearOutputMessages()
{
    ui->plainTextEdit_compile_out->clear();
}


void MainWindow::slot_listWidgetPHPFE_changed(QListWidgetItem* item)
{

    // find this text in the current c document
    QString code = extension->get_file(ui->label_cFile->text());

    QString raw_text = item->text();

    QString search_string = "";

    if(raw_text.count("PHP_FUNCTION") != 1){

        QString item_text_raw = raw_text.replace("PHP_FE(", "");

        QStringList split = item_text_raw.split(",");

        search_string = "PHP_FUNCTION(" + split[0] + ")";

    } else {

        search_string = raw_text;

    }

    int found = code.count(search_string); // will be something like PHP_FUNCTION(bcadd)

    // if found is zero we have a PHP_FE but no PHP_FUNCTION, just go to PHP_FE
    if(found == 0){
        search_string = "PHP_FE(" + raw_text;
        found = code.count(search_string);
    }


    // if found scroll to this function
    if(found != 0){

        // some extensions use static at the top, then define later on
        int pos = -1;

        if(found == 1){
            pos = code.indexOf(search_string);
        } else {
            // find last occurance of this item
            pos = code.lastIndexOf(search_string);
        }

        if(pos != -1){

            QTextCursor cursor(ui->textEdit_cFile->textCursor()); // returns copy

            // set cursor position
            cursor.setPosition(pos, QTextCursor::MoveAnchor);

            // move cursor to end of function name
            cursor.setPosition(pos + search_string.length(), QTextCursor::KeepAnchor);

            // set editor cursor to this new one *!important!*
            ui->textEdit_cFile->setTextCursor(cursor);

            // activate widget
            ui->textEdit_cFile->setFocus();

            // center cursor on this entry
            ui->textEdit_cFile->centerCursor();

        }

    }

}

void MainWindow::buildPHPFE_entries()
{
    this->ui->listWidget_phpFE->clear();

    QStringListIterator it(extension->phpFE);

    while(it.hasNext()){
        new QListWidgetItem(it.next(), this->ui->listWidget_phpFE);
    }
}

void MainWindow::buildPHPFunction_entries()
{
    QStringListIterator it(extension->phpFunction);

    while(it.hasNext()){
        new QListWidgetItem(it.next(), this->ui->listWidget_phpFE);
    }
}

void MainWindow::slot_MessageCenter(int severity, QString message)
{
    ui->statusBar->showMessage(message);
}


