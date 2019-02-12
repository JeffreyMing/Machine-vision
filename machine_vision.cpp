#include "machine_vision.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

#include<QFileDialog>
#include<QtCore>
#include <QTextEdit>
#include <QByteArray>
#include <QDir>

using namespace cv;
using namespace std;

Machine_Vision::Machine_Vision(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//連結訊號區
	connect(ui.PbnOpen, SIGNAL(clicked()), this, SLOT(OpenImage()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(OpenImage()));
	connect(ui.actionSmoothing, SIGNAL(triggered()), this, SLOT(Smoothing()));
	connect(ui.actionSmoothing_Data, SIGNAL(triggered()), this, SLOT(Smoothing_Data()));
	connect(ui.actionMedian, SIGNAL(triggered()), this, SLOT(Median()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(SaveImage()));
	connect(ui.actionEqualization, SIGNAL(triggered()), this, SLOT(Equalization()));
	connect(ui.actionConservative_Smoothing, SIGNAL(triggered()), this, SLOT(Conservative_Smoothing()));
	connect(ui.actionSecond_Derivative_Sharpening, SIGNAL(triggered()), this, SLOT(Second_Derivative_Sharpening()));
	connect(ui.actionThresholding, SIGNAL(triggered()), this, SLOT(Thresholding()));
	
	ui.horizontalSlider->setRange(1, 100);
	ui.horizontalSlider->setValue(5);
	double SliderValue = ui.horizontalSlider->value()*0.04;
	ui.label_Gamma->setText(QString::number(SliderValue));
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(change_slider()));
	connect(ui.actionPowerLaw, SIGNAL(triggered()), this, SLOT(PowerLaw()));

}

Machine_Vision::~Machine_Vision()
{

}

cv::Mat imgOriginal;            // input image
cv::Mat imgGrayscale;           // grayscale of input image

void Machine_Vision::OpenImage() {
	QString File_Filter = "JPG (*.jpg) ;; PNG (*.png)) ;; BMP(*.bmp)";  //過濾檔案類型
	QString strFileName = QFileDialog::getOpenFileName(this, "Open a picture", QDir::currentPath(), File_Filter);       // bring up open file dialog
	if (strFileName == "") {                                     // if file was not chosen
		ui.lblChosenFile->setText("file not chosen");          // update label
		return;                                                 // and exit function
	}

	imgOriginal = imread(strFileName.toStdString());        // open image

	if (imgOriginal.empty()) {									// if unable to open image 
		ui.lblChosenFile->setText("error: image not read from file");      // 假如路徑有中文會出現此錯誤訊息
		return;                                                             // and exit function
	}
	// if we get to this point image was opened successfully
	ui.lblChosenFile->setText(strFileName);                // update label with file name

	Mat imgOriginalRGB;
	cvtColor(imgOriginal, imgOriginalRGB, CV_BGR2RGB);   // BGR TO RGB
	cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);  //BGR TO GRAY
	
	//CV_8UC3 image To QImage型式
	QImage qimgOriginal = QImage((const unsigned char*)(imgOriginalRGB.data),
		imgOriginalRGB.cols, imgOriginalRGB.rows,
		imgOriginalRGB.cols* imgOriginalRGB.channels(),
		QImage::Format_RGB888);
	//show Original image
	ui.lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));
}

void Machine_Vision::SaveImage() {

	QString Str_saveFileName = QFileDialog::getSaveFileName(this, tr("Save File"), "/", tr("Images (*.jpg *.png)"));
	if (Str_saveFileName == "")
	{
		ui.lblChosenFile->setText("No filename");
		return;
	}
	ui.lblOutputImage->pixmap()->save(Str_saveFileName);   //儲存檔案

}

void Machine_Vision::Smoothing() {

	Mat SmoothingImage = imgGrayscale.clone();

	//Smoothing Mask 1/9[1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1] 9個值相加除以9
	//使用mat.at遍歷
	for (int i = 1; i < SmoothingImage.rows - 1; i++) {
		for (int j = 1; j < SmoothingImage.cols - 1; j++) {
			SmoothingImage.at<uchar>(i, j) =
				(SmoothingImage.at<uchar>(i - 1, j - 1) +
					SmoothingImage.at<uchar>(i - 1, j) +
					SmoothingImage.at<uchar>(i - 1, j + 1) +
					SmoothingImage.at<uchar>(i, j - 1) +
					SmoothingImage.at<uchar>(i, j) +
					SmoothingImage.at<uchar>(i, j + 1) +
					SmoothingImage.at<uchar>(i + 1, j - 1) +
					SmoothingImage.at<uchar>(i + 1, j) +
					SmoothingImage.at<uchar>(i + 1, j + 1)) / 9;
		}
	}

	// CV_8UC1 image To QImage型式
	QImage qSmoothingImage = QImage((const unsigned char*)(SmoothingImage.data),
		SmoothingImage.cols, SmoothingImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qSmoothingImage));
}

