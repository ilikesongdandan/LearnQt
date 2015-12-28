#include "fileview.h"

FileView::FileView(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("File View"));
	fileLineEdit = new QLineEdit(tr("/"));
	fileListWidget = new QListWidget;
	mainlayout = new QVBoxLayout(this);
	mainlayout->addWidget(fileLineEdit);
	mainlayout->addWidget(fileListWidget);

	connect(fileLineEdit, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)));
	connect(fileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotDirShow(QListWidgetItem*)));

	QString root = "/";
	QDir rootDir(root);
	QStringList string;
	string << "*";
	QFileInfoList list = rootDir.entryInfoList(string);
	showFileInfoList(list);
}

FileView::~FileView()
{

}
void FileView::slotShow(QDir dir){
	QStringList string;
	string << "*";
	QFileInfoList list = dir.entryInfoList(string, QDir::AllEntries, QDir::DirsFirst);
	showFileInfoList(list);
}
void FileView::slotDirShow(QListWidgetItem *item){
	QString str = item->text();
	QDir dir;
	dir.setPath(fileLineEdit->text());
	dir.cd(str);
	fileLineEdit->setText(dir.absolutePath());
	slotShow(dir);
}

void FileView::showFileInfoList(QFileInfoList list){
	fileListWidget->clear();
	for (unsigned int i= 0; i < list.count();i++)
	{
		QFileInfo tempFileInfo = list.at(i);
		if (tempFileInfo.isDir())
		{
			QIcon icon("1.png");
			QString fileName = tempFileInfo.fileName();
			QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
			fileListWidget->addItem(tmp);
		}
		else if (tempFileInfo.isFile())
		{
			QIcon icon("2.png");
			QString fileName = tempFileInfo.fileName();
			QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
			fileListWidget->addItem(tmp);
		}
	}
}