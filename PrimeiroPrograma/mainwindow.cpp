#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    move(screen()->geometry().center() - frameGeometry().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClick_clicked()
{
    ui->lblText->setText("Olá, Mundo!");
}


void MainWindow::on_btnSeg_clicked()
{
    ui->lblText->setText("Primeiro Programa em QT!");
}

