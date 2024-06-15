#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::msg = "";
QString MainWindow::m1 = "";
QString MainWindow::m2 = "";
QString MainWindow::m3 = "";

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

void MainWindow::on_btnVer1_clicked()
{
    bool cb1, cb2, cb3;

    cb1 = ui->cxVerif1->isChecked();
    cb2 = ui->cxVerif2->isChecked();
    cb3 = ui->cxVerif3->isChecked();

    msg = "";

    if(cb1 == true) {
        msg += "Caixa 1 marcada!\n";
    }

    if(cb2 == true) {
        msg += "Caixa 2 marcada!\n";
    }

    if(cb3 == true) {
        msg += "Caixa 3 marcada!";
    }

    if(!msg.compare("")) {
        msg = "Nenhum marcado!";
    }

    QMessageBox::information(this, "Checkbox", msg);
}


void MainWindow::on_btnVer2_clicked()
{
    bool cb[3];

    cb[0] = ui->cxVerif1->isChecked();
    cb[1] = ui->cxVerif2->isChecked();
    cb[2] = ui->cxVerif3->isChecked();

    msg = "";

    for(int i = 0; i < 3; i++) {
        if(cb[i] == true) {
            msg += "Caixa " + QString::number((i + 1)) + " marcada!\n";
        }
    }

    if(!msg.compare("")) {
        msg = "Nenhum marcado!";
    }

    QMessageBox::information(this, "Checkbox", msg);
}


void MainWindow::on_btnVer3_clicked()
{
    msg = m1 + m2 + m3;

    QMessageBox::information(this, "Checkbox", msg);

    msg = "";
}


void MainWindow::on_cxVerif1_stateChanged(int arg1)
{
    msg = "";

    if(arg1) {
        m1 = "Caixa 1 marcada!\n";
    }
    else {
        m1 = "Caixa 1 desmarcada!\n";
    }
}


void MainWindow::on_cxVerif2_stateChanged(int arg1)
{
    msg = "";

    if(arg1) {
        m2 = "Caixa 2 marcada!\n";
    }
    else {
        m2 = "Caixa 2 desmarcada!\n";
    }
}


void MainWindow::on_cxVerif3_stateChanged(int arg1)
{
    msg = "";

    if(arg1) {
        m3 = "Caixa 3 marcada!";
    }
    else {
        m3 = "Caixa 3 desmarcada!";
    }
}

