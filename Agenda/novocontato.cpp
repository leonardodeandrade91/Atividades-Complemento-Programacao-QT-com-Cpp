#include "novocontato.h"
#include "ui_novocontato.h"

NovoContato::NovoContato(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NovoContato)
{
    ui->setupUi(this);
}

NovoContato::~NovoContato()
{
    delete ui;
}

void NovoContato::on_btnGrav_clicked()
{
    QString nome = ui->txtNome->text().trimmed();
    QString tel = ui->txtTel->text().trimmed();
    QString mail = ui->txtMail->text().trimmed();

    QSqlQuery query;

    QString consulta = "insert into contato (nome, telefone, email) values (?, ?, ?)";

    query.prepare(consulta);

    query.bindValue(0, nome);
    query.bindValue(1, tel);
    query.bindValue(2, mail);

    if(query.exec()) {
        QMessageBox::information(this, "Info", "Registro Gravado com Sucesso!");

        ui->txtNome->clear();
        ui->txtTel->clear();
        ui->txtMail->clear();

        ui->txtNome->setFocus();
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao Inserir Registro!");
    }
}


void NovoContato::on_btnCanc_clicked()
{
    this->close();
}

