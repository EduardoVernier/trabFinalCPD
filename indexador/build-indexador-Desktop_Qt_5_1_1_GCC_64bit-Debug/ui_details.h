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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Details
{
public:
    QLabel *label;
    QTextEdit *infoBox;

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
        infoBox = new QTextEdit(Details);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(10, 70, 450, 560));
        infoBox->setMinimumSize(QSize(450, 560));
        infoBox->setMaximumSize(QSize(0, 0));
        infoBox->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        infoBox->setStyleSheet(QLatin1String("background: transparent;\n"
"outline: none;\n"
"border: 0px solid black;"));
        infoBox->setInputMethodHints(Qt::ImhLatinOnly|Qt::ImhMultiLine);
        infoBox->setReadOnly(true);
        infoBox->setTextInteractionFlags(Qt::NoTextInteraction);

        retranslateUi(Details);

        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QDialog *Details)
    {
        Details->setWindowTitle(QApplication::translate("Details", "New Professor", 0));
        label->setText(QApplication::translate("Details", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">NOME DO QUERIDAO EM CAPS LOCO</span></p></body></html>", 0));
        infoBox->setHtml(QApplication::translate("Details", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	oi</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Details: public Ui_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILS_H
