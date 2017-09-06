#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600, 600);
    this->setFixedSize(600, 600);
    view = new ViewWindow();
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
