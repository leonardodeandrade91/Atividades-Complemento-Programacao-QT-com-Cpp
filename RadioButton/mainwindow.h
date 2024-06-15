#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>
#include <QPixmap>
#include "novoform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnVerif_clicked();

    void on_btnImg_clicked();

    void on_itNov_triggered();

    void on_itEdi_triggered();

    void on_itSalv_triggered();

    void on_itSair_triggered();

    void on_itPesq_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
