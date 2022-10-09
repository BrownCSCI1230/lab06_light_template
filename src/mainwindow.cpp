#include "mainwindow.h"
#include "ui_mainwindow.h"

// You are NOT supposed to modify this file.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(768, 512+90);
}

MainWindow::~MainWindow()
{
    delete ui;
}

