#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap logo(":/imgs/imagens/desktop-e-celular.png");

    ui->lblImg->setPixmap(logo.scaled(100, 100, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnVerif_clicked()
{
    QString msg, cor, transp, prog;
    int numTr = 0;

    msg = "";

    if(ui->radVerm->isChecked()) {
        cor = "Vermelho";
    }
    else if(ui->radVerd->isChecked()) {
        cor = "Verde";
    }
    else if(ui->radAzul->isChecked()) {
        cor = "Azul";
    }

    if(ui->radAv->isChecked()) {
        numTr = 1;
    }
    else if(ui->radCar->isChecked()) {
        numTr = 2;
    }
    else if(ui->radNav->isChecked()) {
        numTr = 3;
    }

    switch(numTr) {
        case 1:
            transp = "Avião";
            break;
        case 2:
            transp = "Carro";
            break;
        case 3:
            transp = "Navio";
            break;
        default:
            transp = "Nenhum";
            break;
    }

    QVector<bool> lings;

    lings.push_back(ui->radCpp->isChecked());
    lings.push_back(ui->radCsh->isChecked());
    lings.push_back(ui->radJav->isChecked());

    if(lings[0]) {
        prog = "C++";
    }
    else if(lings[1]) {
        prog = "C#";
    }
    else if(lings[2]) {
        prog = "Java";
    }

    msg = "Cor: " + cor + "\nTransporte: " + transp + "\nLinguagem: " + prog;

    QMessageBox::information(this, "Mensagem", msg);
}


void MainWindow::on_btnImg_clicked()
{
    QPixmap img(":/imgs/imagens/usuarios.png");

    ui->lblImg->setPixmap(img.scaled(100, 100, Qt::KeepAspectRatio));
}


void MainWindow::on_itNov_triggered()
{
    NovoForm *formulario = new NovoForm(this);

    formulario->show();
}


void MainWindow::on_itEdi_triggered()
{
    QMessageBox::information(this, "Editado", "Editado com Sucesso!");
}


void MainWindow::on_itSalv_triggered()
{
    QMessageBox::information(this, "Salvo", "Salvo com Sucesso!");
}


void MainWindow::on_itSair_triggered()
{
    QApplication::quit();
}


void MainWindow::on_itPesq_triggered()
{
    QMessageBox::information(this, "Pesquisa", "Pesquisando...");
}

