/********************************************************************************
** Form generated from reading UI file 'InstumentSet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTUMENTSET_H
#define UI_INSTUMENTSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTestClass
{
public:
    QAction *actionSaveCurrentConfig;
    QAction *actionLoadConfigFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTextEdit *textEdit;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_6;
    QLineEdit *editcmd;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTestClass)
    {
        if (QTestClass->objectName().isEmpty())
            QTestClass->setObjectName(QStringLiteral("QTestClass"));
        QTestClass->resize(1066, 867);
        actionSaveCurrentConfig = new QAction(QTestClass);
        actionSaveCurrentConfig->setObjectName(QStringLiteral("actionSaveCurrentConfig"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QTest/Resources/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveCurrentConfig->setIcon(icon);
        actionLoadConfigFile = new QAction(QTestClass);
        actionLoadConfigFile->setObjectName(QStringLiteral("actionLoadConfigFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/QTest/Resources/\346\211\223\345\274\200\346\226\207\344\273\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadConfigFile->setIcon(icon1);
        centralWidget = new QWidget(QTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        comboBox_5 = new QComboBox(groupBox);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_5);


        verticalLayout_2->addLayout(formLayout);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_6->sizePolicy().hasHeightForWidth());
        comboBox_6->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBox_6);

        editcmd = new QLineEdit(groupBox_2);
        editcmd->setObjectName(QStringLiteral("editcmd"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editcmd->sizePolicy().hasHeightForWidth());
        editcmd->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(editcmd);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        QTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1066, 30));
        QTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTestClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionLoadConfigFile);
        mainToolBar->addAction(actionSaveCurrentConfig);

        retranslateUi(QTestClass);

        QMetaObject::connectSlotsByName(QTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTestClass)
    {
        QTestClass->setWindowTitle(QApplication::translate("QTestClass", "QTest", Q_NULLPTR));
        actionSaveCurrentConfig->setText(QApplication::translate("QTestClass", "SaveCurrentConfig", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSaveCurrentConfig->setToolTip(QApplication::translate("QTestClass", "SaveCurrentConfig", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionLoadConfigFile->setText(QApplication::translate("QTestClass", "LoadConfigFile", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionLoadConfigFile->setToolTip(QApplication::translate("QTestClass", "LoadConfigFile", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("QTestClass", "Instrument Connect Param", Q_NULLPTR));
        label->setText(QApplication::translate("QTestClass", "SA", Q_NULLPTR));
        label_2->setText(QApplication::translate("QTestClass", "SG", Q_NULLPTR));
        label_3->setText(QApplication::translate("QTestClass", "ENA", Q_NULLPTR));
        label_4->setText(QApplication::translate("QTestClass", "RRU", Q_NULLPTR));
        label_5->setText(QApplication::translate("QTestClass", "RUMA", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QTestClass", "Instrument Command", Q_NULLPTR));
        label_7->setText(QApplication::translate("QTestClass", "Instrument Repository DisPlay", Q_NULLPTR));
        label_6->setText(QApplication::translate("QTestClass", "Send Instrument", Q_NULLPTR));
        comboBox_6->setCurrentText(QString());
        pushButton->setText(QApplication::translate("QTestClass", "Send Command", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QTestClass: public Ui_QTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTUMENTSET_H
