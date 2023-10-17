#pragma once

#include <QGraphicsItem>
#include "GGCommon.h"

class QPainter;

#define POSITION_SIZE_1515	8		// 15*15棋盘星位的大小

class GGChessboardItem  : public QGraphicsItem
{
public:
	explicit GGChessboardItem(QRectF rect, int redius=__redius, QGraphicsItem *parent=nullptr);
	explicit GGChessboardItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent = nullptr);
	~GGChessboardItem();

	virtual QRectF boundingRect() const override;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;

	void setChessboardMatrix(GGChessboardType type);

	bool whetherCanDrop(const QPointF &point, QPointF &retPoint);

private:
	void drawGamekuPosition(GGChessboardType type, QPainter* painter=nullptr);	// 画五子棋中得星位
	void drawChessBoard1515(QPainter* painter=nullptr);	// 画15*15棋盘的星位
	void createChessboradArr();
	void clearChessboradArr();
	void initChessboradArr();

private:
	QSizeF				m_size;
	QRectF				m_rect;
	int					m_redius;
	GGChessboardSize	m_chessboardSize;
	GGChessboardType	m_chessboardType;
	const static int	__redius;
	qreal				m_intervalWidth;
	qreal				m_intervalHeight;
	qreal				m_positionSize;	// 星位大小
	GGChessboardCoord	**m_chessboard;	// 棋盘交界点坐标
	int					m_chessCoordArrSize;	// 棋盘坐标矩阵大小 
};
