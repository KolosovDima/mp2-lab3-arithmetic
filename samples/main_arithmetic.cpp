#include <iostream>
#include <string>
#include "arithmetic.h"
using namespace std;

int main()
{
	int len,k;
	double sum;
	bool cor=false;
	int lenm=0;
    string st;
	Elem str[254];
	Elem str2[254];
	
	setlocale(LC_ALL, "Russian");
	k=0;
	 while (cor!=true)
	 {
		cout<< "¬ведите выражение" << endl;
		cin>> st;
		cor=true;
		len=st.length();
		 for(int i=0; i<len-1;i++)
		{ 
			 k+=1;
			if((FillType(st[i])==3)&&(FillType(st[i+1])==3))
			 {
				 str[lenm].s=st.substr(i+1-k,k);
				 str[lenm].typ=3;
				 lenm++;
				 k=0;
			 }
			else if(FillType(st[i])!=FillType(st[i+1]))
			 {
				 str[lenm].s=st.substr(i+1-k,k);
				 str[lenm].typ=FillType(st[i]);
				 lenm++;
				 k=0;
			 }
		 }
		 k+=1;
			 str[lenm].s=st.substr(len-k,k);
			 str[lenm].typ=FillType(st[len-1]);
			 lenm++;
		if (corBracket(str,lenm)!=true)
			cor=false;
		if (corOper_no_mins(st)!=true)
			cor=false;
		if (corCommas(st)!=true)
			cor=false;
		if (corMins(str,lenm)!=true)
			cor=false;
	}
	 UnaryMinus(str2,lenm);
	 UnaryPlus(str2,lenm);
	 ConInPostfix(str,str2,lenm);
	 Variable(str2,lenm);
	 sum=OPN(str2,lenm);
	cout << "ќтвет" << sum;

}