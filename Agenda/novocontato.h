#ifndef NOVOCONTATO_H
#define NOVOCONTATO_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class NovoContato;
}

class NovoContato : public QMainWindow
{
    Q_OBJECT

public:
    explicit NovoContato(QWidget *parent = nullptr);
    ~NovoContato();

private slots:
    void on_btnGrav_clicked();

    void on_btnCanc_clicked();

private:
    Ui::NovoContato *ui;
};

#endif // NOVOCONTATO_H
