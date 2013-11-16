/********************************************************************************
** Form generated from reading UI file 'details.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILS_H
#define UI_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Details
{
public:
    QLabel *label;

    void setupUi(QDialog *Details)
    {
        if (Details->objectName().isEmpty())
            Details->setObjectName(QStringLiteral("Details"));
        Details->setEnabled(true);
        Details->resize(480, 650);
        Details->setMinimumSize(QSize(480, 650));
        Details->setMaximumSize(QSize(520, 650));
        Details->setStyleSheet(QStringLiteral("background: url(:/new/prefix1/res/bg.png);"));
        label = new QLabel(Details);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 461, 51));
        label->setStyleSheet(QStringLiteral("background: transparent;"));

        retranslateUi(Details);

        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QDialog *Details)
    {
        Details->setWindowTitle(QApplication::translate("Details", "New Professor", 0));
        label->setText(QApplication::translate("Details", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">NOME DO QUERIDAO EM CAPS LOCO</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Details: public Ui_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILS_H
