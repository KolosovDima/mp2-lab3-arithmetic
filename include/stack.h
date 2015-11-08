#ifndef __STACK_H__
#define __STACK_H__

typedef unsigned int telo;

class Stack
{
protected :
	int StackLen;		//лина
	telo *pMem;			// память
	int quElem;			// количество элементов
public:
	Stack(int len);
	~Stack();

	int GetLen();		// получение длины стэка
	int freeEl();		// получение кол-во свободного места
	bool full();		// получение рещультата стэк предельно занят или нет

	void SetElem(const int n);  // добавить элемент в конец стэка
	int  GetElem() const;		//взять значение из стека ,сохранив его
	int  GetClrElem() const;    //взять значение из стека и удалить его
};