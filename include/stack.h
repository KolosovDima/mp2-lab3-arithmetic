#ifndef __TSTACK_H__
#define __TSTACK_H__

#include <iostream>

typedef unsigned int telo;

class Stack
{
protected :
	int StackLen;		//����
	int *pMem;			// ������
	int quElem;			// ���������� ���������
public:
	Stack(int len);
	~Stack();

	int GetLen()const;		// ��������� ����� �����
	int freeEl()const;		// ��������� ���-�� ���������� �����
	bool full()const;		// ��������� ���������� ���� ��������� ����� ��� ���

	void SetElem(const int n);  // �������� ������� � ����� �����
	int  GetElem() const;		//����� �������� �� ����� ,�������� ���
	int  GetClrElem() ;    //����� �������� �� ����� � ������� ���
};
#endif