#ifndef MACHINE_VISION_H
#define MACHINE_VISION_H

#include <QtWidgets/QMainWindow>
#include "ui_machine_vision.h"


class Machine_Vision : public QMainWindow
{
	Q_OBJECT

public:
	Machine_Vision(QWidget *parent = 0);
	~Machine_Vision();

private:
	Ui::Machine_VisionClass ui;

private slots:
	void OpenImage();
	void SaveImage();
	void Smoothing();
	void Smoothing_Data();
	void Median();
	void Equalization();
	void PowerLaw();
	void change_slider();
	void Conservative_Smoothing();
	void Second_Derivative_Sharpening();
	void Thresholding();
};

#endif // MACHINE_VISION_H
