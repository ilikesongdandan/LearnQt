#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include <QtWidgets/QWidget>
//#include "ui_networkinformation.h"
#include "headers.h"

class NetworkInformation : public QWidget
{
	Q_OBJECT

public:
	NetworkInformation(QWidget *parent = 0);
	~NetworkInformation();
	void getHostInformation();
private:
	//Ui::NetworkInformationClass ui;
	QLabel *hostlabel;
	QLineEdit *LocalHostNameLineEdit;
	QLabel *ipLabel;
	QLineEdit *AddressLineEdit;
	QPushButton *detailBtn;
	QGridLayout *mainLayout;
public slots:
	void slotShowDetail();
};

#endif // NETWORKINFORMATION_H
