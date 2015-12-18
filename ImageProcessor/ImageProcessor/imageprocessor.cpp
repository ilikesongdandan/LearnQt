#include "imageprocessor.h"

ImageProcessor::ImageProcessor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Easy World"));

	showwidget = new showWidget(this);
    setCentralWidget(showwidget);
	
	fontlabel1 = new QLabel(tr("font"));
	fontComboBox = new QFontComboBox;
	fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

	fontlabel2 = new QLabel(tr("Size"));
	SizeComboBox = new QComboBox;
	QFontDatabase db;
	foreach (int size ,db.standardSizes())
	{
		SizeComboBox->addItem(QString::number(size));
	}

	boldBtn = new QToolButton;
	boldBtn->setIcon(QIcon("2.png"));
	boldBtn->setCheckable(true);
	boldBtn->setStatusTip(tr("bold"));
	italiBtn = new QToolButton;
	italiBtn->setIcon(QIcon("3.png"));
	italiBtn->setCheckable(true);
	italiBtn->setStatusTip(tr("italic"));

	underlineBtn = new QToolButton;
	underlineBtn->setIcon(QIcon("4.png"));
	underlineBtn->setCheckable(true);
	underlineBtn->setStatusTip(tr("underline"));

	colorBtn = new QToolButton;
	colorBtn->setIcon(QIcon("5.png"));
	colorBtn->setCheckable(true);
	colorBtn->setStatusTip(tr("color"));
	
	connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(showFontcombobox(QString)));
	connect(SizeComboBox, SIGNAL(activated(QString)), this, SLOT(showSizecombobox(QString)));
	connect(boldBtn, SIGNAL(clicked()), this, SLOT(showBoldBtn()));
	connect(italiBtn, SIGNAL(clicked()), this, SLOT(showItaicBtn()));
	connect(underlineBtn, SIGNAL(clicked()), this, SLOT(showUnderlineBtn()));
	connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColorBtn()));
	connect(showwidget->text, SIGNAL(currentCharFormatChanged(QTextCharFormat&)), this, SLOT(showCurrenFormatchanged(QTextCharFormat&)));

	listLabel = new QLabel(tr("list"));
	listcombobox = new QComboBox;
	listcombobox->addItem("Standard");
	listcombobox->addItem("QTextListFormat::ListDisc");
	listcombobox->addItem("QTextListFormat::ListCircle");
	listcombobox->addItem("QTextListFormat::ListSquare");
	listcombobox->addItem("QTextListFormat::ListDecimal");
	listcombobox->addItem("QTextListFormat::ListLowerAlpha");
	listcombobox->addItem("QTextListFormat::ListUpperAlpha");
	listcombobox->addItem("QTextListFormat::ListLowerRoman");
	listcombobox->addItem("QTextListFormat::ListUpperRoman");

	


	createActions();
	createMenus();
	createToolBars();

	if (img.load("1.png")){
		showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));
	}
	//showwidget->imagelabel->resize(showwidget->size());
	connect(listcombobox, SIGNAL(activated()), this, SLOT(showList(int)));
	connect(showwidget->text->document(), SIGNAL(undoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));
	connect(showwidget->text->document(), SIGNAL(redoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));
	connect(showwidget->text->document(), SIGNAL(cursorPositionChanged()), this, SLOT(showCursorPositionchanged()));
}

