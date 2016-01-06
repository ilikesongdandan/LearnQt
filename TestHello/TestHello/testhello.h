#ifndef TESTHELLO_H
#define TESTHELLO_H

#include <QtWidgets/QMainWindow>
#include "ui_testhello.h"

class TestHello : public QMainWindow
{
	Q_OBJECT

public:
	TestHello(QWidget *parent = 0);
	~TestHello();

private:
	Ui::TestHelloClass ui;
};

#endif // TESTHELLO_H
