#ifndef __GG_COMMON_H__
#define __GG_COMMON_H__

struct GGChessboardSize
{
	int m_row;
	int m_column;
	GGChessboardSize(int row=0, int column=0): m_row(row), m_column(column){}
};

struct GGChessboardCoord
{
	double m_x;
	double m_y;
	GGChessboardCoord(double x=0,double y=0): m_x(x), m_y(y) {}
	GGChessboardCoord(const GGChessboardCoord &other): GGChessboardCoord(other.m_x, other.m_y) {}
};

/*************************枚举 Start******************************/
// 棋盘的类型
enum GGChessboardType
{
	ChessBoardType_1515=1,	// 15*15
};

enum GGChessPiecesType
{
	ChessPiecesType_Black=1,	// 黑棋子
	ChessPiecesType_White=2,	// 白棋子
};

/*************************枚举 End******************************/

#endif // __GG_COMMON_H__
