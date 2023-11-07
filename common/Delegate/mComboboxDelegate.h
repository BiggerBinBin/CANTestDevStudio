#pragma once

#include <QStyledItemDelegate>
#include <QWidget>
#include <QComboBox>
#include <qtablewidget.h>
#include <QStringList>
class mComboboxDelegate  : public QStyledItemDelegate
{
	Q_OBJECT

public:
	mComboboxDelegate(QObject *parent);
	~mComboboxDelegate();

	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

	void setEditorData(QWidget* editor, const QModelIndex& index) const;
	void setModelData(QWidget* editor, QAbstractItemModel* model,
		const QModelIndex& index) const;

	void updateEditorGeometry(QWidget* editor,
		const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void setItem(const QStringList& itemlist) { m_item_list = itemlist; }
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
	mutable QModelIndex m_index;
protected slots:
	void onCloseEditor(QWidget*);
private:
	QStringList m_item_list;
	
};
