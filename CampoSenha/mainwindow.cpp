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

void MainWindow::on_btnEntr_clicked()
{
    QString login = ui->txtLogin->text().trimmed();
    QString senha = ui->txtSenha->text().trimmed();

    if(!login.compare("admin") && !senha.compare("123")) {
        QMessageBox::information(this, "Login", "Bem-Vindo ao Sistema!");
    }
    else {
        QMessageBox::critical(this, "Login", "Usuário ou Senha Incorreta!");
    }
}

