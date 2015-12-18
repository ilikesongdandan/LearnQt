#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QtWidgets/QMainWindow>
#include "ui_imageprocessor.h"
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
	Ui::ImageProcessorClass ui;
	QGridLayout *mainlayout;

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
	QToolBar *fontToolbar;

	QLabel *fontlabel1;
	QFontComboBox *fontComboBox;
	QLabel *fontlabel2;
	QComboBox *SizeComboBox;
	QToolButton *boldBtn;
	QToolButton *italiBtn;
	QToolButton *underlineBtn;
	QToolButton *colorBtn;

	QLabel *listLabel;
	QComboBox *listcombobox;
	QActionGroup *actGrp;
	QAction *leftAction;
	QAction *rightAction;
	QAction *centerAction;
	QAction *justifyAction;
	QToolBar *listToolBar;

protected slots:
	void showfile();
	void showOpenfile();
	void showPrintfile();
	void showPrintimg();
	void showZoomIn();
	void showZoomOut();
	void showRotate90();
	void showRotate180();
	void showRotate270();
	void showMirrowVertical();
	void showMirrowHorizontal();
	void showFontcombobox(QString comboStr);
	void showSizecombobox(QString spinvalue);
	void showBoldBtn();
	void showItaicBtn();
	void showUnderlineBtn();
	void showColorBtn();
	void showCurrenFormatchanged(const QTextCharFormat &fmt);

	void showList(int);
	void showAlignment(QAction *act);
	void showCursorPositionchanged();

};

#endif // IMAGEPROCESSOR_H
