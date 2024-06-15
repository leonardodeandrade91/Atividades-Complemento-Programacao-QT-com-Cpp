#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->btnStat);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOk_clicked()
{
    ui->statusbar->showMessage("Nome: " + ui->txtNome->text().trimmed() + " | E-mail: " + ui->txtMail->text().trimmed());
}


void MainWindow::on_btnStat_clicked()
{
    QString msg = "Mensagem do Status!";

    ui->statusbar->showMessage(msg);

    QMessageBox::about(this, "Canal", msg);
}

