#include "mComboboxDelegate.h"
#include <QPainter>
mComboboxDelegate::mComboboxDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{
	connect(this, SIGNAL(closeEditor(QWidget*)), this, SLOT(onCloseEditor(QWidget*)));
	m_item_list << QStringLiteral("2.0-UDS") << QStringLiteral("1.0-Normal") << QStringLiteral("1.0-UDS");
}

mComboboxDelegate::~mComboboxDelegate()
{}

QWidget* mComboboxDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QComboBox* editor = new QComboBox(parent);
	editor->addItems(m_item_list);
	editor->setCurrentIndex(0);
	return editor;
}

void mComboboxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	QString text = index.model()->data(index, Qt::EditRole).toString();
	QComboBox* comboBox = static_cast<QComboBox*>(editor);
	int tindex = comboBox->findText(text);
	if(tindex>=0)
		comboBox->setCurrentIndex(tindex);
}

void mComboboxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	QComboBox* comboBox = static_cast<QComboBox*>(editor); 
	QString text = comboBox->currentText(); //通过当前的索引得到文本内容
	model->setData(index, text, Qt::EditRole);
}

void mComboboxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	editor->setGeometry(option.rect);//外观尺寸
}

void mComboboxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	if (m_index != index)
	{
		QStyledItemDelegate::paint(painter, option, index);
	}
	painter->restore();
}
void mComboboxDelegate::onCloseEditor(QWidget*)
{
	m_index = QModelIndex();
}
