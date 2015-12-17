#include "palette.h"
#if _MSC_VER >= 1600  

#pragma execution_character_set("utf-8")  

#endif  

Palette::Palette(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);
	createCtrlFrame();
	createContentFrame();
	QHBoxLayout *mainlayout = new QHBoxLayout(this);
	mainlayout->addWidget(ctrlFrame);
	mainlayout->addWidget(contentFrame);
}

Palette::~Palette()
{

}
void Palette::createCtrlFrame(){
	ctrlFrame = new QFrame;
	windowLabel = new QLabel(tr("QPalette::Window"));
	windowComboBox = new QComboBox;
	fillColorList(windowComboBox);
	connect(windowComboBox, SIGNAL(activated(int)), this, SLOT(ShowWindow()));

	windowTextLabel = new QLabel(tr("QPalette::WindowText"));
	windowTextComboBox = new QComboBox;
	fillColorList(windowTextComboBox);
	connect(windowTextComboBox, SIGNAL(activated(int)), this, SLOT(showWindowText()));

	buttonLabel = new QLabel(tr("QPalette::button"));
	buttonComboBox = new QComboBox;
	fillColorList(buttonComboBox);
	connect(buttonComboBox, SIGNAL(activated(int)), this, SLOT(showButton()));

	buttonTextLabel = new QLabel(tr("Qpalette::ButtonText"));
	buttonTextComboBox = new QComboBox;
	fillColorList(buttonTextComboBox);
	connect(buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(showButtonText()));

	baseLabel = new QLabel(tr("QPalette"));
	baseComboBox = new QComboBox;
	fillColorList(baseComboBox);
	connect(baseComboBox, SIGNAL(activated(int)), this, SLOT(showBase()));

	QGridLayout *mainlayout = new QGridLayout(ctrlFrame);
	mainlayout->setSpacing(20);
	mainlayout->addWidget(windowLabel, 0, 0);
	mainlayout->addWidget(windowComboBox, 0, 1);
	mainlayout->addWidget(windowTextLabel, 1, 0);
	mainlayout->addWidget(windowTextComboBox, 1, 1);
	mainlayout->addWidget(buttonLabel, 2, 0);
	mainlayout->addWidget(buttonComboBox, 2, 1);
	mainlayout->addWidget(buttonTextLabel, 3, 0);
	mainlayout->addWidget(buttonTextComboBox, 3, 1);
	mainlayout->addWidget(baseLabel, 4, 0);
	mainlayout->addWidget(baseComboBox, 4, 1);
}

void Palette::createContentFrame(){
	contentFrame = new QFrame;
	lable1 = new QLabel(tr("请选择一个值"));
	comboBox1 = new QComboBox;

	label2 = new QLabel(tr("请输入字符串："));
	lineEdit2 = new QLineEdit;
	textEdit2 = new QTextEdit;

	QGridLayout *topLayout = new QGridLayout;
	topLayout->addWidget(lable1, 0, 0);
	topLayout->addWidget(comboBox1, 0, 1);
	topLayout->addWidget(label2, 1, 0);
	topLayout->addWidget(lineEdit2, 1, 1);
	topLayout->addWidget(textEdit2, 2, 0, 1, 2);
	okBtn = new QPushButton(tr("确认"));
	cancelBtn = new QPushButton(tr("取消"));

	QHBoxLayout *bottomlayout = new QHBoxLayout;
	bottomlayout->addStretch(1);
	bottomlayout->addWidget(okBtn);
	bottomlayout->addWidget(cancelBtn);

	QVBoxLayout *mainlayout = new QVBoxLayout(contentFrame);
	mainlayout->addLayout(topLayout);
	mainlayout->addLayout(bottomlayout);
}

void Palette::showWindow(){
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[windowComboBox->currentIndex()]);

	QPalette p = contentFrame->palette();
	p.setColor(QPalette::Window, color);
	contentFrame->setPalette(p);
	contentFrame->update();
}

void Palette::showWindowText(){
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[windowTextComboBox->currentIndex()]);

	QPalette p = contentFrame->palette();
	p.setColor(QPalette::WindowText, color);
	contentFrame->setPalette(p);
	//contentFrame->update();
}
void Palette::showButton(){
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[buttonComboBox->currentIndex()]);

	QPalette p = contentFrame->palette();
	p.setColor(QPalette::Button, color);
	contentFrame->setPalette(p);
	contentFrame->update();
}
void Palette::showButtonText(){
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[buttonTextComboBox->currentIndex()]);

	QPalette p = contentFrame->palette();
	p.setColor(QPalette::ButtonText, color);
	contentFrame->setPalette(p);
	//contentFrame->update();
}

void Palette::showBase(){
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[baseComboBox->currentIndex()]);

	QPalette p = contentFrame->palette();
	p.setColor(QPalette::Base, color);
	contentFrame->setPalette(p);
}
void Palette::fillColorList(QComboBox *comboBox){
	QStringList colorList = QColor::colorNames();
	QColor color;
	foreach(color, colorList){
		QPixmap pix(QSize(70, 20));
		pix.fill(QColor(color));
		comboBox->addItem(QIcon(pix), NULL);
		comboBox->setIconSize(QSize(70, 20));
		comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	}
}