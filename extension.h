#ifndef EXTENSION_H
#define EXTENSION_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include <QRegExp>
#include <QDirIterator>
#include <QTextStream>
#include <QHash>
#include <QList>
#include <QMessageBox>

#include "filedata.h"

class Extension : public QObject
{
    Q_OBJECT

public:
    explicit Extension(QObject *parent = 0);

    // data
    QString location;

    QString extensionName;
    QString path_extBase;
    QString path_phpSDKBase;
    QString path_compileBase;

    QString config_m4;
    QString config_w32;

    QString current_h_file;
    QString current_c_file;

    QHash<QString, fileData> files;
    QList<QString> files_keys;

    QStringList phpFE, phpME, phpFunction;
    QStringList internalFunctions;
    QStringList iniItems;
    QStringList argInfoEntries;

    // functions
    bool setLocation(QString&);
    void loadExtension();
    void processExtension();

    void load_files();

    QString get_file(QString key);
    QString get_h_file(QString key);
    QString get_c_file(QString key);

    void set_file(QString key, QString data);
    void set_dirty(QString key);

    bool load_m4_file();
    bool load_w32_file();

    QString get_m4_file(); void set_m4_file(QString);
    QString get_w32_file(); void set_w32_file(QString);

    void load_phpFE_phpME_entries(QString key);
    void load_phpFunction_entries(QString key);
    
signals:
    void signal_extension_load_finished();
    void signal_extension_load_failed(int, QString);

public slots:

private :
    QRegExp zend_function_entry;
    
};

#endif // EXTENSION_H
