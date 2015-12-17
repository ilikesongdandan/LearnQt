#include "splashesreen.h"
#include <windows.h>

SplasheSreen::SplasheSreen(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowTitle("Splash Example");
	QTextEdit *edit = new QTextEdit;
	edit->setText(tr("Spalsh Example"));
	setCentralWidget(edit);

	resize(600, 450);
	Sleep(1000);
}

SplasheSreen::~SplasheSreen()
{

}
