#ifndef __GG_COMMON_H__
#define __GG_COMMON_H__

#include <string>

/*************************�궨�� Start******************************/
#define GG_GAME_TIMEKEEPING			600		// ���ÿ����ʱ��Ϊ600s

/*************************�궨�� Start******************************/

/*************************ö�ٶ��� Start******************************/
// ���̵�����
enum GGChessboardType
{
	ChessBoardType_1515=1,	// 15*15
};

// ��������
enum GGChessPiecesType
{
	ChessPiecesType_Black=1,	// ������
	ChessPiecesType_White=2,	// ������
};

// ��������
enum GGRoleType
{
	RoleType_Black=1,	// �ڷ�
	RoleType_White=2,	// �׷�
};

// �����Ա�
enum GGRoleGender
{
	RoleGender_Man=0,		// ��
	RoleGender_Woman=1,		// Ů
};

// ��Ϸ���
enum GGGameResult
{
	GameResult_None=-1,		// ��ʼ��
	GameResult_Victory=0,	// ʤ��
	GameResult_Failure=1,	// ʧ��
};
/*************************ö�ٶ��� End******************************/

/*************************���ݶ��� Start****************************/
// ���̴�С
struct GGChessboardSize
{
	int m_row;
	int m_column;
	GGChessboardSize(int row=0, int column=0): m_row(row), m_column(column){}
};

// ���̽�������
struct GGChessboardCoord
{
	double m_x;
	double m_y;
	GGChessboardCoord(double x=0,double y=0): m_x(x), m_y(y) {}
	GGChessboardCoord(const GGChessboardCoord &other): GGChessboardCoord(other.m_x, other.m_y) {}
};

// ��Ϸ��ɫ
struct GGGameRole
{
	int				m_timekeeping;			// ��ʱ
	bool			m_isTimekeeping;		// �Ƿ����ü�ʱ
	GGRoleType		m_roleType;				// ��ɫ����
	GGRoleGender	m_roleGender;			// ��ɫ�Ա�
	GGGameResult	m_gameResult;			// ��Ϸ���
	std::string		m_roleName;				// ��ɫ����
	std::string		m_headPortrait;			// ͷ��·��
	GGGameRole(GGRoleType roleType=RoleType_Black, GGRoleGender roleGender=RoleGender_Man, 
		const std::string &roleName="",const std::string& headPortrait="",bool isTimekeeping=true,int timekeeping=GG_GAME_TIMEKEEPING,
		GGGameResult gameResult=GameResult_None)
		: m_roleType(roleType), m_roleGender(roleGender), m_roleName(roleName), m_headPortrait(headPortrait),
		  m_isTimekeeping(isTimekeeping), m_timekeeping(timekeeping),m_gameResult(gameResult)
		{}
};
/**************************���ݶ��� End****************************/


#endif // __GG_COMMON_H__
