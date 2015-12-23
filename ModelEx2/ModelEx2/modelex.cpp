#include "modelex.h"
#if _MSC_VER >= 1600  

#pragma execution_character_set("utf-8")  

#endif  


ModelEx::ModelEx(QWidget *parent)
: QMainWindow(parent), QAbstractTableModel(parent)
{
	ui.setupUi(this);
	armyMap[1] = tr("�վ�");
	armyMap[2] = tr("����");
	armyMap[3] = tr("½��");
	armyMap[4] = tr("����½ս��");

	weaponTypeMap[1] = tr("��ը��");
	weaponTypeMap[2] = tr("ս����");
	weaponTypeMap[3] = tr("����ĸ��");
	weaponTypeMap[4] = tr("����");
	weaponTypeMap[5] = tr("ֱ����");
	weaponTypeMap[6] = tr("̹��");
	weaponTypeMap[7] = tr("���ܹ�����");
	weaponTypeMap[8] = tr("����ս��");
	populateModel();
}

ModelEx::~ModelEx()
{

}
void ModelEx::populateModel()
{
	header << tr("����") << tr("����") << tr("����");
	army << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1;
	weaponType << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2;
	weapon << tr("B-2") << tr("�����ȼ�") << tr("������") << tr("�Ʒ伶") << tr("�������˼�") << tr("AAAV") << tr("M1A1") << tr("F-22");
}
int ModelEx::columnCount(const QModelIndex &parent) const
{
	return 3;
}

int ModelEx::rowCount(const QModelIndex &parent) const
{
	return army.size();
}

QVariant ModelEx::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case 0:
			return armyMap[army[index.row()]];
			break;
		case 1:
			return weaponTypeMap[weaponType[index.row()]];
			break;
		case 2:
			return weapon[index.row()];
		default:
			return QVariant();
		}
	}
	return QVariant();
}

QVariant ModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole&&orientation == Qt::Horizontal)
		return header[section];
	return QAbstractTableModel::headerData(section, orientation, role);
}