#include "GGGraphicsMapView.h"
#include "GGGraphicsMapScene.h"
#include <QGraphicsRectItem>
#include "GGGlobalVariable.h"
#include "GGChessboardItem.h"
#include "GGChessPiecesItem.h"

GGGraphicsMapView::GGGraphicsMapView(QWidget *parent)
	: QGraphicsView(parent)
{
	setRenderHint(QPainter::Antialiasing);  // ÆôÓÃ¿¹¾â³Ý
	m_graphicsMapScene=new GGGraphicsMapScene(this);
	setScene(m_graphicsMapScene);

	int tmpSize=600;
	m_size=QSize(tmpSize*GGGlobalVariable::instance()->m_zoomWidth,tmpSize*GGGlobalVariable::instance()->m_zoomHeight);
	this->setFixedSize(m_size);

	// Ìí¼ÓÆåÅÌ
	tmpSize=530;
	m_rectangleSize=QSize(tmpSize*GGGlobalVariable::instance()->m_zoomWidth, tmpSize*GGGlobalVariable::instance()->m_zoomHeight);
	m_chessboard =new GGChessboardItem(0, 0, m_rectangleSize.width(), m_rectangleSize.height());
	m_chessboard->setChessboardMatrix(GGChessboardType::ChessBoardType_1515);
	m_graphicsMapScene->addItem(m_chessboard);

#if 1
	GGChessPiecesItem *item = new GGChessPiecesItem(QRectF(102.5, 102.5, 40, 40), GGChessPiecesType::ChessPiecesType_White);
	m_graphicsMapScene->addItem(item);
	item = new GGChessPiecesItem(QRectF(142.5, 102.5, 40, 40), GGChessPiecesType::ChessPiecesType_Black);
	m_graphicsMapScene->addItem(item);
#endif // ²âÊÔ

	this->setStyleSheet("border: none; border-radius: 5px; background-color: #D8BCA4;");
}

GGGraphicsMapView::~GGGraphicsMapView()
{}
