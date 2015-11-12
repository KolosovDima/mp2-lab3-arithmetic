#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_Stack_with_positive_length)
{
ASSERT_NO_THROW (Stack<int> st(3));
}
TEST(TBitField, throws_when_create_Stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> bf(-3));
}
TEST(Stack, can_get_length)
{
  Stack<int> st(3);

  EXPECT_EQ(3, st.GetLen());
}

TEST(Stack, throws_when_full)
{
  Stack<int> st(2);

  st.SetElem(3);
  st.SetElem(3);

  ASSERT_ANY_THROW(st.SetElem(3));
}
TEST(Stack, throws_when_all_free)
{
  Stack<int> st(2);

  ASSERT_ANY_THROW(st.GetElem());
}
TEST(Stack, throws_when_del_all_free)
{
  Stack<int> st(2);

  ASSERT_ANY_THROW(st.GetClrElem());
}
TEST(Stack,can_set_Elem)
{
	Stack<int> st(3);

	st.SetElem(3);

	EXPECT_NE(0, st.GetElem());
}

TEST(Stack, can_get_no_clean_Elem)
{
	int a;
	Stack<int> st(3);

	st.SetElem(3);
	
	a=st.GetElem();

	EXPECT_EQ(3, a);
	EXPECT_EQ(3, st.GetElem());
}
TEST(Stack, can_get_and_clean_Elem)
{
	int a;
	Stack<int> st(3);

	st.SetElem(2);
	st.SetElem(3);
	
	a=st.GetClrElem();

	EXPECT_EQ(3, a);
	EXPECT_EQ(2, st.GetElem());
}
TEST(Stack, can_get_free_cell)
{
	Stack<int> st(3);

	st.SetElem(3);

	EXPECT_EQ(2, st.freeEl());

}
TEST(Stack, compare_stack_full_return_true)
{
	Stack<int> st(3);

	st.SetElem(1);
	st.SetElem(2);
	st.SetElem(3);

	EXPECT_TRUE(true == st.full());
}