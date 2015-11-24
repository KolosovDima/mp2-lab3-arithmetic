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
public:
	int Getlen()const {return len};
	void provbracket(Elem *m)

}
bool Oper(char s); 
bool corOper_no_min((char s));