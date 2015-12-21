#include "mainwidow.h"

MainWidow::MainWidow(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	drawwidget = new drawWidget;   	//�½�һ��DrawWidget����
	setCentralWidget(drawwidget);	//�½���DrawWidget������Ϊ�����ڵ����봰��

	createToolBar();                //ʵ��һ��������

	setMinimumSize(600, 400);       	//���������ڵ���С�ߴ�

	showStyle();                    //��ʼ�����ͣ����ÿؼ��еĵ�ǰֵ��Ϊ��ʼֵ
	drawwidget->setWeight(widthSpinBox->value()); 	//��ʼ���߿�
	drawwidget->setColor(Qt::black);             	//��ʼ����ɫ
}

MainWidow::~MainWidow()
{

}
void MainWidow::createToolBar(){
	QToolBar *toolBar = addToolBar("Tool");   	//Ϊ�������½�һ������������

	styleLabel = new QLabel(tr("line style:"));   	//��������ѡ��ؼ�
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
	styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	styleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(showStyle())); //������Ӧ�Ĳۺ���

	widthLabel = new QLabel(tr("line weight:"));    		//�����߿�ѡ��ؼ�
	widthSpinBox = new QSpinBox;
	widthSpinBox->setRange(1, 20);
	connect(widthSpinBox, SIGNAL(valueChanged(int)), drawwidget, SLOT(setWeight(int)));

	colorBtn = new QToolButton;                  //������ɫѡ��ؼ�
	QPixmap pixmap(20, 20);
	pixmap.fill(Qt::black);
	colorBtn->setIcon(QIcon(pixmap));
	connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));

	clearBtn = new QToolButton();               	//���������ť
	clearBtn->setText(tr("clear"));
	connect(clearBtn, SIGNAL(clicked()), drawwidget, SLOT(clear()));

	toolBar->addWidget(styleLabel);
	toolBar->addWidget(styleComboBox);
	toolBar->addWidget(widthLabel);
	toolBar->addWidget(widthSpinBox);
	toolBar->addWidget(colorBtn);
	toolBar->addWidget(clearBtn);
}
void MainWidow::showStyle(){
	drawwidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
}
void MainWidow::showColor(){
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);	//ʹ�ñ�׼��ɫ�Ի���QColorDialog���һ����ɫֵ
	if (color.isValid())
	{
		drawwidget->setColor(color);
		QPixmap p(20, 20);
		p.fill(color);
		colorBtn->setIcon(QIcon(p));
	}
}