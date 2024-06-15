#include "janelalogin.h"
#include "ui_janelalogin.h"

JanelaLogin::JanelaLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaLogin)
{
    ui->setupUi(this);

    bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

    QString caminho = qApp->applicationDirPath();

    bancoDeDados.setDatabaseName(caminho + "/bancos/agenda.db3");

    if(!bancoDeDados.open()) {
        QPixmap led(":/imgs/imagens/led-red.png");

        ui->lblImg->setPixmap(led);
    }
    else {
        QPixmap led(":/imgs/imagens/led-green.png");

        ui->lblImg->setPixmap(led);
    }
}

JanelaLogin::~JanelaLogin()
{
    delete ui;
}

void JanelaLogin::on_btnEntr_clicked()
{
    QString username = ui->txtLogin->text().trimmed();
    QString senha = ui->txtSenha->text().trimmed();

    QString encripta = QString(QCryptographicHash::hash(senha.toStdString().c_str(), QCryptographicHash::Sha1).toHex());

    if(!bancoDeDados.isOpen()) {
        qDebug() << "Banco de Dados não está Aberto!";

        return;
    }

    QSqlQuery query;

    QString consulta = "select * from admin where username = ? and senha = ?";

    query.prepare(consulta);

    query.bindValue(0, username);
    query.bindValue(1, encripta);

    if(query.exec()) {
        int cont = 0;

        while(query.next()) {
            cont++;
        }

        if(cont == 1) {
            this->close();

            FormPrincipal *princ = new FormPrincipal(this);

            princ->show();
        }
        else {
            QMessageBox::critical(this, "Erro", "Login não Efetuado!");

            ui->txtLogin->clear();
            ui->txtSenha->clear();
            ui->txtLogin->setFocus();
        }
    }
}


void JanelaLogin::on_btnLimp_clicked()
{
    ui->txtLogin->clear();
    ui->txtSenha->clear();
    ui->txtLogin->setFocus();
}

