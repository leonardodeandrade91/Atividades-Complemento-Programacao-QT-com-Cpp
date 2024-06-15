#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnClick, SIGNAL(clicked()), this, SLOT(mudaTexto()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mudaTexto() {
    ui->lblText->setText("Texto Modificado!");
}
