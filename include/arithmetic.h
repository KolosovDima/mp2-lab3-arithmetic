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
	public:
	string s;
	int typ;
	bool un;
	Elem();
	Elem(int typ1,string s1, bool un2);
	~Elem();
	int GetTyp()const {return typ;};
	void operator=(const Elem m2);
};
int FillType(char s);
bool corBracket(Elem *m,int k);
bool corMins(Elem *m,int k);
bool Oper(char s); 
bool corCommas(string s);
bool corOper_no_mins(string s);
void ConInPostfix(Elem *m1,Elem *m2,int &ln);
void UnaryMinus(Elem *m1,int ln);
int Prioritet(Elem l);
void UnaryPlus(Elem *m1,int ln);
void Variable (Elem *m2,int ln);
void UnaryMinus(Elem *m1,int ln);
double OPN(Elem *m2,int ln);
#endif