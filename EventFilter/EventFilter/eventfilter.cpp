#include "eventfilter.h"

EventFilter::EventFilter(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);

	setWindowTitle(tr("event filter"));

	label1 = new QLabel;
	Image1.load("1.png");
	label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label1->setPixmap(QPixmap::fromImage(Image1));

	label2 = new QLabel;
	Image2.load("2.png");
	label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label2->setPixmap(QPixmap::fromImage(Image2));

	label3 = new QLabel;
	Image3.load("3.png");
	label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label3->setPixmap(QPixmap::fromImage(Image3));

	stateLabel = new QLabel(tr("Mouse Press"));
	stateLabel->setAlignment(Qt::AlignHCenter);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(label1);
	layout->addWidget(label2);
	layout->addWidget(label3);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(layout);
	mainLayout->addWidget(stateLabel);

	label1->installEventFilter(this);
	label2->installEventFilter(this);
	label3->installEventFilter(this);
}

EventFilter::~EventFilter()
{

}
bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == label1)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *mouseEvent = (QMouseEvent *)event;
			if (mouseEvent->buttons()&Qt::LeftButton)
			{
				stateLabel->setText(tr("left mouse press left img"));
			}
			else if (mouseEvent->buttons()&Qt::MidButton)
			{
				stateLabel->setText(tr("mid mouse press left img"));
			}
			else if (mouseEvent->buttons()&Qt::RightButton)
			{
				stateLabel->setText(tr("right mouse press left img"));
			}

			QMatrix matrix;
			matrix.scale(1.8, 1.8);
			QImage tmpImg = Image1.transformed(matrix);
			label1->setPixmap(QPixmap::fromImage(tmpImg));
		}
		if (event->type() == QEvent::MouseButtonRelease)
		{
			stateLabel->setText(tr(" mouse release left img"));
			label1->setPixmap(QPixmap::fromImage(Image1));
		}
	}
	else if (watched == label2)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *mouseEvent = (QMouseEvent *)event;
			if (mouseEvent->buttons()&Qt::LeftButton)
			{
				stateLabel->setText(tr("left mouse press mid img"));
			}
			else if (mouseEvent->buttons()&Qt::MidButton)
			{
				stateLabel->setText(tr("mid mouse press mid img"));
			}
			else if (mouseEvent->buttons()&Qt::RightButton)
			{
				stateLabel->setText(tr("right mouse press mid img"));
			}

			QMatrix matrix;
			matrix.scale(1.8, 1.8);
			QImage tmpImg = Image2.transformed(matrix);
			label2->setPixmap(QPixmap::fromImage(tmpImg));
		}
		if (event->type() == QEvent::MouseButtonRelease)
		{
			stateLabel->setText(tr("mouse release mid img"));
			label2->setPixmap(QPixmap::fromImage(Image2));
		}
	}
	else if (watched == label3)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *mouseEvent = (QMouseEvent *)event;
			if (mouseEvent->buttons()&Qt::LeftButton)
			{
				stateLabel->setText(tr("left mouse press right img"));
			}
			else if (mouseEvent->buttons()&Qt::MidButton)
			{
				stateLabel->setText(tr("mid mouse press right img"));
			}
			else if (mouseEvent->buttons()&Qt::RightButton)
			{
				stateLabel->setText(tr("right mouse press right img"));
			}

			QMatrix matrix;
			matrix.scale(1.8, 1.8);
			QImage tmpImg = Image3.transformed(matrix);
			label3->setPixmap(QPixmap::fromImage(tmpImg));
		}
		if (event->type() == QEvent::MouseButtonRelease)
		{
			stateLabel->setText(tr("mouse release right img"));
			label3->setPixmap(QPixmap::fromImage(Image3));
		}
	}
	return QDialog::eventFilter(watched, event);
}
