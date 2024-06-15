#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formtab.h"

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
    void on_tbAbas_tabCloseRequested(int index);

    void on_btnAdd_clicked();

    void on_btnFech_clicked();

    void on_btnForm_clicked();

private:
    Ui::MainWindow *ui;

    static int i;
};
#endif // MAINWINDOW_H
