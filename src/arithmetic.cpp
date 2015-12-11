#include <iostream>
#include <string>
#include "arithmetic.h"
#include "stack.h"
#include <cmath>
#include <cstdlib>
using namespace std;

Elem::Elem()
{
	s="0";
	typ=0;
	un=false;
}
Elem::~Elem()
{}
void Elem::operator=(const Elem m2)
{
	s=m2.s;
	typ=m2.typ;
	un=m2.un;
}
Elem::Elem(int typ1,string s1, bool un2)
{
	s=s1;
	typ=typ1;
	un=un2;

}
int FillType(char s)
{
	if ( Oper(s) )
		return 1;
	else if(isdigit(s))
		return 2;
	else if((s=='(')||(s==')'))
		return 3;
	else if((s=='.')||(s==','))
		return 2;
	else if(isalpha(s))//буква
		return 5;
	else 
		return 0;
}
bool Oper(char s)//Операции
{
	bool flag=false;
	char sign[]="-+*/^";
	for(int i=0;i<7;i++)
		if (s==sign[i])
		{
			flag=true;
			break;
		}
	return flag;
}
bool corBracket(Elem *m,int k)
{
	bool ToF=true;
	Elem a;
	string s2="()";
	Stack<Elem> st(k/2);
	for (int i=0;i<k;i++)
		if (m[i].GetTyp()==3)
		{
			try
			{
			if (m[i].s[0]==s2[0])
				st.SetElem(m[i]);
			if (m[i].s[0]==s2[1])
				a=st.GetClrElem();
			}
			catch(...)
			{
				ToF=false;
				 cout << "место " << i << " Нет ( " << endl; 
			}
		}
	if (st.GetLen()-st.freeEl()!=0)
		{
			cout << " Нехватает ) " << endl;
			ToF=false;
		}
	return ToF;

}
bool corMins(Elem *m,int k)
{
	bool ToF=true;
	string s2="-)";
	for (int i=0;i<k-1;i++)
		if ((m[i].s[0]==s2[0])&&(m[i+1].s[0]==s2[1]))
		{
			cout << "место " << i << " - ) не хватает аргумента  " << endl;
			ToF=false;
		}
	for (int i=1;i<k-1;i++)
		if ((m[i].s[0]==s2[0])&&((m[i-1].GetTyp()==1)||(m[i+1].GetTyp()==1)))
		{
			cout << "место " << i << "две операции подрят " << endl;
			ToF=false;
		}
	if (m[k-1].s[0]==s2[0])
		{
			cout <<"конец строки, нехватка аргумента " << endl;
			ToF=false;
		}
	return ToF;
}
bool corOper_no_mins(string s)
{
	bool ToF=true;
	string s2="-+";
	for (int i=0;i<(s.length()-1);i++)
		if ((FillType(s[i])==1)&&((FillType(s[i+1])==1)&&(s[i]!=s[0])))
		{
			cout << "место " << i << " Две операции подрят " << endl;
			ToF=false;
		}
	if (FillType(s[s.length()-1])==1)
		{
			cout <<"конец строки, нехватка аргумента " << endl;
			ToF=false;
		}
	if ((FillType(s[0])==1)&&(s[0]!=s[1]))
		{
			cout <<"начало строки, нехватка аргумента " << endl;
			ToF=false;
		}
	for (int i=1;i<(s.length()-1);i++)
		if (((FillType(s[i])==2)||(FillType(s[i+1])==5))&&(FillType(s[i+1])==3))
		{
			int j=i;
			while((FillType(s[j+1])==3)||(j<(s.length()-1)))
				j++;
			if ((FillType(s[j+1])!=3)&&(FillType(s[j+1])!=1))
			{
				cout << "место " << i << " нет операций " << endl;
				ToF=false;
			}
		}

	return ToF;

}
bool corCommas(string s)

{
	string s2=".,";
	bool ToF=true;
<<<<<<< HEAD
	if ((s[0]==s2[0])||(s[0]==s2[1]))
	{
		cout << 0 << " Нехватка аргументов" << endl;
			ToF=false;
	}
	if ((s[s.length()-1]==s2[0])||(s[s.length()-1]==s2[1]))
	{
		cout << 0 << "	Нехватка аргументов" << endl;
			ToF=false;
	}
	for (int i=1;i<(s.length()-1);i++)
		if (((s[i]==s2[0])||(s[i]==s2[1]))&&((FillType(s[i-1])==1)||(FillType(s[i+1])==3) ||(FillType(s[i+1])==5)))

		{
			cout << "место " << i << " дробное число не коректо " << endl;
			ToF=false;
		}
	return ToF;
}

