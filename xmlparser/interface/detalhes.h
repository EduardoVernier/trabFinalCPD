#ifndef DETALHES_H
#define DETALHES_H

#include <QMainWindow>

namespace Ui {
class Detalhes;
}

class Detalhes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Detalhes(QWidget *parent = 0);
    ~Detalhes();

private:
    Ui::Detalhes *ui;
};

#endif // DETALHES_H
