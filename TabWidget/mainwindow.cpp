#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::i = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    i = ui->tbAbas->count();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tbAbas_tabCloseRequested(int index)
{
    ui->tbAbas->removeTab(index);
    i--;
}


void MainWindow::on_btnAdd_clicked()
{
    i++;
    ui->tbAbas->addTab(new QWidget(), "Nova Aba: " + QString::number(i));
}


void MainWindow::on_btnFech_clicked()
{
    ui->tbAbas->removeTab(ui->tbAbas->currentIndex());
    i--;
}


void MainWindow::on_btnForm_clicked()
{
    i++;
    ui->tbAbas->addTab(new FormTab(), "Novo Cadastro");
}

