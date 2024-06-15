#ifndef FORMTAB_H
#define FORMTAB_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class FormTab;
}

class FormTab : public QWidget
{
    Q_OBJECT

public:
    explicit FormTab(QWidget *parent = nullptr);
    ~FormTab();

private slots:
    void on_btnCadr_clicked();

    void on_btnLimp_clicked();

private:
    Ui::FormTab *ui;
};

#endif // FORMTAB_H
