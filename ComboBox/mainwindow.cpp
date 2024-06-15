#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString cursos[4] = {"C++", "PHP", "C#", "Javascript"};
    QString icones[4] = {":/icons/icones/cpp.ico", ":/icons/icones/php.ico", ":/icons/icones/csharp.ico", ":/icons/icones/javascript.ico"};

    for(int i = 0; i < 4; i++) {
        ui->cxItens->addItem(QIcon(icones[i]), cursos[i]);
    }

    ui->cxItens->insertItem(3, QIcon(":/icons/icones/java.ico"), "Java");
    ui->cxItens->insertItem(4, QIcon(":/icons/icones/python.ico"), "Python");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClick_clicked()
{
    QMessageBox::information(this, "Cursos", "Linguagem: " + ui->cxItens->currentText());
}

