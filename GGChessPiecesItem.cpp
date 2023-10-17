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
	painter->setRenderHint(QPainter::Antialiasing); // 启用抗锯齿

	QImage image;
	if (m_chessPiecesType == GGChessPiecesType::ChessPiecesType_Black) {
		// painter->setBrush(QBrush(QColor(52, 49, 40)));	// 设置画刷为黑色
		image=QImage(":/resouce/chess/black.png");
	}
	else {
		// painter->setBrush(QBrush(QColor(238, 236, 215)));	// 设置画刷为黑色
		image = QImage(":/resouce/chess/white.png");
	}

	// 绘制一个圆形
	// painter->setPen(Qt::NoPen); // 设置无边框
	// painter->drawEllipse(m_rectF.x(), m_rectF.y(), m_rectF.width(), m_rectF.height());

	// 在圆形区域内绘制图片
	QPainterPath painterPath=QPainterPath();
	painterPath.addEllipse(m_rectF.x(), m_rectF.y(), m_rectF.width(), m_rectF.height());
	painter->setClipPath(painterPath);
	painter->drawImage(m_rectF.x(), m_rectF.y(), image);
}
