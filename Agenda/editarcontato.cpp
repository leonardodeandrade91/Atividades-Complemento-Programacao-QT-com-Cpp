#include "editarcontato.h"
#include "ui_editarcontato.h"

int EditarContato::id = 0;

EditarContato::EditarContato(QWidget *parent, int idCont)
    : QDialog(parent)
    , ui(new Ui::EditarContato)
{
    ui->setupUi(this);

    id = idCont;

    QSqlQuery query;
    QString sql = "select * from contato where id = ?";

    query.prepare(sql);

    query.bindValue(0, id);

    if(query.exec()) {
        query.first();

        ui->lblNome->setText(query.value(0).toString());
        ui->txtNome->setText(query.value(1).toString());
        ui->txtTel->setText(query.value(2).toString());
        ui->txtMail->setText(query.value(3).toString());
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao Selecionar Contato!");
    }
}

EditarContato::~EditarContato()
{
    delete ui;
}

void EditarContato::on_btnGrav_clicked()
{
    QString nome = ui->txtNome->text().trimmed();
    QString tel = ui->txtTel->text().trimmed();
    QString mail = ui->txtMail->text().trimmed();

    QSqlQuery query;
    QString sql = "update contato set nome = ?, telefone = ?, email = ? where id = ?";

    query.prepare(sql);

    query.bindValue(0, nome);
    query.bindValue(1, tel);
    query.bindValue(2, mail);
    query.bindValue(3, id);

    if(query.exec()) {
        QMessageBox::information(this, "Info", "Atualizado com Sucesso!");

        this->close();
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao Atualizar Contato!");
    }
}


void EditarContato::on_btnCanc_clicked()
{
    this->close();
}

