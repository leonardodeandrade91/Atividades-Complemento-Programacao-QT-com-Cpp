#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_btnVer1_clicked();

    void on_btnVer2_clicked();

    void on_btnVer3_clicked();

    void on_cxVerif1_stateChanged(int arg1);

    void on_cxVerif2_stateChanged(int arg1);

    void on_cxVerif3_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    static QString msg;
    static QString m1, m2, m3;
};
#endif // MAINWINDOW_H
