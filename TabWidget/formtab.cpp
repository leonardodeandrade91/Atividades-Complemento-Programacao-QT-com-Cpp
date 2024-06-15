#include "formtab.h"
#include "ui_formtab.h"

FormTab::FormTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTab)
{
    ui->setupUi(this);
}

FormTab::~FormTab()
{
    delete ui;
}

void FormTab::on_btnCadr_clicked()
{
    QString nome = ui->txtNome->text().trimmed();
    QString mail = ui->txtMail->text().trimmed();
    QString senha = ui->txtSenha->text().trimmed();

    QMessageBox::information(this, "Info", "Nome: " + nome + "\nE-mail: " + mail + "\nSenha: " + senha);
}


void FormTab::on_btnLimp_clicked()
{
    ui->txtNome->clear();
    ui->txtMail->clear();
    ui->txtSenha->clear();

    ui->txtNome->setFocus();
}

