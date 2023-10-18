#ifndef __GG_COMMON_H__
#define __GG_COMMON_H__

#include <string>

/*************************宏定义 Start******************************/
#define GG_GAME_TIMEKEEPING			600		// 玩家每局总时间为600s

/*************************宏定义 Start******************************/

/*************************枚举定义 Start******************************/
// 棋盘的类型
enum GGChessboardType
{
	ChessBoardType_1515=1,	// 15*15
};

// 棋子类型
enum GGChessPiecesType
{
	ChessPiecesType_Black=1,	// 黑棋子
	ChessPiecesType_White=2,	// 白棋子
};

// 人物类型
enum GGRoleType
{
	RoleType_Black=1,	// 黑方
	RoleType_White=2,	// 白方
};

// 人物性别
enum GGRoleGender
{
	RoleGender_Man=0,		// 男
	RoleGender_Woman=1,		// 女
};

// 游戏结果
enum GGGameResult
{
	GameResult_None=-1,		// 初始化
	GameResult_Victory=0,	// 胜利
	GameResult_Failure=1,	// 失败
};
/*************************枚举定义 End******************************/

/*************************数据定义 Start****************************/
// 棋盘大小
struct GGChessboardSize
{
	int m_row;
	int m_column;
	GGChessboardSize(int row=0, int column=0): m_row(row), m_column(column){}
};

// 棋盘交点坐标
struct GGChessboardCoord
{
	double m_x;
	double m_y;
	GGChessboardCoord(double x=0,double y=0): m_x(x), m_y(y) {}
	GGChessboardCoord(const GGChessboardCoord &other): GGChessboardCoord(other.m_x, other.m_y) {}
};

// 游戏角色
struct GGGameRole
{
	int				m_timekeeping;			// 计时
	bool			m_isTimekeeping;		// 是否启用计时
	GGRoleType		m_roleType;				// 角色类型
	GGRoleGender	m_roleGender;			// 角色性别
	GGGameResult	m_gameResult;			// 游戏结果
	std::string		m_roleName;				// 角色名称
	std::string		m_headPortrait;			// 头像路径
	GGGameRole(GGRoleType roleType=RoleType_Black, GGRoleGender roleGender=RoleGender_Man, 
		const std::string &roleName="",const std::string& headPortrait="",bool isTimekeeping=true,int timekeeping=GG_GAME_TIMEKEEPING,
		GGGameResult gameResult=GameResult_None)
		: m_roleType(roleType), m_roleGender(roleGender), m_roleName(roleName), m_headPortrait(headPortrait),
		  m_isTimekeeping(isTimekeeping), m_timekeeping(timekeeping),m_gameResult(gameResult)
		{}
};
/**************************数据定义 End****************************/


#endif // __GG_COMMON_H__
