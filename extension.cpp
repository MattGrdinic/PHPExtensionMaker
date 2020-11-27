#include "extension.h"

Extension::Extension(QObject *parent) :
    QObject(parent)
{
}

bool Extension::setLocation(QString &location)
{
    this->location = location;

    QString extensionName;
    QString path_extBase;
    QString path_compileBase;
    QString path_phpSDKBase;

    QFileInfo info(location);


    // set compile paths
#ifdef Q_OS_WIN32

    // Windows requires PHP folder structure defined in:
    // https://wiki.php.net/internals/windows/stepbystepbuild

    QStringList path;

    if(location.contains("\\")){
        path = location.split("\\"); // fresh load
    } else {
        path = location.split("/"); // recent extensions
    }

    QStringListIterator i(path);


    if(!path.isEmpty() && path.length() > 5){

        // get path_extBase

        if(info.isFile()){

            path.pop_back();

            // get extensionName
            this->extensionName = path.last();

            path.pop_back();

            i = path;

            while(i.hasNext())
                path_extBase += i.next() + "/";

            this->path_extBase = path_extBase;

        } else {

            // get extensionName
            this->extensionName = path.last();

            path.pop_back();

            i = path;

            while(i.hasNext())
                path_extBase += i.next() + "/";

            this->path_extBase = path_extBase;

        }

        // get path_compileBase

        path.pop_back();

        i = path;

        while(i.hasNext())
            path_compileBase += i.next() + "/";

        this->path_compileBase = path_compileBase;


        // get path_phpSDKBase

        path.pop_back();
        path.pop_back();
        path.pop_back();
        path.pop_back();

        i = path;

        while(i.hasNext())
            path_phpSDKBase += i.next() + "/";

        this->path_phpSDKBase = path_phpSDKBase;

        return true;


    } else {

        // Warn user about invalid path structure
        QMessageBox m;
        m.setText("All extensions must reside in the path structure defined in: https://wiki.php.net/internals/windows/stepbystepbuild.");
        m.exec();

        return false;

    }


#else

    // Linux builds require /php-sdk/ structure

    QStringList pathModified = dir.split("/");

    return true;

#endif
}

void Extension::loadExtension()
{

    // reset hash
    files.clear();

    phpFE.clear(); phpME.clear(); phpFunction.clear();

    // populate valid apps list
    QDirIterator i(this->location, QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);

    while(i.hasNext()){
        i.next();
        QString fileName = i.fileName();
        if(fileName == "."
                        || fileName == ""
                        || fileName == ".."
                        || fileName == ".DS_Store"){
            continue;
        }

        QString cString = ".c";

        if(fileName.contains(cString)){
            files[i.filePath()].data = "";
        }

        QString hString = ".h";

        if(fileName.contains(hString)){
            files[i.filePath()].data = "";
        }

    }

    // open and parse c files
    this->load_files();

    // if we do not have any c or h files, terminate
    if(files.count() == 0){
        QString message = "This folder doesn't contain any valid extension source files.";
        emit(signal_extension_load_failed(9, message));
        return;
    }

    // load config files
    bool hasm4 = load_m4_file();
    bool hasm32 = load_w32_file();


    // load phpFE and ME entries
    this->load_phpFE_phpME_entries(files.begin().key());
    this->load_phpFunction_entries(files.begin().key());


    // signal to load ui
    emit(signal_extension_load_finished());

}

void Extension::load_files()
{

    QHashIterator<QString, fileData> i(files);

    while (i.hasNext()) {

        i.next();

        QFile file(i.key());

        if(file.open(QIODevice::ReadOnly)){
            files[i.key()].data = file.readAll();
        }

    }

}

QString Extension::get_file(QString key)
{
    return files.value(key).data;
}