void Machine_Vision::Smoothing_Data() {

	Mat SmoothingImage = imgGrayscale.clone();

	for (int i = 1; i < SmoothingImage.rows - 1; i++) {
		for (int j = 1; j < SmoothingImage.cols - 1; j++) {
			SmoothingImage.data[i*SmoothingImage.cols + j] = 
				(SmoothingImage.data[(i - 1)*SmoothingImage.cols + j-1] +
					SmoothingImage.data[(i - 1)*SmoothingImage.cols + j] +
					SmoothingImage.data[(i - 1)*SmoothingImage.cols + j+1] +
					SmoothingImage.data[i*SmoothingImage.cols + j-1] + 
					SmoothingImage.data[i*SmoothingImage.cols + j] + 
					SmoothingImage.data[i*SmoothingImage.cols + j+1] + 
					SmoothingImage.data[(i + 1)*SmoothingImage.cols +j-1] + 
					SmoothingImage.data[(i + 1)*SmoothingImage.cols + j] + 
					SmoothingImage.data[(i + 1)*SmoothingImage.cols +j+1] ) / 9;
		}
	}

	// CV_8UC1 image To QImage型式
	QImage qSmoothingImage = QImage((const unsigned char*)(SmoothingImage.data),
		SmoothingImage.cols, SmoothingImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qSmoothingImage));
}

void Machine_Vision::Median() {
	//中值濾波
	Mat SmoothingImage = imgGrayscale.clone();

	int *arr = new int[9];   //動態記憶體配置

	for (int i = 1; i < SmoothingImage.rows - 1; i++) {
		for (int j = 1; j < SmoothingImage.cols - 1; j++) {
			arr[0] = imgGrayscale.data[(i - 1)*SmoothingImage.cols + j - 1];
			arr[1] = imgGrayscale.data[(i - 1)*SmoothingImage.cols + j];
			arr[2] = imgGrayscale.data[(i - 1)*SmoothingImage.cols + j + 1];
			arr[3] = imgGrayscale.data[i*SmoothingImage.cols + j - 1];
			arr[4] = imgGrayscale.data[i*SmoothingImage.cols + j];
			arr[5] = imgGrayscale.data[i*SmoothingImage.cols + j + 1];
			arr[6] = imgGrayscale.data[(i + 1)*SmoothingImage.cols + j - 1];
			arr[7] = imgGrayscale.data[(i + 1)*SmoothingImage.cols + j];
			arr[8] = imgGrayscale.data[(i + 1)*SmoothingImage.cols + j + 1];
			sort(arr, arr + 8);

			SmoothingImage.data[i*SmoothingImage.cols + j] = arr[4];
		}
	}
	// CV_8UC1 image To QImage型式
	QImage qSmoothingImage = QImage((const unsigned char*)(SmoothingImage.data),
		SmoothingImage.cols, SmoothingImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qSmoothingImage));

	delete[] arr;  //釋放記憶體
}

void Machine_Vision::Equalization() {
	//直方圖等化
	int *hist = new int[256];
	double *pdf = new double[256];

	Mat SmoothingImage = imgGrayscale.clone();

	long ImageSize = SmoothingImage.rows*SmoothingImage.cols;

	for (int i=0; i < 256; i++) {
		hist[i] = 0;
		pdf[i] = 0;
	}

	for (int i = 0; i < ImageSize; i++){
		hist[(int)imgGrayscale.data[i]]++;   //各個向素值累加
	}

	pdf[0] = hist[0] / (double)ImageSize;

	for (int i = 1; i <= 255; i++){
		pdf[i] = pdf[i - 1] + hist[i] / (double)ImageSize;    //將機率一直累加
	}

	for (int i = 0; i<ImageSize; i++){
		SmoothingImage.data[i] = 255 * pdf[(int)imgGrayscale.data[i]];    //機率為0~1，乘上255還原到0~255。
	}

	// CV_8UC1 image To QImage型式
	QImage qSmoothingImage = QImage((const unsigned char*)(SmoothingImage.data),
		SmoothingImage.cols, SmoothingImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qSmoothingImage));
}

