#include "arithmetic.h"

Elem::~Elem()
{
	delete[] s; 
}
Elem(int typ1,string *s1,int index1)
{
	s=s1;
	typ=typ1;
	index=index1;
}
int Elem:: FillType()
{
	if ( Oper(s) )
		return 1;
	else if(isdigit(s))
		return 2;
	else if((s=='(')||(s==')'))
		return 3;
	else if((s=='.')||(s==','))
		return 4;
	else if(isalpha(s))//буква
		return 5;
	else 
		return 0;
}
double Elem::ElemDoub()
{}
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
bool corBracket(Elem *m)
{
	bool ToF=true
	Stack<char> st(m.Getlen()%4);
	for (int i=0;i<m.Getlen();i++)
		if (m[i].GetTyp()==4)
		{
			try
			{
			if m[i].GetE()=="(")
				st.SetElem(m[i].GetE());
			else
				st.GetClrElem();
			}
			catch(string s)
			{
				ToF=false;
				 cout << i << " Нет ( " << endl; 
			}
		}
		if (m.GetLen()-m.freeEl()!=0)
		{
			cout << i << " Нехватает ) " << endl;
			ToF=false;
		}
		return ToF;

}
bool corOper_no_min((string s))
{
	bool ToF=true;
	if ((m[0].GetTyp()==4)&&(m[i].GetE()!="-"))
		cout << 0 << " Нехватка аргументов" << endl;
			ToF=false;

	if ((m[m.Getlen()].GetTyp()==4)&&(m[i].GetE()!="-"))
		cout << 0 << "	Нехватка аргументов" << endl;
			ToF=false;

	for (int i=1;i<m.Getlen()-1;i++)
		{
			if (m[i].GetE()==1)
				if(m[i-1].GetTyp()==4)&&(m[i+1].GetTyp()==3)
					if (((m[i-2].GetTyp()==1)||(if (m[i+2].GetTyp()==1))&&(m[i].GetE()!="-"))) 
					{
						cout << i << " Две операции подрят " << endl;
								ToF=false;
					}

				else if (m[i+1].GetTyp()==3)
					if (((m[i-1].GetTyp()==1)||(if (m[i+2].GetTyp()==1))&&(m[i].GetE()!="-"))) 
					{
						cout << i << " Две операции подрят " << endl;
								ToF=false;
					}


				else (m[i-1].GetTyp()==4)
					if (((m[i-2].GetTyp()==1)||(if (m[i+1].GetTyp()==1))&&(m[i].GetE()!="-"))) 
					{
						cout << i << " Две операции подрят " << endl;
								ToF=false;
					}
		} 

	return ToF;

}
bool corCommas(string s)

{
	bool ToF=true;
	for (int i=1;i<m.Getlen()-1;i++)
		if ((m[i].GetTyp()==4)&&((if (m[i-1].GetTyp()==1)||(m[i+1].GetTyp()=3)||(m[i+1].GetTyp()==5)))
		{
			cout << i << " дробное число не коректо " << endl;
			ToF=false;
		}
	return ToF;
}
bool corkStr(char* s)
{
	if((corCommas(s))&&(corOper_no_min(s))
		return true;
	else
		return false;
}
int Prioritet(char s)
{
	int a
	switch(s)
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
