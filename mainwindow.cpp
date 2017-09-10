#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "loggingcategories.h"
#include <QWidget>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600, 600);
    this->setFixedSize(600, 600);
    view = new ViewWindow();
    view->installEventFilter(this);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}



