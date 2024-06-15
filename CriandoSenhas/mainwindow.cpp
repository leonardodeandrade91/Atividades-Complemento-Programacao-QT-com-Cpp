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

void MainWindow::on_btnCrip_clicked()
{
    QString senha = ui->txtSenha->text().trimmed();

    QString encripta = QString(QCryptographicHash::hash(senha.toStdString().c_str(), QCryptographicHash::Md5).toHex());

    QMessageBox::information(this, "Hash", "Hash: " + encripta);
}

