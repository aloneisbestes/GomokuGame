#pragma once

#include <QGraphicsView>

class GGGraphicsMapScene;
class GGChessboardItem;

class GGGraphicsMapView  : public QGraphicsView
{
	Q_OBJECT

public:
	GGGraphicsMapView(QWidget *parent=nullptr);
	~GGGraphicsMapView();
	
protected:

	virtual void mousePressEvent(QMouseEvent* event);

private:
	GGGraphicsMapScene* m_graphicsMapScene;
	QSize m_size;
	QSize m_rectangleSize;
	GGChessboardItem* m_chessboard;
};
