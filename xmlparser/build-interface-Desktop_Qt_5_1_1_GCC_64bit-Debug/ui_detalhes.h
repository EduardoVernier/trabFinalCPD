/********************************************************************************
** Form generated from reading UI file 'detalhes.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETALHES_H
#define UI_DETALHES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Detalhes
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *Detalhes)
    {
        if (Detalhes->objectName().isEmpty())
            Detalhes->setObjectName(QStringLiteral("Detalhes"));
        Detalhes->resize(800, 600);
        centralwidget = new QWidget(Detalhes);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Detalhes->setCentralWidget(centralwidget);

        retranslateUi(Detalhes);

        QMetaObject::connectSlotsByName(Detalhes);
    } // setupUi

    void retranslateUi(QMainWindow *Detalhes)
    {
        Detalhes->setWindowTitle(QApplication::translate("Detalhes", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class Detalhes: public Ui_Detalhes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETALHES_H
