#ifndef __TSTACK_H__
#define __TSTACK_H__

#include <iostream>
template <class T>

class Stack
{
protected :
	int StackLen;		//лина
	T *pMem;			// память
	int quElem;			// количество элементов
public:
	Stack(int len);
	~Stack();

	int GetLen()const;		// получение длины стэка
	int freeEl()const;		// получение кол-во свободного места
	bool full()const;		// получение рещультата стэк предельно занят или нет

	void SetElem(const T& n);  // добавить элемент в конец стэка
	T GetElem() const;		//взять значение из стека ,сохранив его
	T GetClrElem() ;    //взять значение из стека и удалить его
};
template <class T>
Stack<T>::Stack(int len)
{
	if (len<0)
		throw "Negative_lenght";
	else
	{
		StackLen=len;
		quElem=0;
		pMem= new T[StackLen];
		for (int i=0;i<StackLen;i++)
			pMem[i]=T();
	}
}
template <class T>
Stack<T>::~Stack()
{
	if (pMem!=NULL)
		delete []pMem;
}
template <class T>
int Stack<T>::GetLen() const
{
	return StackLen;
}
template <class T>
int Stack<T>::freeEl() const
{
	return (StackLen-quElem);
}
template <class T>
bool Stack<T>::full() const
{
	bool ToF=false;
		if (StackLen==quElem)
			ToF=true;
	return ToF;
}
template <class T>
void Stack<T>::SetElem(const T& n)
{
	if (true!=(*this).full())
	{
	(*this).pMem[quElem]=n;
	quElem=quElem+1;
	}
	else 
		throw "Full";

}
template <class T>
T Stack<T>::GetElem() const
{
	if ((*this).GetLen()!=(*this).freeEl())
		return (*this).pMem[quElem-1];
	else
		throw "Negative_lenght";

}
template <class T>
T Stack<T>::GetClrElem() 
{
	if ((*this).GetLen()!=(*this).freeEl())
	{
		T el;
		quElem=quElem-1;
		el=(*this).pMem[quElem];
		(*this).pMem[quElem]=0;
		return el;
	}
	else
		throw "Negative_lenght";
}
#endif