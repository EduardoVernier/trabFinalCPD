/********************************************************************************
** Form generated from reading UI file 'addquerido.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDQUERIDO_H
#define UI_ADDQUERIDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddQuerido
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *goButton;

    void setupUi(QDialog *AddQuerido)
    {
        if (AddQuerido->objectName().isEmpty())
            AddQuerido->setObjectName(QStringLiteral("AddQuerido"));
        AddQuerido->resize(320, 96);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/doctor whoives.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddQuerido->setWindowIcon(icon);
        lineEdit = new QLineEdit(AddQuerido);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 301, 23));
        label = new QLabel(AddQuerido);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 161, 21));
        goButton = new QPushButton(AddQuerido);
        goButton->setObjectName(QStringLiteral("goButton"));
        goButton->setGeometry(QRect(230, 60, 80, 23));

        retranslateUi(AddQuerido);

        QMetaObject::connectSlotsByName(AddQuerido);
    } // setupUi

    void retranslateUi(QDialog *AddQuerido)
    {
        AddQuerido->setWindowTitle(QApplication::translate("AddQuerido", "Adicionar Curriculo", 0));
        label->setText(QApplication::translate("AddQuerido", "Nome do Arquivo", 0));
        goButton->setText(QApplication::translate("AddQuerido", "Go", 0));
    } // retranslateUi

};

namespace Ui {
    class AddQuerido: public Ui_AddQuerido {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDQUERIDO_H
