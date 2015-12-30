#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "headers.h"

class QNetworkReply;
class QNetworkAccessManager;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QNetworkAccessManager *manager;
private slots:
	void replyFinished(QNetworkReply *);

};

#endif // MAINWINDOW_H
