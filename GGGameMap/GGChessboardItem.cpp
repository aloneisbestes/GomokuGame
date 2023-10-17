#include "GGChessboardItem.h"
#include <QPainter>
#include <QtMath>

const int GGChessboardItem::__redius=3;

GGChessboardItem::GGChessboardItem(QRectF rect, int redius, QGraphicsItem*parent)
	: QGraphicsItem(parent), m_rect(rect), m_redius(redius)
{
	m_size=rect.size();
	/* �����������Ĭ�� 15*15Ϊ��׼ */
	m_chessboardSize.m_row=15;
	m_chessboardSize.m_column=15;
	m_chessboardType=ChessBoardType_1515;
	m_intervalHeight=0;
	m_intervalWidth=0;
	m_positionSize=0;
	m_chessboard=nullptr;
	m_chessCoordArrSize=15;
	m_intervalWidth=m_size.width()/(m_chessboardSize.m_column-1);
	m_intervalHeight=m_size.height()/(m_chessboardSize.m_row-1);
	createChessboradArr();
	initChessboradArr();
}

GGChessboardItem::GGChessboardItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent)
	: GGChessboardItem(QRectF(x, y, w, h), __redius, parent)
{}

GGChessboardItem::~GGChessboardItem()
{
	clearChessboradArr();
}

QRectF GGChessboardItem::boundingRect() const
{
	return m_rect;
}

void GGChessboardItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setRenderHint(QPainter::Antialiasing); // ���ÿ����

	// ����Բ�Ǿ���
	QPainterPath path;
	path.addRoundedRect(m_rect, m_redius, m_redius);
	QPen pen;
	pen.setWidth(2); // ���ñʵ��߿�
	painter->setPen(pen);
	painter->drawPath(path);

	int row=m_chessboardSize.m_row-1;
	int coloumn=m_chessboardSize.m_column-1;
	int x1, y1, x2, y2;
	for (int i=1; i < row || i < coloumn; ++i) {
		if (i <= coloumn) {
			x1=x2=m_intervalWidth*i;
			y1=0;
			y2=m_size.height();
			painter->drawLine(x1, y1, x2, y2);
		}

		if (i <= row) {
			y1=y2=m_intervalHeight*i;
			x1=0;
			x2=m_size.width();
			painter->drawLine(x1, y1, x2, y2);
		}
	}

	drawGamekuPosition(m_chessboardType, painter);
}

void GGChessboardItem::setChessboardMatrix(GGChessboardType type)
{
	m_chessboardType=type;
	int size;
	switch (m_chessboardType)
	{
		case ChessBoardType_1515:
		{
			size=15;
			m_chessboardSize=GGChessboardSize(size,size);
			m_intervalWidth=m_size.width()/(m_chessboardSize.m_column-1);
			m_intervalHeight=m_size.height()/(m_chessboardSize.m_row-1);
			m_chessCoordArrSize=size;
		}
		break;
		default:
		{
			Q_ASSERT(0);
		}
		break;
	}
	createChessboradArr();
	initChessboradArr();
	update();
}

bool GGChessboardItem::whetherCanDrop(const QPointF &scenePoint,QPointF& retPoint)
{
	QPointF point=this->mapFromScene(scenePoint);
	// ���㵱ǰ�������к���
	int row=qAbs(qFloor(point.y() / m_intervalHeight));
	int column=qAbs(qFloor(point.x()/m_intervalWidth));
	qreal radii=m_intervalWidth/2; // Բ�İ뾶

	for (int i=0; i < 2; ++i) {
		int tmpColumn=column;
		for (int j=0; j < 2; ++j) {
			QPointF center=QPointF(m_chessboard[row][tmpColumn].m_x,m_chessboard[row][tmpColumn].m_y);
			qreal distance=QLineF(center,point).length(); // ����㵽Բ�ĵľ���
			if (distance <= radii) {
				retPoint=center;
				return true;
			}
			tmpColumn+=1;
		}
		row+=1;
	}

	return false;
}

void GGChessboardItem::drawGamekuPosition(GGChessboardType type, QPainter* painter)
{
	switch (type)
	{
		case ChessBoardType_1515:
		{
			m_positionSize=POSITION_SIZE_1515;
			drawChessBoard1515(painter);
		}
		break;
		default:
		{
			Q_ASSERT(0);
		}
		break;
	}
}

void GGChessboardItem::drawChessBoard1515(QPainter* painter)
{
	if (painter == nullptr) {
		return;
	}

	int count=14;	// 15*15�����̳�ȥ��߿��ڲ��ֱ�Ϊ����14����
	int tmpX, tmpY;
	QRectF rect;
	int rectifyWidth=m_positionSize/2;	// ��������
	QPainterPath path;

	// �����ĵ���λ
	tmpX=tmpY=m_intervalWidth*(count/2)-rectifyWidth;
	// ��paint�����л��ƾ���
	painter->setBrush(Qt::black); // ���û�ˢ��ɫ
	rect=QRectF(tmpX, tmpY, m_positionSize, m_positionSize);
	path.addRoundedRect(m_rect, 1, 1);
	painter->drawRect(rect);    // ���ƾ���
	

	// �����������λ
	tmpX=tmpY=m_intervalWidth*3-rectifyWidth;
	rect = QRectF(tmpX, tmpY, m_positionSize, m_positionSize);
	painter->drawRect(rect);    // ���ƾ���

	tmpX=m_intervalWidth*3-rectifyWidth;
	tmpY=m_intervalHeight*11-rectifyWidth;
	rect = QRectF(tmpX, tmpY, m_positionSize, m_positionSize);
	painter->drawRect(rect);    // ���ƾ���


	// ���ұ�������λ
	tmpX=tmpY=m_intervalWidth*11-rectifyWidth;
	rect = QRectF(tmpX, tmpY, m_positionSize, m_positionSize);
	painter->drawRect(rect);    // ���ƾ���

	tmpX=m_intervalWidth*11-rectifyWidth;
	tmpY=m_intervalHeight*3-rectifyWidth;
	rect = QRectF(tmpX, tmpY, m_positionSize, m_positionSize);
	painter->drawRect(rect);    // ���ƾ���
}

void GGChessboardItem::createChessboradArr()
{
	clearChessboradArr();
	m_chessboard=new GGChessboardCoord*[m_chessCoordArrSize];
	for (int i=0; i < m_chessCoordArrSize; i++) {
		m_chessboard[i]=new GGChessboardCoord[m_chessCoordArrSize];
	}
}

void GGChessboardItem::clearChessboradArr()
{
	if (m_chessboard) {
		for (int i=0; i < m_chessCoordArrSize; i++) {
			delete[] m_chessboard[i];
		}

		delete[] m_chessboard;
		m_chessboard=nullptr;
	}
}

void GGChessboardItem::initChessboradArr()
{
	GGChessboardCoord chessboardCoord;
	if (m_chessboard) {
		for (int row=0; row < m_chessCoordArrSize; ++row) {
			for (int column=0; column < m_chessCoordArrSize; ++column) {
				m_chessboard[row][column]=chessboardCoord;
				chessboardCoord.m_x+=m_intervalWidth;
			}
			chessboardCoord.m_y+=m_intervalHeight;
			chessboardCoord.m_x=0;
		}
		
	}
}
