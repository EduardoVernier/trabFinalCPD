/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *searchButton;
    QPushButton *alfaButton;
    QLabel *Logo;
    QLineEdit *searchBar;
    QPushButton *perButton;
    QPushButton *eventsButton;
    QPushButton *totalButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(940, 550);
        MainWindow->setMinimumSize(QSize(940, 550));
        MainWindow->setMaximumSize(QSize(940, 550));
        MainWindow->setStyleSheet(QStringLiteral("background: url(:/new/prefix1/res/bg.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 170, 921, 371));
        tableWidget->setStyleSheet(QStringLiteral("background: #f0f0f0;"));
        tableWidget->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(false);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(180);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(630, 70, 91, 41));
        searchButton->setStyleSheet(QLatin1String("QPushButton#searchButton {\n"
"	outline: none;\n"
"    background: #555555;\n"
"	color: #ffffff;\n"
"	border: 2px solid #dfdfdf;\n"
"	border-radius: 3px;\n"
" }\n"
" QPushButton#searchButton:pressed {\n"
"	outline: none;\n"
"    background: #404040;\n"
" }"));
        alfaButton = new QPushButton(centralWidget);
        alfaButton->setObjectName(QStringLiteral("alfaButton"));
        alfaButton->setEnabled(true);
        alfaButton->setGeometry(QRect(170, 120, 41, 41));
        alfaButton->setStyleSheet(QLatin1String("QPushButton#alfaButton{\n"
"	outline: none;\n"
"	background: #f3f3f3;\n"
"	background-image: url(:/new/prefix1/res/alfabeticadecresc.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"	border: 4px solid #c0c0c0;\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton#alfaButton:pressed{\n"
"	outline: none;\n"
"	background: #f0f0f0;\n"
"	background-image: url(:/new/prefix1/res/alfabeticadecresc.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"	border: 4px solid #a8c54a;\n"
"}"));
        Logo = new QLabel(centralWidget);
        Logo->setObjectName(QStringLiteral("Logo"));
        Logo->setGeometry(QRect(350, 10, 201, 51));
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(26);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        Logo->setFont(font);
        Logo->setStyleSheet(QStringLiteral(""));
        searchBar = new QLineEdit(centralWidget);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(230, 70, 401, 41));
        searchBar->setStyleSheet(QLatin1String("background: white;\n"
"outline: none;\n"
"border: 1px solid #e0e0e0;\n"
"border-radius:3px;"));
        perButton = new QPushButton(centralWidget);
        perButton->setObjectName(QStringLiteral("perButton"));
        perButton->setEnabled(true);
        perButton->setGeometry(QRect(430, 120, 41, 41));
        perButton->setStyleSheet(QLatin1String("QPushButton#perButton{\n"
"	outline: none;\n"
"	background: #f3f3f3;\n"
"	background-position: center;\n"
"	border: 4px solid #c0c0c0;\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton#perButton:pressed{\n"
"	outline: none;\n"
"	background: #f0f0f0;\n"
"	background-position: center;\n"
"	border: 4px solid #cc0000;\n"
"}"));
        eventsButton = new QPushButton(centralWidget);
        eventsButton->setObjectName(QStringLiteral("eventsButton"));
        eventsButton->setEnabled(true);
        eventsButton->setGeometry(QRect(600, 120, 41, 41));
        eventsButton->setStyleSheet(QLatin1String("QPushButton#eventsButton{\n"
"	outline: none;\n"
"	background: #f3f3f3;\n"
"	background-position: center;\n"
"	border: 4px solid #c0c0c0;\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton#eventsButton:pressed{\n"
"	outline: none;\n"
"	background: #f0f0f0;\n"
"	background-position: center;\n"
"	border: 4px solid #dddd00;\n"
"}"));
        totalButton = new QPushButton(centralWidget);
        totalButton->setObjectName(QStringLiteral("totalButton"));
        totalButton->setEnabled(true);
        totalButton->setGeometry(QRect(790, 120, 41, 41));
        totalButton->setStyleSheet(QLatin1String("QPushButton#totalButton{\n"
"	outline: none;\n"
"	background: #f3f3f3;\n"
"	background-position: center;\n"
"	border: 4px solid #c0c0c0;\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton#totalButton:pressed{\n"
"	outline: none;\n"
"	background: #f0f0f0;\n"
"	background-position: center;\n"
"	border: 4px solid #00dddd;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Noodles", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Nome", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Artigos em Peri\303\263dicos", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Artigos em Eventos", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Numero de Artigos ao todo", 0));
        searchButton->setText(QApplication::translate("MainWindow", "NI", 0));
        alfaButton->setText(QString());
        Logo->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt; color:#444444;\">N</span><span style=\" font-size:36pt; color:#a8c54a;\">oo</span><span style=\" font-size:36pt; color:#0092b2;\">dles</span></p></body></html>", 0));
        perButton->setText(QApplication::translate("MainWindow", "AP", 0));
        eventsButton->setText(QApplication::translate("MainWindow", "AE", 0));
        totalButton->setText(QApplication::translate("MainWindow", "Total", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
