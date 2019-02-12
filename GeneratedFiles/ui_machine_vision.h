/********************************************************************************
** Form generated from reading UI file 'machine_vision.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACHINE_VISION_H
#define UI_MACHINE_VISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Machine_VisionClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSmoothing;
    QAction *actionSmoothing_Data;
    QAction *actionMedian;
    QAction *actionEqualization;
    QAction *actionPowerLaw;
    QAction *actionConservative_Smoothing;
    QAction *actionSecond_Derivative_Sharpening;
    QAction *actionThresholding;
    QWidget *centralWidget;
    QPushButton *PbnOpen;
    QLabel *lblChosenFile;
    QLabel *lblOriginal;
    QLabel *lblOutputImage;
    QSlider *horizontalSlider;
    QLabel *label_Gamma;
    QLabel *lbl_ThresholdValue;
    QLineEdit *lineEdit_ThresholdValue;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPre_processing;
    QMenu *menuSegmentation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Machine_VisionClass)
    {
        if (Machine_VisionClass->objectName().isEmpty())
            Machine_VisionClass->setObjectName(QStringLiteral("Machine_VisionClass"));
        Machine_VisionClass->setWindowModality(Qt::NonModal);
        Machine_VisionClass->resize(738, 455);
        Machine_VisionClass->setDocumentMode(false);
        actionOpen = new QAction(Machine_VisionClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Machine_VisionClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSmoothing = new QAction(Machine_VisionClass);
        actionSmoothing->setObjectName(QStringLiteral("actionSmoothing"));
        actionSmoothing_Data = new QAction(Machine_VisionClass);
        actionSmoothing_Data->setObjectName(QStringLiteral("actionSmoothing_Data"));
        actionMedian = new QAction(Machine_VisionClass);
        actionMedian->setObjectName(QStringLiteral("actionMedian"));
        actionEqualization = new QAction(Machine_VisionClass);
        actionEqualization->setObjectName(QStringLiteral("actionEqualization"));
        actionPowerLaw = new QAction(Machine_VisionClass);
        actionPowerLaw->setObjectName(QStringLiteral("actionPowerLaw"));
        actionConservative_Smoothing = new QAction(Machine_VisionClass);
        actionConservative_Smoothing->setObjectName(QStringLiteral("actionConservative_Smoothing"));
        actionSecond_Derivative_Sharpening = new QAction(Machine_VisionClass);
        actionSecond_Derivative_Sharpening->setObjectName(QStringLiteral("actionSecond_Derivative_Sharpening"));
        actionThresholding = new QAction(Machine_VisionClass);
        actionThresholding->setObjectName(QStringLiteral("actionThresholding"));
        centralWidget = new QWidget(Machine_VisionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PbnOpen = new QPushButton(centralWidget);
        PbnOpen->setObjectName(QStringLiteral("PbnOpen"));
        PbnOpen->setGeometry(QRect(20, 350, 101, 41));
        lblChosenFile = new QLabel(centralWidget);
        lblChosenFile->setObjectName(QStringLiteral("lblChosenFile"));
        lblChosenFile->setGeometry(QRect(130, 360, 301, 20));
        lblOriginal = new QLabel(centralWidget);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        lblOriginal->setGeometry(QRect(20, 20, 341, 291));
        lblOriginal->setContextMenuPolicy(Qt::CustomContextMenu);
        lblOriginal->setAcceptDrops(false);
        lblOriginal->setLayoutDirection(Qt::LeftToRight);
        lblOriginal->setAutoFillBackground(false);
        lblOriginal->setFrameShape(QFrame::Panel);
        lblOriginal->setFrameShadow(QFrame::Plain);
        lblOriginal->setScaledContents(true);
        lblOutputImage = new QLabel(centralWidget);
        lblOutputImage->setObjectName(QStringLiteral("lblOutputImage"));
        lblOutputImage->setGeometry(QRect(380, 20, 341, 291));
        lblOutputImage->setContextMenuPolicy(Qt::CustomContextMenu);
        lblOutputImage->setAcceptDrops(false);
        lblOutputImage->setLayoutDirection(Qt::LeftToRight);
        lblOutputImage->setAutoFillBackground(false);
        lblOutputImage->setFrameShape(QFrame::Panel);
        lblOutputImage->setFrameShadow(QFrame::Plain);
        lblOutputImage->setScaledContents(true);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 320, 281, 19));
        QFont font;
        font.setFamily(QStringLiteral("3ds"));
        font.setPointSize(12);
        horizontalSlider->setFont(font);
        horizontalSlider->setValue(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedControls(false);
        label_Gamma = new QLabel(centralWidget);
        label_Gamma->setObjectName(QStringLiteral("label_Gamma"));
        label_Gamma->setGeometry(QRect(310, 320, 31, 21));
        label_Gamma->setFrameShape(QFrame::Box);
        lbl_ThresholdValue = new QLabel(centralWidget);
        lbl_ThresholdValue->setObjectName(QStringLiteral("lbl_ThresholdValue"));
        lbl_ThresholdValue->setGeometry(QRect(370, 320, 91, 21));
        lineEdit_ThresholdValue = new QLineEdit(centralWidget);
        lineEdit_ThresholdValue->setObjectName(QStringLiteral("lineEdit_ThresholdValue"));
        lineEdit_ThresholdValue->setGeometry(QRect(460, 320, 31, 21));
        Machine_VisionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Machine_VisionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 738, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPre_processing = new QMenu(menuBar);
        menuPre_processing->setObjectName(QStringLiteral("menuPre_processing"));
        menuSegmentation = new QMenu(menuBar);
        menuSegmentation->setObjectName(QStringLiteral("menuSegmentation"));
        Machine_VisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Machine_VisionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Machine_VisionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Machine_VisionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Machine_VisionClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPre_processing->menuAction());
        menuBar->addAction(menuSegmentation->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuPre_processing->addAction(actionSmoothing);
        menuPre_processing->addAction(actionSmoothing_Data);
        menuPre_processing->addAction(actionMedian);
        menuPre_processing->addAction(actionEqualization);
        menuPre_processing->addAction(actionPowerLaw);
        menuPre_processing->addAction(actionConservative_Smoothing);
        menuPre_processing->addAction(actionSecond_Derivative_Sharpening);
        menuSegmentation->addAction(actionThresholding);

        retranslateUi(Machine_VisionClass);

        QMetaObject::connectSlotsByName(Machine_VisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *Machine_VisionClass)
    {
        Machine_VisionClass->setWindowTitle(QApplication::translate("Machine_VisionClass", "Machine_Vision", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("Machine_VisionClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("Machine_VisionClass", "Save", Q_NULLPTR));
        actionSmoothing->setText(QApplication::translate("Machine_VisionClass", "Smoothing_at", Q_NULLPTR));
        actionSmoothing_Data->setText(QApplication::translate("Machine_VisionClass", "Smoothing_Data", Q_NULLPTR));
        actionMedian->setText(QApplication::translate("Machine_VisionClass", "Median", Q_NULLPTR));
        actionEqualization->setText(QApplication::translate("Machine_VisionClass", "Equalization", Q_NULLPTR));
        actionPowerLaw->setText(QApplication::translate("Machine_VisionClass", "PowerLaw", Q_NULLPTR));
        actionConservative_Smoothing->setText(QApplication::translate("Machine_VisionClass", "Conservative Smoothing", Q_NULLPTR));
        actionSecond_Derivative_Sharpening->setText(QApplication::translate("Machine_VisionClass", "Second Derivative Sharpening", Q_NULLPTR));
        actionThresholding->setText(QApplication::translate("Machine_VisionClass", "Thresholding", Q_NULLPTR));
        PbnOpen->setText(QApplication::translate("Machine_VisionClass", "Open", Q_NULLPTR));
        lblChosenFile->setText(QApplication::translate("Machine_VisionClass", "STATUS", Q_NULLPTR));
        lblOriginal->setText(QString());
        lblOutputImage->setText(QString());
        label_Gamma->setText(QString());
        lbl_ThresholdValue->setText(QApplication::translate("Machine_VisionClass", "Threshold Value\357\274\232", Q_NULLPTR));
        lineEdit_ThresholdValue->setText(QApplication::translate("Machine_VisionClass", "100", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("Machine_VisionClass", "File", Q_NULLPTR));
        menuPre_processing->setTitle(QApplication::translate("Machine_VisionClass", "Pre-processing", Q_NULLPTR));
        menuSegmentation->setTitle(QApplication::translate("Machine_VisionClass", "Segmentation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Machine_VisionClass: public Ui_Machine_VisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINE_VISION_H
