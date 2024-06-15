#ifndef EDITARCONTATO_H
#define EDITARCONTATO_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class EditarContato;
}

class EditarContato : public QDialog
{
    Q_OBJECT

public:
    explicit EditarContato(QWidget *parent = nullptr, int idCont = 0);
    ~EditarContato();

private slots:
    void on_btnGrav_clicked();

    void on_btnCanc_clicked();

private:
    Ui::EditarContato *ui;

    static int id;
};

#endif // EDITARCONTATO_H
