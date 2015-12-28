#ifndef WATCHER_H
#define WATCHER_H
#include "headers.h"
#include <QtWidgets/QMainWindow>
//#include "ui_watcher.h"

class Watcher : public QWidget
{
	Q_OBJECT

public:
	Watcher(QWidget *parent = 0);
	~Watcher();

private:
	//Ui::WatcherClass ui;
	public slots :
		void directoryChanged(QString path);
private:
	QLabel *pathLabel;
	QFileSystemWatcher fsWatcher;
};

#endif // WATCHER_H
