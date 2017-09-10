#include <QCoreApplication>
#include <QTest>
#include <iostream>
#include "testcoordinates.h"
#include "testcoordinatescontainer.h"
#include "testcollisions.h"

#include <QFile>
#include <QScopedPointer>
#include <QDateTime>
#include <QTextStream>

QScopedPointer <QFile> m_logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context,
        const QString &msg);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new TestCoordinatescontainer(), argc, argv);
    //QTest::qExec(new Testcollisions(), argc, argv);
    //QTest::qExec(new TestCoordinates(), argc, argv);

    m_logFile.reset(new QFile("logs.txt"));
    m_logFile.data()->open(QFile::Append | QFile::Text);

    qInstallMessageHandler(messageHandler);
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
