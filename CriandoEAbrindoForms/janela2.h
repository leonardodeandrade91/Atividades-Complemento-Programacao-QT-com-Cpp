#ifndef JANELA2_H
#define JANELA2_H

#include <QMainWindow>

namespace Ui {
class Janela2;
}

class Janela2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Janela2(QWidget *parent = nullptr);
    ~Janela2();

private:
    Ui::Janela2 *ui;
};

#endif // JANELA2_H
