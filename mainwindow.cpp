#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QtCore>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a=new Apache;

    setWindowIcon(QIcon("m.png"));
    setCentralWidget(a);
    setWindowTitle("ApacheConfigurator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//7e287a
