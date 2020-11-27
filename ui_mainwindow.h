/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 16 01:59:54 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QList>
#include <QTime>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include "qmenubar.h"
#include <QToolBar>
#include <QStatusBar>
#include <QApplication>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Extension;
    QAction *actionCreate_Extension;
    QAction *actionPreferences;
    QAction *actionGo_to_PHP_Function;
    QAction *actionCreate_Test;
    QAction *actionCompile_Extension;
    QAction *actionExtension_Properties;
    QAction *actionSave_Current_Document;
    QAction *actionSave_All_Documents;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_cFile;
    QPlainTextEdit *textEdit_cFile;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_hFile;
    QPlainTextEdit *textEdit_hFile;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_config_m4;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_config_w32;
    QPushButton *pushButton_compileExtension;
    QComboBox *comboBox_compileType;
    QLabel *label_path_phpSDKBase;
    QLabel *label_path_compileBase;
    QLabel *label_path_extBase;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label;
    QListWidget *listWidget_extensionFiles;
    QListWidget *listWidget_phpFE;
    QLabel *label_2;
    QTabWidget *tabWidget_2;
    QWidget *widget;
    QListWidget *listWidget_2;
    QWidget *tab_4;
    QWidget *tab_6;
    QTabWidget *tabWidget_compile;
    QWidget *tab_7;
    QPlainTextEdit *plainTextEdit_compile_out;
    QPushButton *pushButton_compileClearOutput;
    QWidget *tab_8;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExtension;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1435, 888);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionLoad_Extension = new QAction(MainWindow);
        actionLoad_Extension->setObjectName(QString::fromUtf8("actionLoad_Extension"));
        actionCreate_Extension = new QAction(MainWindow);
        actionCreate_Extension->setObjectName(QString::fromUtf8("actionCreate_Extension"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionGo_to_PHP_Function = new QAction(MainWindow);
        actionGo_to_PHP_Function->setObjectName(QString::fromUtf8("actionGo_to_PHP_Function"));
        actionCreate_Test = new QAction(MainWindow);
        actionCreate_Test->setObjectName(QString::fromUtf8("actionCreate_Test"));
        actionCompile_Extension = new QAction(MainWindow);
        actionCompile_Extension->setObjectName(QString::fromUtf8("actionCompile_Extension"));
        actionExtension_Properties = new QAction(MainWindow);
        actionExtension_Properties->setObjectName(QString::fromUtf8("actionExtension_Properties"));
        actionSave_Current_Document = new QAction(MainWindow);
        actionSave_Current_Document->setObjectName(QString::fromUtf8("actionSave_Current_Document"));
        actionSave_All_Documents = new QAction(MainWindow);
        actionSave_All_Documents->setObjectName(QString::fromUtf8("actionSave_All_Documents"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(310, 10, 1111, 561));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setTabsClosable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_cFile = new QLabel(tab);
        label_cFile->setObjectName(QString::fromUtf8("label_cFile"));

        verticalLayout_2->addWidget(label_cFile);

        textEdit_cFile = new QPlainTextEdit(tab);
        textEdit_cFile->setObjectName(QString::fromUtf8("textEdit_cFile"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(10);
        textEdit_cFile->setFont(font);

        verticalLayout_2->addWidget(textEdit_cFile);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_hFile = new QLabel(tab_2);
        label_hFile->setObjectName(QString::fromUtf8("label_hFile"));

        verticalLayout_3->addWidget(label_hFile);

        textEdit_hFile = new QPlainTextEdit(tab_2);
        textEdit_hFile->setObjectName(QString::fromUtf8("textEdit_hFile"));
        textEdit_hFile->setFont(font);

        verticalLayout_3->addWidget(textEdit_hFile);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        plainTextEdit_config_m4 = new QPlainTextEdit(tab_3);
        plainTextEdit_config_m4->setObjectName(QString::fromUtf8("plainTextEdit_config_m4"));
        plainTextEdit_config_m4->setFont(font);

        verticalLayout_4->addWidget(plainTextEdit_config_m4);

        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_5 = new QVBoxLayout(tab_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        plainTextEdit_config_w32 = new QPlainTextEdit(tab_5);
        plainTextEdit_config_w32->setObjectName(QString::fromUtf8("plainTextEdit_config_w32"));
        plainTextEdit_config_w32->setFont(font);

        verticalLayout_5->addWidget(plainTextEdit_config_w32);

        tabWidget->addTab(tab_5, QString());
        pushButton_compileExtension = new QPushButton(centralWidget);
        pushButton_compileExtension->setObjectName(QString::fromUtf8("pushButton_compileExtension"));
        pushButton_compileExtension->setGeometry(QRect(1100, 770, 301, 51));
        comboBox_compileType = new QComboBox(centralWidget);
        comboBox_compileType->setObjectName(QString::fromUtf8("comboBox_compileType"));
        comboBox_compileType->setGeometry(QRect(1100, 730, 141, 22));
        label_path_phpSDKBase = new QLabel(centralWidget);
        label_path_phpSDKBase->setObjectName(QString::fromUtf8("label_path_phpSDKBase"));
        label_path_phpSDKBase->setGeometry(QRect(1100, 630, 291, 20));
        label_path_compileBase = new QLabel(centralWidget);
        label_path_compileBase->setObjectName(QString::fromUtf8("label_path_compileBase"));
        label_path_compileBase->setGeometry(QRect(1100, 660, 291, 21));
        label_path_extBase = new QLabel(centralWidget);
        label_path_extBase->setObjectName(QString::fromUtf8("label_path_extBase"));
        label_path_extBase->setGeometry(QRect(1100, 690, 281, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1100, 600, 271, 20));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1260, 730, 141, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 291, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 270, 108, 16));
        listWidget_extensionFiles = new QListWidget(centralWidget);
        listWidget_extensionFiles->setObjectName(QString::fromUtf8("listWidget_extensionFiles"));
        listWidget_extensionFiles->setGeometry(QRect(10, 30, 291, 231));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget_extensionFiles->sizePolicy().hasHeightForWidth());
        listWidget_extensionFiles->setSizePolicy(sizePolicy2);
        listWidget_extensionFiles->setMinimumSize(QSize(0, 0));
        listWidget_extensionFiles->setMaximumSize(QSize(16777215, 16777215));
        listWidget_extensionFiles->setBaseSize(QSize(0, 200));
        listWidget_phpFE = new QListWidget(centralWidget);
        listWidget_phpFE->setObjectName(QString::fromUtf8("listWidget_phpFE"));
        listWidget_phpFE->setGeometry(QRect(10, 290, 291, 251));
        sizePolicy2.setHeightForWidth(listWidget_phpFE->sizePolicy().hasHeightForWidth());
        listWidget_phpFE->setSizePolicy(sizePolicy2);
        listWidget_phpFE->setMinimumSize(QSize(0, 0));
        listWidget_phpFE->setMaximumSize(QSize(16777215, 16777215));
        listWidget_phpFE->setBaseSize(QSize(0, 100));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 550, 37, 16));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(9, 580, 291, 241));
        sizePolicy2.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy2);
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setBaseSize(QSize(200, 190));
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        listWidget_2 = new QListWidget(widget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 10, 261, 191));
        tabWidget_2->addTab(widget, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_2->addTab(tab_6, QString());
        tabWidget_compile = new QTabWidget(centralWidget);
        tabWidget_compile->setObjectName(QString::fromUtf8("tabWidget_compile"));
        tabWidget_compile->setGeometry(QRect(310, 580, 771, 241));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        plainTextEdit_compile_out = new QPlainTextEdit(tab_7);
        plainTextEdit_compile_out->setObjectName(QString::fromUtf8("plainTextEdit_compile_out"));
        plainTextEdit_compile_out->setGeometry(QRect(10, 10, 741, 161));
        pushButton_compileClearOutput = new QPushButton(tab_7);
        pushButton_compileClearOutput->setObjectName(QString::fromUtf8("pushButton_compileClearOutput"));
        pushButton_compileClearOutput->setGeometry(QRect(10, 180, 171, 23));
        tabWidget_compile->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tabWidget_compile->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1435, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExtension = new QMenu(menuBar);
        menuExtension->setObjectName(QString::fromUtf8("menuExtension"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuExtension->menuAction());
        menuFile->addAction(actionLoad_Extension);
        menuFile->addAction(actionCreate_Extension);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Current_Document);
        menuFile->addAction(actionSave_All_Documents);
        menuFile->addSeparator();
        menuExtension->addAction(actionExtension_Properties);
        menuExtension->addAction(actionCreate_Test);
        menuExtension->addAction(actionCompile_Extension);
        menuEdit->addAction(actionPreferences);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_compile->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PHP Extension Editor", 0));
        actionLoad_Extension->setText(QApplication::translate("MainWindow", "Load Extension...", 0));
        actionCreate_Extension->setText(QApplication::translate("MainWindow", "Create  Extension...", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences...", 0));
        actionGo_to_PHP_Function->setText(QApplication::translate("MainWindow", "Go to PHP Function", 0));
        actionCreate_Test->setText(QApplication::translate("MainWindow", "Create Test", 0));
        actionCompile_Extension->setText(QApplication::translate("MainWindow", "Compile Extension...", 0));
        actionExtension_Properties->setText(QApplication::translate("MainWindow", "Extension Properties...", 0));
        actionSave_Current_Document->setText(QApplication::translate("MainWindow", "&Save Current Document", 0));
        actionSave_All_Documents->setText(QApplication::translate("MainWindow", "Save All Documents", 0));
        label_cFile->setText(QApplication::translate("MainWindow", "Current C File:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Source File", 0));
        label_hFile->setText(QApplication::translate("MainWindow", "Current H File:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Header File", 0));
        label_5->setText(QApplication::translate("MainWindow", "Please note: Any changes to this document are saved strait away.", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "config.m4", 0));
        label_6->setText(QApplication::translate("MainWindow", "Please note: Any changes to this document are saved strait away.", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "config.w32", 0));
        pushButton_compileExtension->setText(QApplication::translate("MainWindow", "Compile Extension", 0));
        comboBox_compileType->clear();
        comboBox_compileType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Shared Object", 0)
         << QApplication::translate("MainWindow", "Static", 0)
        );
        label_path_phpSDKBase->setText(QApplication::translate("MainWindow", "Compile Path:", 0));
        label_path_compileBase->setText(QApplication::translate("MainWindow", "Compile Base Path:", 0));
        label_path_extBase->setText(QApplication::translate("MainWindow", "Extension Base:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Compiler Properties", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Debug", 0)
         << QApplication::translate("MainWindow", "Release", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Extension Files:", 0));
        label->setText(QApplication::translate("MainWindow", "User-Space Functions:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Others:", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(widget), QApplication::translate("MainWindow", "INI ENTRIES", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "ARG INFO", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Helper Functions", 0));
        pushButton_compileClearOutput->setText(QApplication::translate("MainWindow", "Clear Compile Output", 0));
        tabWidget_compile->setTabText(tabWidget_compile->indexOf(tab_7), QApplication::translate("MainWindow", "Compiler Output", 0));
        tabWidget_compile->setTabText(tabWidget_compile->indexOf(tab_8), QApplication::translate("MainWindow", "Command Line", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuExtension->setTitle(QApplication::translate("MainWindow", "Extension", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
