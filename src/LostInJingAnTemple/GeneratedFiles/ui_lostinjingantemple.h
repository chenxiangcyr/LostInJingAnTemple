/********************************************************************************
** Form generated from reading UI file 'lostinjingantemple.ui'
**
** Created: Tue Apr 24 10:46:55 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSTINJINGANTEMPLE_H
#define UI_LOSTINJINGANTEMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LostInJingAnTempleClass
{
public:
    QAction *actionImportData;
    QAction *actionFindShortestPath;
    QAction *actionExportData;
    QAction *actionAbout;
    QAction *actionConvert_To_Weighted_Graph;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuOperation;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LostInJingAnTempleClass)
    {
        if (LostInJingAnTempleClass->objectName().isEmpty())
            LostInJingAnTempleClass->setObjectName(QString::fromUtf8("LostInJingAnTempleClass"));
        LostInJingAnTempleClass->resize(875, 555);
        actionImportData = new QAction(LostInJingAnTempleClass);
        actionImportData->setObjectName(QString::fromUtf8("actionImportData"));
        actionFindShortestPath = new QAction(LostInJingAnTempleClass);
        actionFindShortestPath->setObjectName(QString::fromUtf8("actionFindShortestPath"));
        actionExportData = new QAction(LostInJingAnTempleClass);
        actionExportData->setObjectName(QString::fromUtf8("actionExportData"));
        actionAbout = new QAction(LostInJingAnTempleClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionConvert_To_Weighted_Graph = new QAction(LostInJingAnTempleClass);
        actionConvert_To_Weighted_Graph->setObjectName(QString::fromUtf8("actionConvert_To_Weighted_Graph"));
        centralWidget = new QWidget(LostInJingAnTempleClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LostInJingAnTempleClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LostInJingAnTempleClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 18));
        menuOperation = new QMenu(menuBar);
        menuOperation->setObjectName(QString::fromUtf8("menuOperation"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        LostInJingAnTempleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LostInJingAnTempleClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LostInJingAnTempleClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LostInJingAnTempleClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LostInJingAnTempleClass->setStatusBar(statusBar);

        menuBar->addAction(menuOperation->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOperation->addAction(actionImportData);
        menuOperation->addAction(actionConvert_To_Weighted_Graph);
        menuOperation->addAction(actionFindShortestPath);
        menuOperation->addAction(actionExportData);
        menuHelp->addAction(actionAbout);

        retranslateUi(LostInJingAnTempleClass);

        QMetaObject::connectSlotsByName(LostInJingAnTempleClass);
    } // setupUi

    void retranslateUi(QMainWindow *LostInJingAnTempleClass)
    {
        LostInJingAnTempleClass->setWindowTitle(QApplication::translate("LostInJingAnTempleClass", "Lost In JingAn Temple", 0, QApplication::UnicodeUTF8));
        actionImportData->setText(QApplication::translate("LostInJingAnTempleClass", "Import Data", 0, QApplication::UnicodeUTF8));
        actionFindShortestPath->setText(QApplication::translate("LostInJingAnTempleClass", "Find Shortest Path", 0, QApplication::UnicodeUTF8));
        actionExportData->setText(QApplication::translate("LostInJingAnTempleClass", "Export Data", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("LostInJingAnTempleClass", "About This Program", 0, QApplication::UnicodeUTF8));
        actionConvert_To_Weighted_Graph->setText(QApplication::translate("LostInJingAnTempleClass", "Convert To Weighted Graph", 0, QApplication::UnicodeUTF8));
        menuOperation->setTitle(QApplication::translate("LostInJingAnTempleClass", "Operation", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("LostInJingAnTempleClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LostInJingAnTempleClass: public Ui_LostInJingAnTempleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSTINJINGANTEMPLE_H
