#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
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
    void on_cbUnid_currentTextChanged(const QString &arg1);

    void on_btnAdd_clicked();

    void on_btnRem_clicked();

private:
    Ui::MainWindow *ui;

    static QString local;
};
#endif // MAINWINDOW_H
