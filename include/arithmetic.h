#ifndef __ARITHIMETIC_H__
#define __ARITHIMETIC_H__

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "stack.h"

using namespace std;
class Elem
{
private:
	string *s;
	int typ;
	int index;
public:
	Elem();
	Elem(int typ,string *s1);
	~Elem();
	string GetE(){return s};
	int GetTyp()const {return typ};
	void FillType();
}
class mas
{
private:
	Elem *yr;
	int len;
	bool Oper(Elem* m); 
	bool corOper_no_min((Elem* m));
	bool provbracket(Elem *m)
public:
	int Getlen()const {return len};
	bool corkStr(Elem* m)

}
