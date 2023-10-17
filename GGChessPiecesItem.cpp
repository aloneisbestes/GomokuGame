#include "GGChessPiecesItem.h"
#include <QPainter>
#include <QPainterPath>

GGChessPiecesItem::GGChessPiecesItem(QRectF rect, GGChessPiecesType type, QGraphicsItem* parent)
	: QGraphicsItem(parent), m_rectF(rect), m_chessPiecesType(type)
{
}

GGChessPiecesItem::~GGChessPiecesItem()
{}

QRectF GGChessPiecesItem::boundingRect() const
{
	return m_rectF;
}

void GGChessPiecesItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setRenderHint(QPainter::Antialiasing); // ���ÿ����

	QImage image;
	if (m_chessPiecesType == GGChessPiecesType::ChessPiecesType_Black) {
		// painter->setBrush(QBrush(QColor(52, 49, 40)));	// ���û�ˢΪ��ɫ
		image=QImage(":/resouce/chess/black.png");
	}
	else {
		// painter->setBrush(QBrush(QColor(238, 236, 215)));	// ���û�ˢΪ��ɫ
		image = QImage(":/resouce/chess/white.png");
	}

	// ����һ��Բ��
	// painter->setPen(Qt::NoPen); // �����ޱ߿�
	// painter->drawEllipse(m_rectF.x(), m_rectF.y(), m_rectF.width(), m_rectF.height());

	// ��Բ�������ڻ���ͼƬ
	QPainterPath painterPath=QPainterPath();
	painterPath.addEllipse(m_rectF.x(), m_rectF.y(), m_rectF.width(), m_rectF.height());
	painter->setClipPath(painterPath);
	painter->drawImage(m_rectF.x(), m_rectF.y(), image);
}
