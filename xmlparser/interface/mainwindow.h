#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_searchButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_descAlfa_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
