#include "formprincipal.h"
#include "ui_formprincipal.h"

FormPrincipal::FormPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FormPrincipal)
{
    ui->setupUi(this);
}

FormPrincipal::~FormPrincipal()
{
    delete ui;
}

void FormPrincipal::on_btnAdd_clicked()
{
    NovoContato *novoCont = new NovoContato(this);

    novoCont->show();
}

void FormPrincipal::on_btnPesq_clicked()
{
    PesquisaContatos *novoPesq = new PesquisaContatos(this);

    novoPesq->show();
}
