#include "imageprocessor.h"

ImageProcessor::ImageProcessor(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("Easy World"));

	showwidget = new showWidget(this);
	setCentralWidget(showwidget);

	createActions();
	createMenus();
	createToolBars();

	if (img.load("1.png")){
		showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));
	}

}

ImageProcessor::~ImageProcessor()
{
	

}
void ImageProcessor::createActions(){
	openFile = new QAction(QIcon("2.png"), tr("open"), this);
	openFile->setShortcut(tr("ctrl+O"));
	openFile->setStatusTip(tr("open a file"));

	NewFile = new QAction(QIcon("3.png"), tr("new"), this);
	NewFile->setShortcut(tr("ctrl+N"));
	NewFile->setStatusTip(tr("create a new file"));

	exitAction = new QAction(tr("exit"), this);
	exitAction->setShortcut(tr("ctrl+Q"));
	exitAction->setStatusTip(tr("exit progress"));
	connect(exitAction, SIGNAL(clicked()), this, SLOT(close()));

	copyAction = new QAction(QIcon("4.png"), tr("copy"), this);
	copyAction->setShortcut(tr("ctrl+C"));
	copyAction->setStatusTip(tr("copy a file"));
	connect(copyAction, SIGNAL(triggered()), showwidget->text, SLOT(copy()));

	cutAction = new QAction(QIcon("5.png"), tr("cut"), this);
	cutAction->setShortcut(tr("ctrl+X"));
	cutAction->setStatusTip(tr("cut a file"));
	connect(cutAction, SIGNAL(triggered()), showwidget->text, SLOT(cut()));

	pasteAction = new QAction(QIcon("6.png"), tr("paste"), this);
	pasteAction->setShortcut(tr("ctrl+V"));
	pasteAction->setStatusTip(tr("paste a file"));
	connect(pasteAction, SIGNAL(triggered()), showwidget->text, SLOT(paste()));

	aboutAction = new QAction(tr("about"),this);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(QApplication::aboutQt()));

	PrintText = new QAction(QIcon("7.png"), tr("printText"), this);
	PrintText->setStatusTip("print a file");

	PrintImg = new QAction(QIcon("8.png"), tr("printImg"), this);
	PrintImg->setStatusTip("print a Img");

	zoomInAction = new QAction(QIcon("9.png"), tr("big"), this);
	zoomInAction->setStatusTip(tr("big a img"));

	zommOutAction = new QAction(QIcon("10.png"), tr("small"), this);
	zommOutAction->setStatusTip(tr("small a img"));

	rotate90 = new QAction(QIcon("11.png"), tr("rotete90"), this);
	rotate90->setStatusTip(tr("rotate 90 a img"));

	rotate180 = new QAction(QIcon("2.png"), tr("rotete180"), this);
	rotate180->setStatusTip(tr("rotate 180 a img"));

	rotate270 = new QAction(QIcon("3.png"), tr("rotete270"), this);
	rotate270->setStatusTip(tr("rotate 270 a img"));

	mirrowVertical = new QAction(QIcon("4.png"), tr("vertiacl img"), this);
	mirrowVertical->setStatusTip(tr("vertiacl a img"));

	mirrowHorizontal = new QAction(QIcon("5.png"), tr("horizontal img"), this);
	mirrowHorizontal->setStatusTip(tr("horizontal a img"));

	undoAction = new QAction(QIcon("6.png"), "undo", this);
	connect(undoAction, SIGNAL(triggered()), showwidget->text, SLOT(undo()));

	redoAction = new QAction(QIcon("7.png"), "redo", this);
	connect(redoAction, SIGNAL(triggered()), showwidget->text, SLOT(redo()));

}
void ImageProcessor::createMenus(){
	fileMenu = menuBar()->addMenu(tr("file"));
	fileMenu->addAction(openFile);
	fileMenu->addAction(NewFile);
	fileMenu->addAction(PrintText);
	fileMenu->addAction(PrintImg);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	zoomMenu = menuBar()->addMenu(tr("edit"));
	zoomMenu->addAction(copyAction);
	zoomMenu->addAction(cutAction);
	zoomMenu->addAction(pasteAction);
	zoomMenu->addAction(aboutAction);
	zoomMenu->addSeparator();
	zoomMenu->addAction(zoomInAction);
	zoomMenu->addAction(zommOutAction);

	rotateMenu = menuBar()->addMenu(tr("roatte"));
	rotateMenu->addAction(rotate90);
	rotateMenu->addAction(rotate180);
	rotateMenu->addAction(rotate270);

	mirrorMenu = menuBar()->addMenu(tr("mirrow"));
	mirrorMenu->addAction(mirrowVertical);
	mirrorMenu->addAction(mirrowHorizontal);
}
void ImageProcessor::createToolBars(){
	fileTool = addToolBar("File");
	fileTool->addAction(openFile);
	fileTool->addAction(NewFile);
	fileTool->addAction(PrintText);
	fileTool->addAction(PrintImg);

	zoomTool = addToolBar("Edit");
	zoomTool->addAction(copyAction);
	zoomTool->addAction(cutAction);
	zoomTool->addAction(pasteAction);
	zoomTool->addSeparator();
	zoomTool->addAction(zoomInAction);
	zoomTool->addAction(zommOutAction);

	rotateTool = addToolBar("rotate");
	rotateTool->addAction(rotate90);
	rotateTool->addAction(rotate180);
	rotateTool->addAction(rotate270);

	doToolBar = addToolBar("doEdit");
	doToolBar->addAction(undoAction);
	doToolBar->addAction(redoAction);


}