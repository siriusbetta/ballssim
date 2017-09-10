#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QScopedPointer>
#include <QDateTime>
#include <QTextStream>
#include <thread>
#include "physicsthread.h"

QScopedPointer <QFile> m_logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context,
        const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    m_logFile.reset(new QFile("logs.txt"));
    m_logFile.data()->open(QFile::Append | QFile::Text);

    qInstallMessageHandler(messageHandler);


    MainWindow w;
    w.show();


    std::thread physicsThread( (PhysicsThread()));
    physicsThread.detach();
    return a.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context,
        const QString &msg)
{
    QTextStream out(m_logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");

    switch(type)
    {
         case QtInfoMsg:
               out << "INF" ;
               break;
         case QtDebugMsg:
               out << "DBG" ;
               break;
         case QtWarningMsg:
               out << "WRN" ;
               break;
         case QtCriticalMsg:
              out << "CRT" ;
               break;
         case QtFatalMsg:
               out << "FTL" ;
               break;
    }
    out << context.category << ": " << msg << endl;
    out.flush();
}
