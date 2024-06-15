#include "novoform.h"
#include "ui_novoform.h"

NovoForm::NovoForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NovoForm)
{
    ui->setupUi(this);
}

NovoForm::~NovoForm()
{
    delete ui;
}
