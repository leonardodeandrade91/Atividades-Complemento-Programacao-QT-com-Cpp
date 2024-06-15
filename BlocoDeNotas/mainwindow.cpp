#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->txtEd);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_itNov_triggered()
{
    localArquivo = "";

    ui->txtEd->clear();
    ui->txtEd->setFocus();
}

void MainWindow::on_itAbr_triggered()
{
    QString filtro = "Todos os Arquivos (*.*) ;; Arquivos de Texto (*.txt)";
    QString nomeArquivo = QFileDialog::getOpenFileName(this, "Abrir", QDir::homePath(), filtro);
    QFile arquivo(nomeArquivo);

    localArquivo = nomeArquivo;

    if(!arquivo.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Aviso", "O Arquivo não Pôde ser Aberto!");
        return;
    }

    QTextStream entrada(&arquivo);
    QString texto = entrada.readAll();

    ui->txtEd->setText(texto);

    arquivo.close();
}


void MainWindow::on_itSalv_triggered()
{
    QFile arquivo(localArquivo);

    if(!arquivo.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Aviso", "O Arquivo não Pôde ser Salvo!");
        return;
    }

    QTextStream saida(&arquivo);
    QString texto = ui->txtEd->toPlainText();

    saida << texto;

    arquivo.flush();

    arquivo.close();
}


void MainWindow::on_itSalCo_triggered()
{
    QString filtro = "Todos os Arquivos (*.*) ;; Arquivos de Texto (*.txt)";
    QString nomeArquivo = QFileDialog::getSaveFileName(this, "Salvar", QDir::homePath(), filtro);
    QFile arquivo(nomeArquivo);

    localArquivo = nomeArquivo;

    if(!arquivo.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Aviso", "O Arquivo não Pôde ser Salvo!");
        return;
    }

    QTextStream saida(&arquivo);
    QString texto = ui->txtEd->toPlainText();

    saida << texto;

    arquivo.flush();

    arquivo.close();
}


void MainWindow::on_itFech_triggered()
{
    close();
}


void MainWindow::on_itDesf_triggered()
{
    ui->txtEd->undo();
}


void MainWindow::on_itRef_triggered()
{
    ui->txtEd->redo();
}


void MainWindow::on_itRec_triggered()
{
    ui->txtEd->cut();
}


void MainWindow::on_itCop_triggered()
{
    ui->txtEd->copy();
}


void MainWindow::on_itCol_triggered()
{
    ui->txtEd->paste();
}


void MainWindow::on_itSob_triggered()
{

}


void MainWindow::on_itFon_triggered()
{
    bool fonteOk;
    QFont fonte = QFontDialog::getFont(&fonteOk, this);

    if(fonteOk) {
        ui->txtEd->setFont(fonte);
    }
    else {
        return;
    }
}


void MainWindow::on_itCorFon_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::black, this, "Escolha uma Cor");

    if(cor.isValid()) {
        ui->txtEd->setTextColor(cor);
    }
    else {
        return;
    }
}


void MainWindow::on_itCorFun_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::white, this, "Escolha uma Cor");

    if(cor.isValid()) {
        ui->txtEd->setTextBackgroundColor(cor);
    }
    else {
        return;
    }
}


void MainWindow::on_itImpr_triggered()
{
    QPrinter imp;

    imp.setPrinterName("Impressora");

    QPrintDialog cxImp(&imp, this);

    if(cxImp.exec() == QDialog::Rejected) {
        return;
    }

    ui->txtEd->print(&imp);
}