void Machine_Vision::PowerLaw() {
	//Power Law(Gamma Correction)
	double Gamma1 = ui.horizontalSlider->value()*0.04;

	double *Lookup_table = new double[256];

	Mat PowerLawImage = imgGrayscale.clone();
	Lookup_table[0] = 0;
	for (int i = 1; i <= 255; i++) {
		Lookup_table[i] = 255*pow((double)i/255, Gamma1);
	}
	
	int ImageSize = PowerLawImage.rows*PowerLawImage.cols;

	for (int i = 0; i < ImageSize; i++) {
		PowerLawImage.data[i] = Lookup_table[imgGrayscale.data[i]];
	}
	QImage qPowerLawImage = QImage((const unsigned char*)(PowerLawImage.data),
		PowerLawImage.cols, PowerLawImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qPowerLawImage));

}

void Machine_Vision::change_slider()
{
	double SliderValue = ui.horizontalSlider->value()*0.04;
	ui.label_Gamma->setText(QString::number(SliderValue));
}

void Machine_Vision::Conservative_Smoothing()
{
	//保守平滑濾波器
	Mat SmoothingImage = imgGrayscale.clone();

	int *arr = new int[9];   //動態記憶體配置

	for (int i = 1; i < SmoothingImage.rows - 1; i++) {
		for (int j = 1; j < SmoothingImage.cols - 1; j++) {
			arr[0] = imgGrayscale.data[(i - 1)*SmoothingImage.cols + j - 1];
			arr[1] = imgGrayscale.data[(i - 1)*SmoothingImage.cols + j];
			arr[2] = imgGrayscale.data[(i - 1)*SmoothingImage.cols + j + 1];
			arr[3] = imgGrayscale.data[i*SmoothingImage.cols + j - 1];
			arr[4] = imgGrayscale.data[i*SmoothingImage.cols + j + 1];
			arr[5] = imgGrayscale.data[(i + 1)*SmoothingImage.cols + j - 1];
			arr[6] = imgGrayscale.data[(i + 1)*SmoothingImage.cols + j];
			arr[7] = imgGrayscale.data[(i + 1)*SmoothingImage.cols + j + 1];
			sort(arr, arr + 7);  //排序

			if (imgGrayscale.data[i*SmoothingImage.cols + j] > arr[7])
				SmoothingImage.data[i*SmoothingImage.cols + j] = arr[7];  //當中心值大於最大值 以最大值取代
			else if (imgGrayscale.data[i*SmoothingImage.cols + j] < arr[0])
				SmoothingImage.data[i*SmoothingImage.cols + j] = arr[0];  //當中心值小於最小值 以最小值取代
		}
	}

	// CV_8UC1 image To QImage型式
	QImage qSmoothingImage = QImage((const unsigned char*)(SmoothingImage.data),
		SmoothingImage.cols, SmoothingImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qSmoothingImage));

	delete[] arr;  //釋放記憶體
}

void Machine_Vision::Second_Derivative_Sharpening()
{

}

void Machine_Vision::Thresholding()
{
	Mat ThresholdingImage = imgGrayscale.clone();

	QString QThresholdValue = ui.lineEdit_ThresholdValue->text();
	int ThresholdValue = QThresholdValue.toInt();

	for (int i = 0; i < ThresholdingImage.rows; i++) {
		for (int j = 0; j < ThresholdingImage.cols; j++) {
			if (imgGrayscale.at<uchar>(i, j) <= ThresholdValue)
				ThresholdingImage.at<uchar>(i, j) = 0;
			else
				ThresholdingImage.at<uchar>(i, j) = 255;
		}
	}

	// CV_8UC1 image To QImage型式
	QImage qThresholdingImage = QImage((const unsigned char*)(ThresholdingImage.data),
		ThresholdingImage.cols, ThresholdingImage.rows,
		imgGrayscale.cols* imgGrayscale.channels(),
		QImage::Format_Indexed8);
	ui.lblOutputImage->setPixmap(QPixmap::fromImage(qThresholdingImage));
}
