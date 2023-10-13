#ifndef __GG_GLOBAL_VARIABLE_H__
#define __GG_GLOBAL_VARIABLE_H__

/**
 * ȫ����ر���
 */


class GGGlobalVariable
{
public:
	~GGGlobalVariable();

	static GGGlobalVariable* instance() {
		static GGGlobalVariable* ins=new GGGlobalVariable();
		return ins;
	}

public:


private:
	GGGlobalVariable();
	GGGlobalVariable(const GGGlobalVariable& other)=delete;
	void operator=(const GGGlobalVariable& other)=delete;
	GGGlobalVariable(GGGlobalVariable&& other)=delete;
};


#endif // !__GG_GLOBAL_VARIABLE_H__

