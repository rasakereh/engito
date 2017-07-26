/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *lytPlayerCount;
    QLabel *lblPlayerCount;
    QSpinBox *spinPlayerCount;
    QWidget *formLayoutWidget;
    QFormLayout *lytPlayerNames;
    QLabel *lblPlayer1;
    QLineEdit *txtPlayer1;
    QLabel *lblPlayer2;
    QLineEdit *txtPlayer2;
    QLabel *lblPlayer3;
    QLineEdit *txtPlayer3;
    QLineEdit *txtPlayer4;
    QLabel *lblPlayer4;
    QPushButton *btnGo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 20, 251, 41));
        lytPlayerCount = new QHBoxLayout(horizontalLayoutWidget);
        lytPlayerCount->setSpacing(6);
        lytPlayerCount->setContentsMargins(11, 11, 11, 11);
        lytPlayerCount->setObjectName(QStringLiteral("lytPlayerCount"));
        lytPlayerCount->setContentsMargins(0, 0, 0, 0);
        lblPlayerCount = new QLabel(horizontalLayoutWidget);
        lblPlayerCount->setObjectName(QStringLiteral("lblPlayerCount"));

        lytPlayerCount->addWidget(lblPlayerCount);

        spinPlayerCount = new QSpinBox(horizontalLayoutWidget);
        spinPlayerCount->setObjectName(QStringLiteral("spinPlayerCount"));
        spinPlayerCount->setMinimum(2);
        spinPlayerCount->setMaximum(4);
        spinPlayerCount->setValue(2);

        lytPlayerCount->addWidget(spinPlayerCount);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 70, 351, 131));
        lytPlayerNames = new QFormLayout(formLayoutWidget);
        lytPlayerNames->setSpacing(6);
        lytPlayerNames->setContentsMargins(11, 11, 11, 11);
        lytPlayerNames->setObjectName(QStringLiteral("lytPlayerNames"));
        lytPlayerNames->setHorizontalSpacing(20);
        lytPlayerNames->setContentsMargins(0, 0, 0, 0);
        lblPlayer1 = new QLabel(formLayoutWidget);
        lblPlayer1->setObjectName(QStringLiteral("lblPlayer1"));

        lytPlayerNames->setWidget(0, QFormLayout::LabelRole, lblPlayer1);

        txtPlayer1 = new QLineEdit(formLayoutWidget);
        txtPlayer1->setObjectName(QStringLiteral("txtPlayer1"));

        lytPlayerNames->setWidget(0, QFormLayout::FieldRole, txtPlayer1);

        lblPlayer2 = new QLabel(formLayoutWidget);
        lblPlayer2->setObjectName(QStringLiteral("lblPlayer2"));

        lytPlayerNames->setWidget(1, QFormLayout::LabelRole, lblPlayer2);

        txtPlayer2 = new QLineEdit(formLayoutWidget);
        txtPlayer2->setObjectName(QStringLiteral("txtPlayer2"));

        lytPlayerNames->setWidget(1, QFormLayout::FieldRole, txtPlayer2);

        lblPlayer3 = new QLabel(formLayoutWidget);
        lblPlayer3->setObjectName(QStringLiteral("lblPlayer3"));

        lytPlayerNames->setWidget(2, QFormLayout::LabelRole, lblPlayer3);

        txtPlayer3 = new QLineEdit(formLayoutWidget);
        txtPlayer3->setObjectName(QStringLiteral("txtPlayer3"));

        lytPlayerNames->setWidget(2, QFormLayout::FieldRole, txtPlayer3);

        txtPlayer4 = new QLineEdit(formLayoutWidget);
        txtPlayer4->setObjectName(QStringLiteral("txtPlayer4"));

        lytPlayerNames->setWidget(3, QFormLayout::FieldRole, txtPlayer4);

        lblPlayer4 = new QLabel(formLayoutWidget);
        lblPlayer4->setObjectName(QStringLiteral("lblPlayer4"));

        lytPlayerNames->setWidget(3, QFormLayout::LabelRole, lblPlayer4);

        btnGo = new QPushButton(centralWidget);
        btnGo->setObjectName(QStringLiteral("btnGo"));
        btnGo->setGeometry(QRect(130, 210, 121, 23));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lblPlayerCount->setText(QApplication::translate("MainWindow", "Player Count:", Q_NULLPTR));
        lblPlayer1->setText(QApplication::translate("MainWindow", "Player(1) Nick-Name:                 ", Q_NULLPTR));
        lblPlayer2->setText(QApplication::translate("MainWindow", "Player(2) Nick-Name:", Q_NULLPTR));
        lblPlayer3->setText(QApplication::translate("MainWindow", "Player(3) Nick-Name:", Q_NULLPTR));
        lblPlayer4->setText(QApplication::translate("MainWindow", "Player(4) Nick-Name:", Q_NULLPTR));
        btnGo->setText(QApplication::translate("MainWindow", "Let's Go!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
