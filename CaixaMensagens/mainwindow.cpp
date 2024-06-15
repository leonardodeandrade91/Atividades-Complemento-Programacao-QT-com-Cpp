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

void MainWindow::on_btnMens_clicked()
{
    QMessageBox::StandardButton verif;
    QString opc;

    verif = QMessageBox::question(this, "Pergunta", "Escolha um Botão!");

    opc = (verif == QMessageBox::Yes) ? "SIM" : "NÃO";

    QMessageBox::information(this, "Info", "Escolheu o " + opc + "!");
}

