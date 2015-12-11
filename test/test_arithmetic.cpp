#include "arithmetic.h"
#include <gtest.h>

TEST(arithmetic, can_create_Elem)
{
  ASSERT_NO_THROW(Elem m);
}

TEST(arithmetic, can_create_Elem_with_string_and_type_and_bool)
{
	string s="s";
  ASSERT_NO_THROW(Elem m(4,s,true));
}

TEST(arithmetic, can_create_elem_with_string_and_type_and_bool)
{
	string s="s";
	Elem m2;
	Elem m1(4,s,true);
	m2=m1;
	EXPECT_EQ(m1.s,m2.s);
	EXPECT_EQ(m1.typ,m2.typ);
	EXPECT_EQ(m1.un,m2.un);
}
TEST(arithmetic, can_Fill_Type_Oper)
{
	string s="-";
	EXPECT_EQ(true,Oper(s[0]));
}
TEST(arithmetic, can_not_Fill_Type_not_Oper)
{
	string s="7";
	EXPECT_EQ(false,Oper(s[0]));
}
TEST(arithmetic, can_Fill_Type_Elem_Oper)
{
	string s="-";
	EXPECT_EQ(1,Oper(s[0]));
}
TEST(arithmetic, can_Fill_Type_Elem_Bracket)
{
	string s=")";
	EXPECT_EQ(3,FillType(s[0]));
}
TEST(arithmetic, can_Fill_Type_Elem_Number)
{
	string s="6";
	EXPECT_EQ(2,FillType(s[0]));
}
TEST(arithmetic, can_Fill_Type_Elem_Letter)
{
	string s="a";
	EXPECT_EQ(5,FillType(s[0]));
}
TEST(arithmetic, corBracket_no_error_Bracket)
{
	Elem m[6];
	string s1="(()())";
	for (int i=0;i<6;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	EXPECT_EQ(true ,corBracket(m,6));
}
TEST(arithmetic, corBracket_error_Bracket_right)
{
	Elem m[6];
	string s1="(()()(";
	for (int i=0;i<6;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	EXPECT_NE(true ,corBracket(m,6));
}
TEST(arithmetic, corBracket_error_Bracket_left)
{
	Elem m[6];
	string s1="(())))";
	for (int i=0;i<6;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	EXPECT_NE(true ,corBracket(m,6));
}
TEST(arithmetic, corMins_no_error_mins)
{
	Elem m[6];
	string s1="4+(-6)";
	for (int i=0;i<6;i++)
		m[i].s=s1[i];
	EXPECT_EQ(true ,corMins(m,6));
}
TEST(arithmetic, corMins_no_error_mins_start)
{
	Elem m[6];
	string s1="-4+(7)";
for (int i=0;i<6;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	UnaryMinus(m,6);
	EXPECT_EQ(true ,corMins(m,6));
}
TEST(arithmetic, corMins_error_mins_mid)
{
	Elem m[6];
	string s1="4-+(7)";
	for (int i=0;i<6;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	UnaryMinus(m,6);
	EXPECT_NE(true ,corMins(m,6));
}
TEST(arithmetic, corMins_error_mins_end)
{
	Elem m[6];
	string s1="4+(7)-";
for (int i=0;i<6;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	UnaryMinus(m,6);
	EXPECT_NE(true ,corMins(m,6));
}
TEST(arithmetic, corOper_error_oper_end)
{
	string s1="4+(7)+";
	EXPECT_NE(true ,corOper_no_mins(s1));
}
TEST(arithmetic, corOper_error_oper_start)
{
	string s1="*4+(7)";
	EXPECT_NE(true ,corOper_no_mins(s1));
}
TEST(arithmetic, corOper_no_error_oper)
{
	string s1="4+7+77";
	EXPECT_EQ(true ,corOper_no_mins(s1));
}
TEST(arithmetic, corOper_error_mid_oper)
{
	string s1="4+7++7";
	EXPECT_NE(true ,corOper_no_mins(s1));
}
TEST(arithmetic, corCommas_error_mid_Commas)
{
	string s1="4+.77";
	EXPECT_NE(true ,corCommas(s1));
}
TEST(arithmetic, corCommas_no_error_Commas)
{
	string s1="4+0.77";
	EXPECT_EQ(true ,corCommas(s1));
}
TEST(arithmetic, corCommas_error_end_Commas)
{
	string s1="4+77.";
	EXPECT_NE(true ,corCommas(s1));
}
TEST(arithmetic, corCommas_error_start_Commas)
{
	string s1=".4+77";
	EXPECT_NE(true ,corCommas(s1));
}
TEST(arithmetic, coninpostfix_all)
{
	Elem m[11];
	Elem m2[11];
	int a=11;
	string s1="4+(7)-6^8*7";
	string s2="47+68^7*-";

for (int i=0;i<a;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	UnaryMinus(m,a);
	ConInPostfix(m,m2,a);
for (int i=0;i<a;i++)
	{
		m[i].s=s2[i];
		m[i].typ=FillType(s2[i]);
	}

	for (int i=0;i<a;i++)
	{ 
		EXPECT_EQ(m2[i].s ,m[i].s );
	}
}
TEST(arithmetic, opn)
{
	Elem m[9];
	Elem m2[9];
	int a=9;
	string s1="4+7-2^2*4";

for (int i=0;i<a;i++)
	{
		m[i].s=s1[i];
		m[i].typ=FillType(s1[i]);
	}
	UnaryMinus(m,6);
	ConInPostfix(m,m2,a);
	for (int i=0;i<a;i++)

	EXPECT_EQ(-5 ,OPN(m2,a) );
}