// attempts to return a related h file for a given c file key
QString Extension::get_h_file(QString key)
{

    QString ref_name = key;

    // standard name
    QString standard_name = ref_name.replace(".c", ".h");

    // most "official" php extensions use php_ prefix for h files
    QString standard_php_name = standard_name;

    QStringList pathModified = standard_name.split("/");

    if(!pathModified.isEmpty()){

        standard_php_name = "";

        QString fileName = pathModified[pathModified.length() - 1];

        pathModified.pop_back();

        QStringListIterator i(pathModified);

        while(i.hasNext())
            standard_php_name += i.next() + "/";

        // add back on normal file name
        standard_php_name += "php_" + fileName;
    }

    // do any of the new values exist as keys?
    if(files.contains(standard_name)){
        this->current_h_file = standard_name;
        return files[standard_name].data;
    }

    if(files.contains(standard_php_name)){
        this->current_h_file = standard_php_name;
        qDebug() << "H File Data: " << files[standard_php_name].data;
        return files[standard_php_name].data;
    }

    this->current_h_file = "";
    return "";

}

// attempts to return a related c file for a given h file
QString Extension::get_c_file(QString key)
{

    QString ref_name = key;

    // standard name
    QString standard_name = ref_name.replace(".h", ".c");

    QString basic_name = ref_name.replace("php_", "");

    // do any of the new values exist as keys?
    if(files.contains(standard_name)){

        load_phpFE_phpME_entries(standard_name);
        load_phpFunction_entries(standard_name);

        this->current_c_file = standard_name;

        return files[standard_name].data;
    }

    if(files.contains(basic_name)){

        load_phpFE_phpME_entries(basic_name);
        load_phpFunction_entries(basic_name);

        this->current_c_file = basic_name;

        return files[basic_name].data;
    }

    return "";

}

void Extension::set_file(QString key, QString data)
{

    qDebug() << "Initial Value:" << files[key].data;
    if(files[key].data != data){
        files[key].data = data;
        qDebug() << "Updated Value:" << files[key].data;
        set_dirty(key);
    }

}

void Extension::set_dirty(QString key)
{
    qDebug() << "set_dirty called";

    files[key].dirty = true;
}

bool Extension::load_m4_file()
{
    QFile m4File(this->location + "/config.m4");

    if(m4File.open(QIODevice::ReadOnly)){
        config_m4 = m4File.readAll();
        return true;
    }

    return false;
}

QString Extension::get_m4_file()
{
    return this->config_m4;
}

void Extension::set_m4_file(QString data)
{
    this->config_m4 = data;
}


bool Extension::load_w32_file()
{
    QFile w32File(this->location + "/config.w32");

    if(w32File.open(QIODevice::ReadOnly)){
        config_w32 = w32File.readAll();
        return true;
    }
    return false;
}

QString Extension::get_w32_file()
{
    return this->config_w32;
}

void Extension::set_w32_file(QString data)
{
    this->config_w32 = data;
}


void Extension::processExtension()
{

}


/* phpFE and phpME */
void Extension::load_phpFE_phpME_entries(QString key)
{

    phpFE.clear(); phpME.clear();

    // get c files list
    QString cFile = files.value(key).data;

    if(cFile == ""){
        return;
    }

    int count = cFile.count("PHP_FE(");

    if(count == 0){
        return;
    }

    int matches = 0;

    int index = 0;
    int end = 0;

    while(matches < count){
        index = cFile.indexOf("PHP_FE(", end);
        end = cFile.indexOf(")", index);

        QString extract = cFile.mid(index, ((end + 1) - index));
        extract = extract.replace("\n", "");
        extract = extract.replace("\t", "");

        this->phpFE << extract;
        matches++;
    }
}

void Extension::load_phpFunction_entries(QString key)
{

    phpFunction.clear();

    // get c files list
    QString cFile = files.value(key).data;

    if(cFile == ""){
        return;
    }

    int count = cFile.count("PHP_FUNCTION(");

    if(count == 0){
        return;
    }

    int matches = 0;

    int index = 0;
    int end = 0;

    while(matches < count){
        index = cFile.indexOf("PHP_FUNCTION(", end);
        end = cFile.indexOf(")", index);

        QString extract = cFile.mid(index, ((end + 1) - index));
        extract = extract.replace("\n", "");
        extract = extract.replace("\t", "");

        this->phpFunction << extract;
        matches++;
    }
}
