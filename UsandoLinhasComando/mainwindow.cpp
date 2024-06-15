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

void MainWindow::on_btnClick_clicked()
{
    QProcess cons;

    cons.start("cmd.exe");
    cons.write("echo Exemplo de Uso de Linhas de Comandos no QT>>%userprofile%\\Desktop\\teste.txt\n\r");
    cons.write("exit\n\r");

    cons.waitForFinished();
    cons.close();
}

