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
	TBitField(int len);
	~TBitField();

	int GetLen();		// ��������� ����� �����
	int freeEl();		// ��������� ���-�� ���������� �����
	bool full();		// ��������� ���������� ���� ��������� ����� ��� ���

	void SetElem(const int n);  // �������� ������� � ����� �����
	int  GetElem() const;		//����� �������� �� ����� ,�������� ���
	int  GetClrElem() const;    //����� �������� �� ����� � ������� ���
};