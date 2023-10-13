#include "GGGraphicsMapView.h"
#include "GGGraphicsMapScene.h"
#include <QGraphicsRectItem>

GGGraphicsMapView::GGGraphicsMapView(QWidget *parent)
	: QGraphicsView(parent)
{
	setRenderHint(QPainter::Antialiasing);  // ���ÿ����
	m_graphicsMapScene=new GGGraphicsMapScene(this);
	setScene(m_graphicsMapScene);

	m_size=QSize(600,600);
	this->setFixedSize(m_size);

	// �������
	QGraphicsRectItem* rectangle=new QGraphicsRectItem(0, 0, 580, 580);
	m_graphicsMapScene->addItem(rectangle);
}

GGGraphicsMapView::~GGGraphicsMapView()
{}