void ConInPostfix( Elem *m1,Elem *m2,int &ln)
{
	int sh=0;
	string s2="()";
	Stack<Elem> st(ln);
	for(int i=0;i<ln;i++)
	{
		if (m1[i].s[0]==s2[0])
			st.SetElem(m1[i]);
		if (m1[i].s[0]==s2[1])
		{
			Elem a=st.GetClrElem();
			while (a.s[0]!=s2[0])
			{
				m2[sh]=a;
				sh++;
				a=st.GetClrElem();
			}
		}
		if ((m1[i].GetTyp()==2)||(m1[i].GetTyp()==5))
		{
			m2[sh]=m1[i];
			sh++;
		}
		if (m1[i].GetTyp()==1)
		{
			if(st.GetLen()-st.freeEl()==0)
				st.SetElem(m1[i]);
			else
			{
				Elem a=st.GetElem();
				while(Prioritet(m1[i])<=Prioritet(a))
				{
					m2[sh]=st.GetClrElem();
					sh++;
					if(st.GetLen()-st.freeEl()!=0)
						a=st.GetElem();
					else
						a.s="(";
				}
				st.SetElem(m1[i]);
			}
		}
	}
	while(st.GetLen()-st.freeEl()!=0)
	{
		m2[sh]=st.GetClrElem();;
		sh++;
	}
	ln=sh;
}
void Variable (Elem *m2,int ln)
{
	string a;
	for(int i=0;i<ln;i++)
	{
		if(m2[i].typ==5)
		{
			cout<< m2[i].s << "=";
			cin >> a;
			for(int j=i+1;j<ln;j++)
				if (m2[j].s==m2[i].s)
				{
					m2[j].s=a;
					m2[j].typ=2;
				}
			m2[i].s=a;
			m2[i].typ=2;
		}
	}
}
void UnaryMinus(Elem *m1,int ln)
{
	string s2="-(";
	if(m1[0].s[0]==s2[0])
		m1[0].un=true;
	for(int i=1;i<ln;i++)
		if((m1[i].s[0]==s2[0])&&(m1[i-1].s[0]==s2[1]))
			m1[i].un=true;
}
void UnaryPlus(Elem *m1,int ln)
{
	string s2="+(";
	if(m1[0].s[0]==s2[0])
		m1[0].un=true;
	for(int i=1;i<ln;i++)
		if((m1[i].s[0]==s2[0])&&(m1[i-1].s[0]==s2[1]))
			m1[i].un=true;
}
double OPN(Elem *m2,int ln)
{
	double a,b,rez;
	string s="-";
	Stack<double> st(ln);
	
	for(int i=0;i<ln;i++)
	{
		if (m2[i].typ==2)
		{
			double z;
			char x[254];
			for(int j=0;j<m2[i].s.length();j++)
				x[j]=m2[i].s[j];
			z=atof(x);
			st.SetElem(z);
		}
		if ((m2[i].typ==1)&&(m2[i].un!=true))
		{
			rez=0;
			b=st.GetClrElem();
			a=st.GetClrElem();
			switch(m2[i].s[0])
			{
				case '+':{rez=a+b;break;}
				case '-':{rez=a-b;break;}
				case '*':{rez=a*b;break;}
				case '/':{rez=a/b;break;}
				case '^':{rez=pow(a,b);break;}
			}
			st.SetElem(rez);
		}
		if ((m2[i].typ==1)&&(m2[i].un==true))
			if (m2[i].s[0]==s[0])
			{
				rez=(-st.GetClrElem());
				st.SetElem(rez);
			}
			else
			{
				rez=st.GetClrElem();
				st.SetElem(rez);
			}
	}
	return st.GetClrElem();
	
}
int Prioritet(Elem l)
{
	int a;
	switch(l.s[0])
	{
		case '(':{a=0;break;}
		case '+':{a=1;break;}
		case '-':{a=1;break;}
		case '*':{a=2;break;}
		case '/':{a=2;break;}
		case '^':{a=3;break;}
	}
	return a;
}
