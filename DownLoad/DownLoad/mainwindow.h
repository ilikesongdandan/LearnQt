#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "headers.h"
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class QFile;
class QNetworkReply;
class QNetworkAccessManager;


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void startRequest(QUrl url);
private:
	Ui::MainWindowClass ui;
	QNetworkAccessManager *manager;
	QNetworkReply *reply;
	QUrl url;
	QFile *file;

private slots:
	void replyFinished(QNetworkReply *);
	void httpFinished();
	void httpReadyRead();
	void updateDataReadProgress(qint64, qint64);
	void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
