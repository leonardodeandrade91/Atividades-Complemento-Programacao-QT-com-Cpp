#include "pesquisacontatos.h"
#include "ui_pesquisacontatos.h"

PesquisaContatos::PesquisaContatos(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PesquisaContatos)
{
    ui->setupUi(this);

    QSqlQuery query;
    QString sql = "select * from contato";

    query.prepare(sql);

    if(query.exec()) {
        int linha = 0;

        ui->tbList->setColumnCount(4);

        while(query.next()) {
            ui->tbList->insertRow(linha);
            ui->tbList->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tbList->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tbList->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tbList->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));

            ui->tbList->setRowHeight(linha, 20);

            linha++;
        }

        ui->tbList->setColumnWidth(0, 30);
        ui->tbList->setColumnWidth(1, 150);
        ui->tbList->setColumnWidth(3, 250);

        QStringList cabecalhos = {"ID", "Nome", "Telefone", "E-mail"};

        ui->tbList->setHorizontalHeaderLabels(cabecalhos);
        ui->tbList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tbList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tbList->verticalHeader()->setVisible(false);
        ui->tbList->setStyleSheet("QTableView {selection-background-color: blue}");
        ui->tbList->setSortingEnabled(true);
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao Pesquisar Tabela de Contatos!");
    }
}

PesquisaContatos::~PesquisaContatos()
{
    delete ui;
}

void PesquisaContatos::on_btnExcl_clicked()
{
    int linha = ui->tbList->currentRow();
    int id = ui->tbList->item(linha, 0)->text().toInt();

    QSqlQuery query;
    QString sql = "delete from contato where id = ?";

    query.prepare(sql);

    query.bindValue(0, id);

    if(query.exec()) {
        ui->tbList->removeRow(linha);

        QMessageBox::information(this, "Info", "Contato Excluído!");
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao Excluir o Registro!");
    }
}


void PesquisaContatos::on_btnEdit_clicked()
{
    int linha = ui->tbList->currentRow();
    int id = ui->tbList->item(linha, 0)->text().toInt();

    EditarContato editCont(this, id);

    editCont.exec();

    QSqlQuery query;

    QString sql = "select * from contato where id = ?";

    query.prepare(sql);

    query.bindValue(0, id);

    if(query.exec()) {
        query.first();

        ui->tbList->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tbList->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tbList->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
    }
}

void PesquisaContatos::on_btnPesq_clicked()
{
    QString pesq = ui->txtPesq->text().trimmed();

    QSqlQuery query;
    QString sql = "select * from contato where nome like ?";

    query.prepare(sql);

    query.bindValue(0, '%' + pesq + '%');

    if(query.exec()) {
        int linha = 0;

        ui->tbList->setRowCount(0);

        while(query.next()) {
            ui->tbList->insertRow(linha);
            ui->tbList->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tbList->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tbList->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tbList->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));

            ui->tbList->setRowHeight(linha, 20);

            linha++;
        }
    }
    else {
        QMessageBox::critical(this, "Erro", "Erro ao Pesquisar Tabela de Contatos!");
    }
}
