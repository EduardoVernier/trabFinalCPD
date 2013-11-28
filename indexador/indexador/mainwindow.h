#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "professor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    chavesProfessor *prof = new chavesProfessor;
    vector <chavesProfessor> vecProfessor;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    //void on_ascAlfa_clicked(bool checked);

    void on_alfaButton_clicked();

    void on_perButton_clicked();

    void on_eventsButton_clicked();

    void on_totalButton_clicked();

    void on_searchBar_textChanged(const QString &arg1);

    void on_addCurriculoButton_triggered();


    bool on_go(QString a);

private:
    Ui::MainWindow *ui;
    void escreveNaTable();
    void escreveNaTableInverso();

signals:
    bool addQ();

};

#endif // MAINWINDOW_H
