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

void MainWindow::on_btnAdd_clicked()
{
    if(ui->txtItem->text().trimmed().compare("")) {
        ui->lstItens->addItem(ui->txtItem->text().trimmed());

        ui->txtItem->clear();
        ui->txtItem->setFocus();
    }
}


void MainWindow::on_btnAdAs_clicked()
{
    QListWidgetItem *item1 = new QListWidgetItem("C++");
    QListWidgetItem *item2 = new QListWidgetItem("C#");
    QListWidgetItem *item3 = new QListWidgetItem("PHP");
    QListWidgetItem *item4 = new QListWidgetItem("Java");
    QListWidgetItem *item5 = new QListWidgetItem("Python");

    ui->lstItens->addItem(item1);
    ui->lstItens->addItem(item2);
    ui->lstItens->addItem(item3);
    ui->lstItens->addItem(item4);
    ui->lstItens->addItem(item5);
}


void MainWindow::on_btnMarc_clicked()
{
    if(ui->lstItens->currentRow() != -1) {
        if(marcados.indexOf(ui->lstItens->currentRow()) == -1) {
            ui->lstItens->currentItem()->setForeground(Qt::lightGray);
            ui->lstItens->currentItem()->setBackground(Qt::darkGreen);

            marcados.push_back(ui->lstItens->currentRow());

            qDebug() << "Marcados: " << marcados;
        }
    }
}


void MainWindow::on_btnDesm_clicked()
{
    if(ui->lstItens->currentRow() != -1) {
        if(marcados.indexOf(ui->lstItens->currentRow()) >= 0) {
            ui->lstItens->currentItem()->setForeground(Qt::black);
            ui->lstItens->currentItem()->setBackground(Qt::white);

            marcados.erase(marcados.begin() + marcados.indexOf(ui->lstItens->currentRow()));

            qDebug() << "Marcados: " << marcados;
        }
    }
}


void MainWindow::on_btnDesmTod_clicked()
{
    while(!marcados.empty()) {
        ui->lstItens->setCurrentRow(marcados.last());
        ui->lstItens->currentItem()->setForeground(Qt::black);
        ui->lstItens->currentItem()->setBackground(Qt::white);
        marcados.pop_back();
    }
}

