#include "extensiondlg.h"
#if _MSC_VER >= 1600  

#pragma execution_character_set("utf-8")  

#endif  


ExtensionDlg::ExtensionDlg(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);
	setWindowTitle(tr("Extension Dialog"));
	createBaseInfo();
	createDetailInfo();

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(baseWidget);
	layout->addWidget(detailWidget);
	layout->setSizeConstraint(QLayout::SetFixedSize);
	layout->setSpacing(10);
}

ExtensionDlg::~ExtensionDlg()
{

}
void ExtensionDlg::createBaseInfo(){
	baseWidget = new QWidget;
	QLabel *nameLabel = new QLabel(tr("������"));
	QLineEdit *nameLineEdit = new QLineEdit;

	QLabel *sexLabel = new QLabel(tr("�Ա�"));
	QComboBox *sexComboBox = new QComboBox;
	sexComboBox->insertItem(0, tr("��"));
	sexComboBox->insertItem(1, tr("Ů"));

	QGridLayout *leftLayout = new QGridLayout;
	leftLayout->addWidget(nameLabel, 0, 0);
	leftLayout->addWidget(nameLineEdit, 0, 1);
	leftLayout->addWidget(sexLabel, 1, 0);
	leftLayout->addWidget(sexComboBox, 1, 1);

	QPushButton *okBtn = new QPushButton(tr("ȷ��"));
	QPushButton *detailBtn = new QPushButton(tr("��ϸ"));
	QDialogButtonBox *btnBox = new QDialogButtonBox(Qt::Vertical);
	btnBox->addButton(okBtn, QDialogButtonBox::ActionRole);
	btnBox->addButton(detailBtn, QDialogButtonBox::ActionRole);

	QHBoxLayout *mainlayout = new QHBoxLayout(baseWidget);
	mainlayout->addLayout(leftLayout);
	mainlayout->addWidget(btnBox);
	connect(detailBtn, SIGNAL(clicked()), this, SLOT(showDetailInfo()));
}
void ExtensionDlg::createDetailInfo(){
	detailWidget = new QWidget;
	QLabel *agelabel = new QLabel(tr("���䣺"));
	QLineEdit *ageLineEdit = new QLineEdit;
	ageLineEdit->setText(tr("30"));

	QLabel *departmentLabel = new QLabel(tr("����"));
	QComboBox *departmentCombox = new QComboBox;
	departmentCombox->addItem(tr("����1"));
	departmentCombox->addItem(tr("����2"));
	departmentCombox->addItem(tr("����3"));
	departmentCombox->addItem(tr("����4"));
	QLabel *emailLabel = new QLabel(tr("email:"));
	QLineEdit *emaliLineEdit = new QLineEdit;

	QGridLayout *mainlayout = new QGridLayout(detailWidget);
	mainlayout->addWidget(agelabel, 0, 0);
	mainlayout->addWidget(ageLineEdit, 0, 1);
	mainlayout->addWidget(departmentLabel, 1, 0);
	mainlayout->addWidget(departmentCombox, 1, 1);
	mainlayout->addWidget(emailLabel, 2, 0);
	mainlayout->addWidget(emaliLineEdit, 2, 1);

	detailWidget->hide();
}

void ExtensionDlg::showDetailInfo(){
	if (detailWidget->isHidden()){
		detailWidget->show();
	}
	else
	{
		detailWidget->hide();
	}
}