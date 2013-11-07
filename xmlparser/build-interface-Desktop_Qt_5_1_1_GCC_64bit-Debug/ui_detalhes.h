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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Detalhes
{
public:
    QWidget *centralwidget;
    QTextEdit *nameText;

    void setupUi(QMainWindow *Detalhes)
    {
        if (Detalhes->objectName().isEmpty())
            Detalhes->setObjectName(QStringLiteral("Detalhes"));
        Detalhes->resize(800, 600);
        Detalhes->setStyleSheet(QStringLiteral("background: url(:/new/prefix1/resources/diamond_upholstery/bg.png);"));
        centralwidget = new QWidget(Detalhes);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        nameText = new QTextEdit(centralwidget);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setGeometry(QRect(20, 20, 511, 41));
        nameText->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        nameText->setStyleSheet(QLatin1String("QTextEdit#nameText{\n"
"	background: rgba(0,0,0,0);\n"
"	border: 0px solid transparent;\n"
"}"));
        nameText->setInputMethodHints(Qt::ImhNone);
        nameText->setReadOnly(true);
        nameText->setTextInteractionFlags(Qt::TextSelectableByMouse);
        Detalhes->setCentralWidget(centralwidget);

        retranslateUi(Detalhes);

        QMetaObject::connectSlotsByName(Detalhes);
    } // setupUi

    void retranslateUi(QMainWindow *Detalhes)
    {
        Detalhes->setWindowTitle(QApplication::translate("Detalhes", "Professor", 0));
        nameText->setHtml(QApplication::translate("Detalhes", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">NOME DO QUERIDAO EM CAPS LOCO</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Detalhes: public Ui_Detalhes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETALHES_H