ImageProcessor::~ImageProcessor()
{
	

}
void ImageProcessor::createActions(){
	openFile = new QAction(QIcon("2.png"), tr("open"), this);
	openFile->setShortcut(tr("ctrl+O"));
	openFile->setStatusTip(tr("open a file"));
	connect(openFile, SIGNAL(triggered()), this, SLOT(showOpenfile()));

	NewFile = new QAction(QIcon("3.png"), tr("new"), this);
	NewFile->setShortcut(tr("ctrl+N"));
	NewFile->setStatusTip(tr("create a new file"));
	connect(NewFile, SIGNAL(triggered()), this, SLOT(showfile()));

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
	connect(PrintText, SIGNAL(triggered()), this, SLOT(showPrintfile()));

	PrintImg = new QAction(QIcon("8.png"), tr("printImg"), this);
	PrintImg->setStatusTip("print a Img");
	connect(PrintImg, SIGNAL(triggered()), this, SLOT(showPrintimg()));

	zoomInAction = new QAction(QIcon("9.png"), tr("big"), this);
	zoomInAction->setStatusTip(tr("big a img"));
	connect(zoomInAction, SIGNAL(triggered()), this, SLOT(showZoomIn()));

	zommOutAction = new QAction(QIcon("10.png"), tr("small"), this);
	zommOutAction->setStatusTip(tr("small a img"));
	connect(zommOutAction, SIGNAL(triggered()), this, SLOT(showZoomOut()));

	rotate90 = new QAction(QIcon("11.png"), tr("rotete90"), this);
	rotate90->setStatusTip(tr("rotate 90 a img"));
	connect(rotate90, SIGNAL(triggered()), this, SLOT(showRotate90()));

	rotate180 = new QAction(QIcon("2.png"), tr("rotete180"), this);
	rotate180->setStatusTip(tr("rotate 180 a img"));
	connect(rotate180, SIGNAL(triggered()), this, SLOT(showRotate180()));

	rotate270 = new QAction(QIcon("3.png"), tr("rotete270"), this);
	rotate270->setStatusTip(tr("rotate 270 a img"));
	connect(rotate270, SIGNAL(triggered()), this, SLOT(showRotate270()));

	mirrowVertical = new QAction(QIcon("4.png"), tr("vertiacl img"), this);
	mirrowVertical->setStatusTip(tr("vertiacl a img"));
	connect(mirrowVertical, SIGNAL(triggered()), this, SLOT(showMirrowVertical()));

	mirrowHorizontal = new QAction(QIcon("5.png"), tr("horizontal img"), this);
	mirrowHorizontal->setStatusTip(tr("horizontal a img"));
	connect(mirrowHorizontal, SIGNAL(triggered()), this, SLOT(showMirrowHorizontal()));

	undoAction = new QAction(QIcon("6.png"), "undo", this);
	connect(undoAction, SIGNAL(triggered()), showwidget->text, SLOT(undo()));

	redoAction = new QAction(QIcon("7.png"), "redo", this);
	connect(redoAction, SIGNAL(triggered()), showwidget->text, SLOT(redo()));

	actGrp = new QActionGroup(this);
	leftAction = new QAction(QIcon("5.png"), "left", actGrp);
	leftAction->setCheckable(true);
	leftAction->setStatusTip(tr("left"));
	rightAction = new QAction(QIcon("6.png"), "right", actGrp);
	rightAction->setCheckable(true);
	rightAction->setStatusTip(tr("right"));

	centerAction = new QAction(QIcon("7.png"), "center", actGrp);
	centerAction->setCheckable(true);
	centerAction->setStatusTip(tr("center"));

	justifyAction = new QAction(QIcon("8.png"), "justify", actGrp);
	justifyAction->setCheckable(true);
	justifyAction->setStatusTip(tr("justify"));
	connect(actGrp, SIGNAL(triggered(QAction*)), this, SLOT(showAlignment(QAction*)));
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
	rotateTool->addAction(mirrowVertical);
	rotateTool->addAction(mirrowHorizontal);

	doToolBar = addToolBar("doEdit");
	doToolBar->addAction(undoAction);
	doToolBar->addAction(redoAction);

	fontToolbar = addToolBar("Font");
	fontToolbar->addWidget(fontlabel1);
	fontToolbar->addWidget(fontComboBox);
	fontToolbar->addWidget(fontlabel2);
	fontToolbar->addWidget(SizeComboBox);
	fontToolbar->addSeparator();
	fontToolbar->addWidget(boldBtn);
	fontToolbar->addWidget(italiBtn);
	fontToolbar->addWidget(underlineBtn);
	fontToolbar->addSeparator();
	fontToolbar->addWidget(colorBtn);

	listToolBar = addToolBar("list");
	listToolBar->addWidget(listLabel);
	listToolBar->addWidget(listcombobox);
	listToolBar->addSeparator();
	listToolBar->addActions(actGrp->actions());
}
void ImageProcessor::showfile(){
	ImageProcessor *newImgProcessor = new ImageProcessor;
	newImgProcessor->show();
}
void ImageProcessor::showOpenfile(){
	filename = QFileDialog::getOpenFileName(this);
	if (!filename.isEmpty()){
		if (showwidget->text->document()->isEmpty()){
			loadFile(filename);
		}
		else
		{
			ImageProcessor *newImgProcessor = new ImageProcessor;
			newImgProcessor->show();
			newImgProcessor->loadFile(filename);
		}
	}
}
void ImageProcessor::loadFile(QString filename){
	printf("file name:%s\n", filename.data());

	QFile file(filename);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream textStream(&file);
		while (!textStream.atEnd())
		{
			showwidget->text->append(textStream.readLine());
			printf("read line\n");
		}
		printf("end\n");
	}
}

