#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::local = QDir::currentPath();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir unidades;

    foreach(QFileInfo qfi, unidades.drives()) {
        ui->cbUnid->addItem(qfi.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cbUnid_currentTextChanged(const QString &arg1)
{
    ui->lstDir->clear();

    ui->lstDir->addItem(arg1);

    QDir conteudo(arg1);

    foreach(QFileInfo qfi, conteudo.entryInfoList()) {
        if(qfi.isDir()) {
            ui->lstDir->addItem("Pasta: " + qfi.absoluteFilePath());
        }
    }
}


void MainWindow::on_btnAdd_clicked()
{
    local = ui->lstDir->currentItem()->text();

    QString nome = ui->txtDir->text().trimmed();

    QDir novodir(local + "/" + nome);

    if(novodir.exists()) {
        QMessageBox::warning(this, "Pasta", "Diretório " + nome + " já existe!");
    }
    else {
        novodir.mkdir(local + "/" + nome);

        ui->lstDir->clear();

        ui->lstDir->addItem(ui->cbUnid->currentText());

        QDir conteudo(ui->cbUnid->currentText());

        foreach(QFileInfo qfi, conteudo.entryInfoList()) {
            if(qfi.isDir()) {
                ui->lstDir->addItem("Pasta: " + qfi.absoluteFilePath());
            }
        }
    }

    ui->txtDir->clear();
}


void MainWindow::on_btnRem_clicked()
{
    local = ui->lstDir->currentItem()->text();

    QString nome = ui->txtDir->text().trimmed();

    QDir excldir(local + "/" + nome);

    if(!excldir.exists()) {
        QMessageBox::warning(this, "Pasta", "Diretório não encontrado!");
    }
    else {
        excldir.rmdir(local + "/" + nome);

        ui->lstDir->clear();

        ui->lstDir->addItem(ui->cbUnid->currentText());

        QDir conteudo(ui->cbUnid->currentText());

        foreach(QFileInfo qfi, conteudo.entryInfoList()){
            if(qfi.isDir()) {
                ui->lstDir->addItem("Pasta: " + qfi.absoluteFilePath());
            }
        }
    }
}

