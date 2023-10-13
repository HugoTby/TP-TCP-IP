/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitiationQtClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *IPLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *pushButton_2;
    QLabel *connectionStatusLabel;
    QLabel *MessageEditLine;
    QPlainTextEdit *plainTextEdit;
    QLabel *connectionStatusLabel1;
    QPushButton *far;
    QPushButton *hr;
    QPushButton *cel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InitiationQtClass)
    {
        if (InitiationQtClass->objectName().isEmpty())
            InitiationQtClass->setObjectName(QString::fromUtf8("InitiationQtClass"));
        InitiationQtClass->resize(385, 340);
        centralWidget = new QWidget(InitiationQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 230, 131, 81));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 41, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 71, 20));
        IPLineEdit = new QLineEdit(centralWidget);
        IPLineEdit->setObjectName(QString::fromUtf8("IPLineEdit"));
        IPLineEdit->setGeometry(QRect(50, 10, 113, 20));
        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(50, 30, 113, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 50, 75, 23));
        connectionStatusLabel = new QLabel(centralWidget);
        connectionStatusLabel->setObjectName(QString::fromUtf8("connectionStatusLabel"));
        connectionStatusLabel->setGeometry(QRect(170, 0, 451, 41));
        MessageEditLine = new QLabel(centralWidget);
        MessageEditLine->setObjectName(QString::fromUtf8("MessageEditLine"));
        MessageEditLine->setGeometry(QRect(610, 160, 391, 171));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(50, 90, 111, 141));
        connectionStatusLabel1 = new QLabel(centralWidget);
        connectionStatusLabel1->setObjectName(QString::fromUtf8("connectionStatusLabel1"));
        connectionStatusLabel1->setGeometry(QRect(20, 230, 301, 41));
        far = new QPushButton(centralWidget);
        far->setObjectName(QString::fromUtf8("far"));
        far->setGeometry(QRect(170, 140, 91, 41));
        hr = new QPushButton(centralWidget);
        hr->setObjectName(QString::fromUtf8("hr"));
        hr->setGeometry(QRect(170, 190, 91, 41));
        cel = new QPushButton(centralWidget);
        cel->setObjectName(QString::fromUtf8("cel"));
        cel->setGeometry(QRect(170, 90, 91, 41));
        InitiationQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InitiationQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 385, 21));
        InitiationQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InitiationQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        InitiationQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InitiationQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InitiationQtClass->setStatusBar(statusBar);

        retranslateUi(InitiationQtClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), InitiationQtClass, SLOT(onConnectButtonClicked()));
        QObject::connect(cel, SIGNAL(clicked()), InitiationQtClass, SLOT(EnvoiCel()));
        QObject::connect(far, SIGNAL(clicked()), InitiationQtClass, SLOT(EnvoiFar()));
        QObject::connect(hr, SIGNAL(clicked()), InitiationQtClass, SLOT(EnvoiHyg()));

        QMetaObject::connectSlotsByName(InitiationQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *InitiationQtClass)
    {
        InitiationQtClass->setWindowTitle(QCoreApplication::translate("InitiationQtClass", "InitiationQt", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("InitiationQtClass", "IP", nullptr));
        label_4->setText(QCoreApplication::translate("InitiationQtClass", "PORT", nullptr));
        pushButton_2->setText(QCoreApplication::translate("InitiationQtClass", "Connexion", nullptr));
        connectionStatusLabel->setText(QCoreApplication::translate("InitiationQtClass", "status de connexion : deconnecte", nullptr));
        MessageEditLine->setText(QString());
        connectionStatusLabel1->setText(QCoreApplication::translate("InitiationQtClass", "Message recu =", nullptr));
        far->setText(QCoreApplication::translate("InitiationQtClass", "\302\260F", nullptr));
        hr->setText(QCoreApplication::translate("InitiationQtClass", "H", nullptr));
        cel->setText(QCoreApplication::translate("InitiationQtClass", "\302\260C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitiationQtClass: public Ui_InitiationQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