void ImageProcessor::showPrintfile(){
	QPrinter printer;
	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec()){
		QTextDocument *doc = showwidget->text->document();
		doc->print(&printer);
	}
}
void ImageProcessor::showPrintimg(){
	QPrinter printer;
	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec()){
		QPainter painer(&printer);
		QRect rect = painer.viewport();
		QSize size = img.size();
		size.scale(rect.size(), Qt::KeepAspectRatio);
		painer.setViewport(rect.x(), rect.y(), size.width(), size.height());
		painer.setWindow(img.rect());
		painer.drawImage(0, 0, img);
	}
}
void ImageProcessor::showZoomIn(){
	if (img.isNull()){
		return;
	}
	QMatrix matrix;
	matrix.scale(2, 2);
	img = img.transformed(matrix);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));
}
void ImageProcessor::showZoomOut(){
	if (img.isNull()){
		return;
	}
	QMatrix matrix;
	matrix.scale(0.5,0.5);
	img = img.transformed(matrix);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));
}

void ImageProcessor::showRotate90(){
	if (img.isNull()){ return; }
	QMatrix matrix;
	matrix.rotate(90);
	img = img.transformed(matrix);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));

}
void ImageProcessor::showRotate180(){
	if (img.isNull()){ return; }
	QMatrix matrix;
	matrix.rotate(180);
	img = img.transformed(matrix);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));

}
void ImageProcessor::showRotate270(){
	if (img.isNull()){ return; }
	QMatrix matrix;
	matrix.rotate(270);
	img = img.transformed(matrix);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));

}
void ImageProcessor::showMirrowVertical(){
	if (img.isNull()){ return; }
	 
	img = img.mirrored(false,true);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));

}
void ImageProcessor::showMirrowHorizontal(){
	if (img.isNull()){ return; }

	img = img.mirrored(true,false);
	showwidget->imagelabel->setPixmap(QPixmap::fromImage(img));

}
void ImageProcessor::showFontcombobox(QString comboStr){
	QTextCharFormat fmt;
	fmt.setFontFamily(comboStr);
	mergeFormat(fmt);
}
void ImageProcessor::mergeFormat(QTextCharFormat format){
	QTextCursor cursor = showwidget->text->textCursor();
	if (!cursor.hasSelection()){
		cursor.select(QTextCursor::WordUnderCursor);
		cursor.mergeCharFormat(format);
		showwidget->text->mergeCurrentCharFormat(format);
	}
}
void ImageProcessor::showSizecombobox(QString Spinvalue){
	QTextCharFormat fmt;
	fmt.setFontPointSize(Spinvalue.toFloat());
	showwidget->text->mergeCurrentCharFormat(fmt);
}
void ImageProcessor::showBoldBtn(){
	QTextCharFormat fmt;
	fmt.setFontWeight(boldBtn->isCheckable()?QFont::Bold:QFont::Normal);
	showwidget->text->mergeCurrentCharFormat(fmt);
}
void ImageProcessor::showItaicBtn(){
	QTextCharFormat fmt;
	fmt.setFontItalic(italiBtn->isCheckable());
	showwidget->text->mergeCurrentCharFormat(fmt);
}
void ImageProcessor::showUnderlineBtn(){
	QTextCharFormat fmt;
	fmt.setFontUnderline(underlineBtn->isCheckable());
	showwidget->text->mergeCurrentCharFormat(fmt);
}
void ImageProcessor::showColorBtn(){
	QColor color = QColorDialog::getColor(Qt::red, this);
	if (color.isValid())
	{
		QTextCharFormat fmt;
		fmt.setForeground(color);
		showwidget->text->mergeCurrentCharFormat(fmt);
	}
}
void ImageProcessor::showCurrenFormatchanged(const QTextCharFormat &fmt){
	fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
	SizeComboBox->setCurrentIndex(SizeComboBox->findText(QString::number(fmt.fontPointSize())));
	boldBtn->setChecked(fmt.font().bold());
	italiBtn->setChecked(fmt.fontItalic());
	underlineBtn->setChecked(fmt.fontUnderline());
}

