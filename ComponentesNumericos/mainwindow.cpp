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

void MainWindow::on_btnVerif_clicked()
{
    int num = ui->numEntr->value();

    int dobro = num * 2;

    QMessageBox::information(this, "Informação", "O dobro de " + QString::number(num) + " é " + QString::number(dobro) + ".");
}

void MainWindow::on_sliNum_actionTriggered(int action)
{
    ui->lblNum->setText(QString::number(ui->sliNum->value()));
}

