#ifndef __STACK_H__
#define __STACK_H__

typedef unsigned int telo;

class Stack
{
protected :
	int StackLen;		//����
	telo *pMem;			// ������
	int quElem;			// ���������� ���������
public:
	Stack(int len);
	~Stack();

	int GetLen();		// ��������� ����� �����
	int freeEl();		// ��������� ���-�� ���������� �����
	bool full();		// ��������� ���������� ���� ��������� ����� ��� ���

	void SetElem(const int n);  // �������� ������� � ����� �����
	int  GetElem() const;		//����� �������� �� ����� ,�������� ���
	int  GetClrElem() const;    //����� �������� �� ����� � ������� ���
};