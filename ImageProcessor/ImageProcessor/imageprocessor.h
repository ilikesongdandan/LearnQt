#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QtWidgets/QMainWindow>
//#include "ui_imageprocessor.h"
#include "headers.h"
#include "showwidget.h"

class ImageProcessor : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcessor(QWidget *parent = 0);
	~ImageProcessor();
	
	void createActions();
	void createMenus();
	void createToolBars();
	void loadFile(QString filename);
	void mergeFormat(QTextCharFormat);

private:
	//Ui::ImageProcessorClass ui;
	QMenu *fileMenu;
	QMenu *zoomMenu;
	QMenu *rotateMenu;
	QMenu *mirrorMenu;

	QImage img;
	QString filename;
	
	showWidget *showwidget;

	QAction *openFile;
	QAction *NewFile;
	QAction *PrintText;
	QAction *PrintImg;
	QAction *exitAction;
	QAction *copyAction;
	QAction *cutAction;
	QAction *pasteAction;
	QAction *aboutAction;
	QAction *zoomInAction;
	QAction *zommOutAction;

	QAction *rotate90;
	QAction *rotate180;
	QAction *rotate270;

	QAction *mirrowVertical;
	QAction *mirrowHorizontal;

	QAction *undoAction;
	QAction *redoAction;

	QToolBar *fileTool;
	QToolBar *zoomTool;
	QToolBar *rotateTool;
	QToolBar *mirrowTool;

	QToolBar *doToolBar;
};

#endif // IMAGEPROCESSOR_H
