#include "GGGraphicsMapView.h"
#include "GGGraphicsMapScene.h"
#include <QGraphicsRectItem>
#include "GGGlobalVariable.h"
#include "GGChessboardItem.h"
#include "GGChessPiecesItem.h"
#include <QMouseEvent>

GGGraphicsMapView::GGGraphicsMapView(QWidget *parent)
	: QGraphicsView(parent)
{
	setRenderHint(QPainter::Antialiasing);  // ÆôÓÃ¿¹¾â³Ý
	

	int tmpSize=600;
	m_size=QSize(tmpSize*GGGlobalVariable::instance()->m_zoomWidth,tmpSize*GGGlobalVariable::instance()->m_zoomHeight);
	this->setFixedSize(m_size);

	m_graphicsMapScene=new GGGraphicsMapScene(this);
	// m_graphicsMapScene->setSceneRect(QRectF(0,0, m_size.width(), m_size.height()));
	setScene(m_graphicsMapScene);

	// Ìí¼ÓÆåÅÌ
	tmpSize=550;
	m_rectangleSize=QSize(tmpSize*GGGlobalVariable::instance()->m_zoomWidth, tmpSize*GGGlobalVariable::instance()->m_zoomHeight);
	m_chessboard =new GGChessboardItem(0, 0, m_rectangleSize.width(), m_rectangleSize.height());
	m_chessboard->setChessboardMatrix(GGChessboardType::ChessBoardType_1515);
	m_graphicsMapScene->addItem(m_chessboard);

#if 0
	GGChessPiecesItem *item = new GGChessPiecesItem(QRectF(102.5, 102.5, 40, 40), GGChessPiecesType::ChessPiecesType_White);
	m_graphicsMapScene->addItem(item);
	item = new GGChessPiecesItem(QRectF(142.5, 102.5, 40, 40), GGChessPiecesType::ChessPiecesType_Black);
	m_graphicsMapScene->addItem(item);
#endif // ²âÊÔ

	this->setStyleSheet("border: none; border-radius: 5px; background-color: #D8BCA4;");
}

GGGraphicsMapView::~GGGraphicsMapView()
{}

void GGGraphicsMapView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		QPointF pointf=this->mapToScene(this->mapFromGlobal(QCursor::pos()));
		QPointF retPointf;
		if (m_chessboard->whetherCanDrop(pointf,retPointf)) {
			QPointF scenePointF=m_chessboard->mapToScene(retPointf);
			GGChessPiecesItem* item=new GGChessPiecesItem(QRectF(scenePointF.x()-20,scenePointF.y()-20,40,40),GGChessPiecesType::ChessPiecesType_White);
			m_graphicsMapScene->addItem(item);
		}
	}

	QGraphicsView::mousePressEvent(event);
}
