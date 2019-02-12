#include "machine_vision.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Machine_Vision w;
	w.show();
	return a.exec();
}
