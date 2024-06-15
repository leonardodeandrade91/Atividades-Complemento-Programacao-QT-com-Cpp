#ifndef FORMPRINCIPAL_H
#define FORMPRINCIPAL_H

#include <QMainWindow>
#include "novocontato.h"
#include "pesquisacontatos.h"

namespace Ui {
class FormPrincipal;
}

class FormPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormPrincipal(QWidget *parent = nullptr);
    ~FormPrincipal();

private slots:
    void on_btnAdd_clicked();

    void on_btnPesq_clicked();

private:
    Ui::FormPrincipal *ui;
};

#endif // FORMPRINCIPAL_H
