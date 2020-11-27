#ifndef PROCESSCOMPILE_H
#define PROCESSCOMPILE_H

#include <QDebug>
#include <QProcess>
#include <QStringList>

#ifdef Q_OS_WIN32
#include <windows.h>
#endif

class ProcessCompile : public QObject
{
    Q_OBJECT
public:
    explicit ProcessCompile(QObject *parent = 0);

    QMap<int, QProcess*>myServerProcessMap;

    QProcess *compileProcess;

    QString stdoutBuffer;
    QString stderrBuffer;

    int startCompile(QString extensionName, QString path_extBase, QString path_compileBase, QString path_phpSDKBase);

signals:

    void signal_compileStarted(QString, Q_PID);
    void signal_compileFinished(QString, int);
    void signal_compileStdOut(QString, Q_PID);
    void signal_compileStdErr(QString, Q_PID);

public slots:

    // process slots
    void slot_compile_Started();
    void slot_compile_Finished(int);
    void slot_compile_readyReadStandardOutput();
    void slot_compile_readyReadStandardError();


private slots :
    void slot_compile_error(QProcess::ProcessError error);

};

#endif // PROCESSCOMPILE_H
