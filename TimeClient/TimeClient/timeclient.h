#ifndef TIMECLIENT_H
#define TIMECLIENT_H
#include "headers.h"
#include <QtWidgets/QDialog>
#include "ui_timeclient.h"

class TimeClient : public QDialog
{
	Q_OBJECT

public:
	TimeClient(QWidget *parent = 0);
	~TimeClient();

private:
	Ui::TimeClientClass ui;
	QLabel *serverNameLabel;
	QLineEdit *serverNameLineEdit;
	QLabel *portLabel;
	QLineEdit *portLineEdit;
	QDateTimeEdit *dateTimeEdit;
	QLabel *stateLabel;

	QPushButton *getBtn;
	QPushButton *quitBtn;

	uint time2u;
	QTcpSocket *tcpSocket;

public slots:
	void enableGetBtn();
	void getTime();
	void readTime();
	void showError(QAbstractSocket::SocketError socketError);


};

#endif // TIMECLIENT_H
