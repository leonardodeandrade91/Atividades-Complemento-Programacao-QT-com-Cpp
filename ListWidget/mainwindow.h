#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>

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
    void on_btnAdd_clicked();

    void on_btnAdAs_clicked();

    void on_btnMarc_clicked();

    void on_btnDesm_clicked();

    void on_btnDesmTod_clicked();

private:
    Ui::MainWindow *ui;

    QVector<int> marcados;
};
#endif // MAINWINDOW_H
