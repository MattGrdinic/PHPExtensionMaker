#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QListWidgetItem>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QCloseEvent>

#include "extension.h"
#include "processcompile.h"

#include "highlighter.h"
#include "filedata.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Extension *extension;
    ProcessCompile *process_compile;

public slots :
    bool slot_buildUI();
    void slot_MessageCenter(int, QString);

private:
    Ui::MainWindow *ui;

    enum { MaxRecentExtensions = 5 };
    QAction *recentExtensionActions[MaxRecentExtensions];
    QStringList recentExtensions;
    void updateRecentExtensionActions();

    bool okToContinue();

    bool hasPendingSaveOperations();

    bool fileChanged;

    void highlightDirtyFiles();

    bool loadExtension(QString);

    void readSettings();
    void writeSettings();

    QString currentDocumentName;
    void setCurrentDocumentName(QString documentName);
    QString getCurrentDocumentName();

    void init_extension(); /* called in constructor */

    void create_menu_connections();
    void create_editor_connections();
    void create_list_widget_connections();

    void setupEditors();
    Highlighter *highlighter_c_file;
    Highlighter *highlighter_h_file;

    void buildPHPFE_entries();
    void buildPHPFunction_entries();

    QAction *exitAction;

protected:
    void closeEvent(QCloseEvent *event);

private slots :
    void actionLoad_Extension();
    void actionSave_Current_Document();

    bool saveAll();

    void openRecentExtension();

    void slot_cFile_textChanged();
    void slot_hFile_textChanged();

    void slot_m4_textChanged();
    void slot_w32_textChanged();

    void slot_tabWidget_currentChanged(int);

    void slot_compile_extension();

    // list widgets
    void slot_listWidgetExtensionFile_changed(QListWidgetItem* item);
    void slot_listWidgetPHPFE_changed(QListWidgetItem* item);

    void slot_compile_OutputMessages(QString);
    void slot_compile_clearOutputMessages();

};

#endif // MAINWINDOW_H
