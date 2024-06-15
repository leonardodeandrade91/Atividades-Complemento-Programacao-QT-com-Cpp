#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::local = "C:\\Projetos\\QT com C++\\CriandoELendoArquivos\\files\\";
QString MainWindow::nome = "arquivo.txt";

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

void MainWindow::on_btnGrav_clicked()
{
    QFile arquivo(local + nome);

    if(!arquivo.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "ERRO", "Erro ao Abrir o Arquivo!");
    }

    QTextStream saida(&arquivo);
    QString texto = ui->plArq->toPlainText();

    saida << texto;

    arquivo.flush();
    arquivo.close();

    ui->plArq->clear();
}


void MainWindow::on_btnLer_clicked()
{
    QFile arquivo(local + nome);

    if(!arquivo.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "ERRO", "Erro ao Abrir o Arquivo!");
    }

    QTextStream entrada(&arquivo);
    QString texto = entrada.readAll();

    ui->plArq->setPlainText(texto);

    arquivo.close();
}


void MainWindow::on_btnAbr_clicked()
{
    QString filtro = "Todos os Arquivos (*.*) ;; Arquivos de Texto (*.txt)";
    QString abrir = QFileDialog::getOpenFileName(this, "Abrir Arquivos", QDir::homePath(), filtro);

    QFile arquivo(abrir);

    if(!arquivo.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "ERRO", "Erro ao Abrir o Arquivo!");
    }

    QTextStream entrada(&arquivo);
    QString texto = entrada.readAll();

    ui->plArq->setPlainText(texto);

    arquivo.close();
}

