#ifndef PESQUISACONTATOS_H
#define PESQUISACONTATOS_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include "editarcontato.h"

namespace Ui {
class PesquisaContatos;
}

class PesquisaContatos : public QMainWindow
{
    Q_OBJECT

public:
    explicit PesquisaContatos(QWidget *parent = nullptr);
    ~PesquisaContatos();

private slots:
    void on_btnExcl_clicked();

    void on_btnEdit_clicked();

    void on_btnPesq_clicked();

private:
    Ui::PesquisaContatos *ui;
};

#endif // PESQUISACONTATOS_H
