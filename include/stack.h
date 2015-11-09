#ifndef __TSTACK_H__
#define __TSTACK_H__

#include <iostream>

typedef unsigned int telo;

class Stack
{
protected :
	int StackLen;		//лина
	int *pMem;			// память
	int quElem;			// количество элементов
public:
	Stack(int len);
	~Stack();

	int GetLen()const;		// получение длины стэка
	int freeEl()const;		// получение кол-во свободного места
	bool full()const;		// получение рещультата стэк предельно занят или нет

	void SetElem(const int n);  // добавить элемент в конец стэка
	int  GetElem() const;		//взять значение из стека ,сохранив его
	int  GetClrElem() ;    //взять значение из стека и удалить его
};
#endif