void ImageProcessor::showAlignment(QAction *act){
	if (act == leftAction){
		showwidget->text->setAlignment(Qt::AlignLeft);
	}
	if (act ==rightAction){
		showwidget->text->setAlignment(Qt::AlignRight);
	}
	if (act == centerAction){
		showwidget->text->setAlignment(Qt::AlignCenter);

	}
	if (act == justifyAction){
		showwidget->text->setAlignment(Qt::AlignJustify);
	}
}
void ImageProcessor::showCursorPositionchanged(){
	if (showwidget->text->alignment() == Qt::AlignLeft){
		leftAction->setChecked(true);
	}
	if (showwidget->text->alignment() == Qt::AlignRight){
		rightAction->setChecked(true);
	}
	if (showwidget->text->alignment() == Qt::AlignCenter){
		centerAction->setChecked(true);
	}
	if (showwidget->text->alignment() == Qt::AlignJustify){
		justifyAction->setChecked(true);
	}
}
void ImageProcessor::showList(int index){
	QTextCursor cursor = showwidget->text->textCursor();
	if (index != 0){
		QTextListFormat::Style style = QTextListFormat::ListDisc;
		switch (index)
		{
		case 1:
			style = QTextListFormat::ListDisc;break;
		case 2:
			style = QTextListFormat::ListCircle; break;
		case 3:
			style = QTextListFormat::ListSquare; break;
		case 4:
			style = QTextListFormat::ListDecimal; break;
		case 5:
			style = QTextListFormat::ListLowerAlpha; break;
		case 6:
			style = QTextListFormat::ListUpperAlpha; break;
		case 7:
			style = QTextListFormat::ListLowerRoman; break;
		case 8:
			style = QTextListFormat::ListUpperRoman; break;
		default:
			break;
		}
		cursor.beginEditBlock();
		QTextBlockFormat blockfmt = cursor.blockFormat();
		QTextListFormat listfmt;
		if (cursor.currentList()){
			listfmt = cursor.currentList()->format();
		}
		else
		{
			listfmt.setIndent(blockfmt.indent() + 1);
			blockfmt.setIndent(0);
			cursor.setBlockFormat(blockfmt);
		}
		listfmt.setStyle(style);
		cursor.createList(listfmt);
		cursor.endEditBlock();
	}
	else
	{
		QTextBlockFormat bfmt;
		bfmt.setObjectIndex(-1);
		cursor.mergeBlockFormat(bfmt);
	}
}