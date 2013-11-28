#ifndef ADDQUERIDO_H
#define ADDQUERIDO_H

#include <QDialog>

namespace Ui {
class AddQuerido;
}

class AddQuerido : public QDialog
{
    Q_OBJECT

public:
    explicit AddQuerido(QWidget *parent = 0);
    ~AddQuerido();

private:
    Ui::AddQuerido *ui;

signals:
    bool go(QString);
private slots:
    void on_goButton_clicked();
};

#endif // ADDQUERIDO_H
