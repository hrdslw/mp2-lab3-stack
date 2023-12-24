#include "../TStack/TCalc.h"

#include "gtest.h"

TEST(TCalc, can_create_calc_with_right_infix)
{
	TCalc calc("2+2");
	string str = "2+2";
	EXPECT_EQ(1, str == calc.GetInfix());
}

TEST(TCalc, can_set_infix)
{
	TCalc calc("3-3");
	string str = "2+2";
	calc.SetInfix(str);
	EXPECT_EQ(1, str == calc.GetInfix());
}

TEST(TCalc, can_summ)
{
	TCalc calc("2+2");
	EXPECT_EQ(4, calc.Calc());
}

TEST(TCalc, can_milt)
{
	TCalc calc("2*2");
	EXPECT_EQ(4, calc.Calc());
}

TEST(TCalc, can_div)
{
	TCalc calc("2/2");
	EXPECT_EQ(1, calc.Calc());
}

TEST(TCalc, can_sub)
{
	TCalc calc("2-2");
	EXPECT_EQ(0, calc.Calc());
}

TEST(TCalc, can_pow)
{
	TCalc calc("2^2");
	EXPECT_EQ(4, calc.Calc());
}


TEST(TCalc, can_correctly_calculate_no_postfix)
{
	TCalc calc("2^2+2*3-(1+2/2)");
	EXPECT_EQ(8, calc.Calc());
}

TEST(TCalc, can_correctly_calculate_long)
{
	TCalc calc("(2^2+2*3-(1+2/2)-100-(32-22))^2-0.1");
	EXPECT_EQ(10403.9, calc.Calc());
}