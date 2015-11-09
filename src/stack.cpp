#include "stack.h"
Stack::Stack(int len)
{
	if (len<0)
		throw "Negative_lenght";
	else
	{
		StackLen=len;
		quElem=0;
		pMem= new int[StackLen];
		for (int i=0;i<StackLen;i++)
			pMem[i]=0;
	}
}
Stack::~Stack()
{
	if (pMem!=NULL)
		delete []pMem;
}
int Stack::GetLen() const
{
	return StackLen;
}
int Stack::freeEl() const
{
	return (StackLen-quElem);
}
bool Stack::full() const
{
	bool ToF=true;
		if (StackLen==quElem)
			ToF=true;
	return ToF;
}
void Stack::SetElem(const int n)
{
	if (true!=(*this).full())
	{
	pMem[quElem]=n;
	quElem+=1;
	}
	else 
		throw "Full";

}
int Stack::GetElem() const
{
	if ((*this).GetLen()!=(*this).freeEl())
		return pMem[quElem-1];
	else
		throw "Negative_lenght";

}
int Stack::GetClrElem() 
{
	if ((*this).GetLen()!=(*this).freeEl())
	{
		int el;
		quElem=quElem-1;
		el=pMem[quElem];
		pMem[quElem]=0;
		return el;
	}
	else
		throw "Negative_lenght";
}