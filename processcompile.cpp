#include "mainwindow.h"
#include "processcompile.h"

ProcessCompile::ProcessCompile(QObject *parent) :
    QObject(parent)
{
}

int ProcessCompile::startCompile(QString extensionName, QString path_extBase, QString path_compileBase, QString path_phpSDKBase)
{

    if(path_extBase == "" || path_compileBase == "" || path_phpSDKBase == "")
        return -1;


    compileProcess = new QProcess(this);

#ifdef Q_OS_WIN32

    QString program = "C:/Windows/System32/cmd.exe";

    QStringList arguments;

    // On Windows, paths with spaces are automatically quoted.
    arguments << "/E:ON"
              << "/V:ON"
              << "/T:0E"
              << "/K"
              << "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0\\Bin\\SetEnv.cmd";

#else

#endif


    QString vs_working_dir = "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0\\";

    if(path_phpSDKBase != ""){
        compileProcess->setWorkingDirectory(vs_working_dir); // path_phpSDKBase
    }

    connect(compileProcess, SIGNAL(started()),
            this, SLOT(slot_compile_Started()));

    connect(compileProcess, SIGNAL(finished(int)),
            this, SLOT(slot_compile_Finished(int)));

    connect(compileProcess, SIGNAL(readyReadStandardOutput()),
            this, SLOT(slot_compile_readyReadStandardOutput()));

    connect(compileProcess, SIGNAL(readyReadStandardError()),
            this, SLOT(slot_compile_readyReadStandardError()));

    connect(compileProcess, SIGNAL(error(QProcess::ProcessError)),
            this, SLOT(slot_compile_error(QProcess::ProcessError)));


    compileProcess->start(program, arguments);

    // Windows: Be sure to end all commands with \n
    // waitForBytesWritten() calls are always needed.

    if (!compileProcess->waitForStarted(1000))
             return -1;


    compileProcess->waitForReadyRead(100);
    compileProcess->waitForFinished(100);


    // set environment vars

    compileProcess->write("setenv /x86 /xp /release \n");

    // head into SDK base
    QString compile_path_command = "cd " + path_phpSDKBase + "\n";

    compileProcess->write(compile_path_command.toStdString().c_str());

    if(!compileProcess->waitForBytesWritten())
        return -1;

    // define php build vars
    compileProcess->write("bin\\phpsdk_setvars.bat \n");

    //compileProcess->waitForReadyRead(100);
    //compileProcess->waitForFinished(100);

    // head into php base
    compile_path_command = "cd " + path_compileBase + "\n";

    compileProcess->write(compile_path_command.toStdString().c_str());

    if(!compileProcess->waitForBytesWritten())
        return -1;

    // run configure
    compileProcess->write("buildconf.bat \n");

    if(!compileProcess->waitForBytesWritten())
        return -1;

    // run cscript
    QString cscript = "cscript /nologo configure.js --enable-" + extensionName + " --enable-debug" + " --enable-" + extensionName + "=shared \n";

    compileProcess->write(cscript.toStdString().c_str());

    if(!compileProcess->waitForBytesWritten())
        return -1;

    // compile
    QString nmake = "nmake php_" + extensionName + ".dll \n";

    compileProcess->write(nmake.toStdString().c_str());

    if(!compileProcess->waitForBytesWritten())
        return -1;



#ifdef Q_OS_WIN32

        // http://msdn.microsoft.com/en-us/library/windows/desktop/ms684873%28v=vs.85%29.aspx

        PROCESS_INFORMATION *pi;

        pi = compileProcess->pid();

        return pi->dwProcessId;
#else
        return compileProcess->pid();
#endif


}

// slots
void ProcessCompile::slot_compile_Started()
{

    QString myString = "";

    emit signal_compileStarted(myString, compileProcess->pid());

    emit signal_compileStdOut(myString, compileProcess->pid());

    qDebug() << "Compile Process Started";

}

void ProcessCompile::slot_compile_Finished(int statusCode)
{
    QString myString(compileProcess->readAllStandardError());

    emit signal_compileFinished(myString, statusCode);

    qDebug() << "Compile Process Finished: " << myString;

}

void ProcessCompile::slot_compile_readyReadStandardOutput()
{
    QString myString(compileProcess->readAllStandardOutput());

    emit signal_compileStdOut(myString, compileProcess->pid());

    qDebug() << "Compile Process Ouput: " << myString;

}

void ProcessCompile::slot_compile_readyReadStandardError()
{
    QString myString(compileProcess->readAllStandardError());

    emit signal_compileStdErr(myString, compileProcess->pid());

    qDebug() << "Compile Process Error: " << myString;
}

void ProcessCompile::slot_compile_error(QProcess::ProcessError error)
{
    qDebug() << "Process Error: " << error;
}
