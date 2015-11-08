#ifndef __STACK_H__
#define __STACK_H__

typedef unsigned int telo;

class stack
{
protected :
	int StackLen;
	telo *pMem;
	int quElem;
	int free;
private :
	void SetMem(telo &pMem, int StackLen );
public:
	TBitField(int len);
	~TBitField();

	int free();
	int full();

	void SetElem(const int n);
	int  GetBit(const int n) const;
	int  GetClrBit(const int n) const;
};