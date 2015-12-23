#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "headers.h"
#include "histogramview.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void createAction();
	void createMenu();
	void setupModel();
	void setupView();

	void openFile(QString);

private:
	Ui::MainWindowClass ui;
	QMenu *fileMenu;
	QAction *openAct;

	QStandardItemModel *model;
	QTableView *table;
	QSplitter *splitter;
	HistogramView *histogram;
public slots:
	void slotOpen();
};

#endif // MAINWINDOW_H
