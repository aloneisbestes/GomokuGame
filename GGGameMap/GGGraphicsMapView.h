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
	

private:
	GGGraphicsMapScene* m_graphicsMapScene;
	QSize m_size;
	QSize m_rectangleSize;
	GGChessboardItem* m_chessboard;
};
