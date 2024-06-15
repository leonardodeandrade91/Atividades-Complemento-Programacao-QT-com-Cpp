#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap logo(":/imgs/imagens/idiomas.png");

    ui->lblImg->setPixmap(logo);
}

MainWindow::~MainWindow()
{
    delete ui;
}
