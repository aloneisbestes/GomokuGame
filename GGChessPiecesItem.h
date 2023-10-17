#pragma once

#include <QGraphicsItem>
#include "GGCommon.h"

class GGChessPiecesItem  : public QGraphicsItem
{
public:
	GGChessPiecesItem(QRectF rect, GGChessPiecesType type=ChessPiecesType_Black, QGraphicsItem *parent=nullptr);
	~GGChessPiecesItem();

	virtual QRectF boundingRect() const override;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;

private:
	QRectF					m_rectF;				// �ؼ���С
	GGChessPiecesType		m_chessPiecesType;		// ��������
};
