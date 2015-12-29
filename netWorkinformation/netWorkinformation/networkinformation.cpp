#include "networkinformation.h"

NetworkInformation::NetworkInformation(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	hostlabel = new QLabel(tr("host name:"));
	LocalHostNameLineEdit = new QLineEdit;
	ipLabel = new QLabel(tr("IP address:"));
	AddressLineEdit = new QLineEdit;

	detailBtn = new QPushButton(tr("detail"));
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(hostlabel, 0, 0);
	mainLayout->addWidget(LocalHostNameLineEdit, 0, 1);
	mainLayout->addWidget(ipLabel, 1, 0);
	mainLayout->addWidget(AddressLineEdit, 1, 1);
	mainLayout->addWidget(detailBtn, 2, 0, 1, 2);

	getHostInformation();
	connect(detailBtn, SIGNAL(clicked()), this, SLOT(slotShowDetail()));
}

NetworkInformation::~NetworkInformation()
{

}
void NetworkInformation::getHostInformation(){
	QString localhostName = QHostInfo::localHostName();
	LocalHostNameLineEdit->setText(localhostName);

	QHostInfo hostInfo = QHostInfo::fromName(localhostName);
	QList<QHostAddress>listAddress = hostInfo.addresses();
	if (!listAddress.isEmpty())
	{
		AddressLineEdit->setText(listAddress.first().toString());
	}
}
void NetworkInformation::slotShowDetail(){
	QString detail = "";
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
	for (int i = 0; i < list.count();++i)
	{
		QNetworkInterface Interface = list.at(i);
		detail = detail + tr("device:") + Interface.name() + "\n";
		detail = detail + tr("hardware address:") + Interface.hardwareAddress() + "\n";
		QList<QNetworkAddressEntry> entryList = Interface.addressEntries();
		for (int j = 0; j < entryList.count();++j)
		{
			QNetworkAddressEntry entry = entryList.at(j);
			detail = detail + "\t" + tr("IP address:") + entry.ip().toString() + "\n";
			detail = detail + "\t" + tr("subnet mask:") + entry.netmask().toString() + "\n";
			detail = detail + "\t" + tr("broadcast address:") + entry.broadcast().toString() + "\n";
		}
	}
	QMessageBox::information(this, tr("detail"), detail);
}