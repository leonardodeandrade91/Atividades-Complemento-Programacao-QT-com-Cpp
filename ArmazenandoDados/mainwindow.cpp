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

void MainWindow::on_btnMost_clicked()
{
    QString nome = ui->txtNome->text().trimmed();
    QString fone = ui->txtTel->text().trimmed();
    QString mail = ui->txtMail->text().trimmed();

    QMessageBox::information(this, "Dados Digitados", "Nome: " + nome + "\nTelefone: " + fone + "\nE-mail: " + mail);
}


void MainWindow::on_btnLimp_clicked()
{
    ui->txtNome->clear();
    ui->txtTel->clear();
    ui->txtMail->clear();

    ui->txtNome->setFocus();
}

