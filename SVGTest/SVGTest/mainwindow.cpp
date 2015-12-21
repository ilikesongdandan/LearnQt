#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("SVG Viewer"));
	createMenu();

	svgWindow = new SvgWindow;
	setCentralWidget(svgWindow);
}

MainWindow::~MainWindow()
{

}
void MainWindow::createMenu()
{
	QMenu *fileMenu = menuBar()->addMenu(tr("file"));

	QAction *openAct = new QAction(tr("open"), this);
	connect(openAct, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
	fileMenu->addAction(openAct);
}

void MainWindow::slotOpenFile()
{
	QString name = QFileDialog::getOpenFileName(this, "open", "/", "svg files(*.svg)");
	svgWindow->setFile(name);
}
