#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>

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
    void on_itNov_triggered();

    void on_itAbr_triggered();

    void on_itSalv_triggered();

    void on_itSalCo_triggered();

    void on_itFech_triggered();

    void on_itDesf_triggered();

    void on_itRef_triggered();

    void on_itRec_triggered();

    void on_itCop_triggered();

    void on_itCol_triggered();

    void on_itSob_triggered();

    void on_itCorFon_triggered();

    void on_itCorFun_triggered();

    void on_itFon_triggered();

    void on_itImpr_triggered();

private:
    Ui::MainWindow *ui;

    QString localArquivo;
};
#endif // MAINWINDOW_H
