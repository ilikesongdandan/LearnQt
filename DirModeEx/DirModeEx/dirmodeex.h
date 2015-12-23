#ifndef DIRMODEEX_H
#define DIRMODEEX_H

#include <QtWidgets/QMainWindow>
#include "ui_dirmodeex.h"

class DirModeEx : public QMainWindow
{
	Q_OBJECT

public:
	DirModeEx(QWidget *parent = 0);
	~DirModeEx();

private:
	Ui::DirModeExClass ui;
};

#endif // DIRMODEEX_H
