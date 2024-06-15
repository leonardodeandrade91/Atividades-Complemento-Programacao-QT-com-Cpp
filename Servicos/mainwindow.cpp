#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGoog_clicked()
{
    QString link = "https://www.google.com.br";

    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_btnPdf_clicked()
{
    QString caminho = "file:///C:/Program Files/Adobe/Acrobat DC/Acrobat/Acrobat.exe";

    QDesktopServices::openUrl(QUrl(caminho));
}


void MainWindow::on_btnCalc_clicked()
{
    QString caminho = "file:///C:/Windows/System32/calc.exe";

    QDesktopServices::openUrl(QUrl(caminho));
}
