#pragma once

#include <QGraphicsView>

class GGGraphicsMapScene;

class GGGraphicsMapView  : public QGraphicsView
{
	Q_OBJECT

public:
	GGGraphicsMapView(QWidget *parent=nullptr);
	~GGGraphicsMapView();

private:
	GGGraphicsMapScene* m_graphicsMapScene;
	QSize m_size;
};
