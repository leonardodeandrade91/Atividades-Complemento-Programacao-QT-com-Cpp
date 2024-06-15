#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *telaSplash = new QSplashScreen();

    telaSplash->setPixmap(QPixmap(":/imgs/imagens/qt-banner.jpg"));

    telaSplash->show();

    MainWindow w;

    QTimer::singleShot(2000, telaSplash, SLOT(close()));

    QTimer::singleShot(2000, &w, SLOT(show()));

    // w.show();

    return a.exec();
}
