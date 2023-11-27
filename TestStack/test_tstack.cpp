#include "../TStack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, can_get_size)
{
  TStack<int> s(10);

  EXPECT_EQ(s.Size(), 10);
}

TEST(TStack, new_stack_is_empty)
{
  TStack<int> s(5);

  EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, can_assign_stack)
{
	TStack<int> s(10);
	TStack<int> s1(5);

	s1.Push(4);
	s1.Push(5);

	s = s1;




  
}

TEST(TStack, can_clear_bit)
{
  TStack<int> bf(10);

}

TEST(TStack, throws_when_create_bitfield_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> bf(-3));
}

TEST(TStack, throws_when_set_bit_with_negative_index)
{
  TStack<int> bf(10);

 
}

TEST(TStack, throws_when_set_bit_with_too_large_index)
{
  TStack<int> bf(10);

  
}

TEST(TStack, throws_when_get_bit_with_negative_index)
{
  TStack<int> bf(10);

  
}

TEST(TStack, throws_when_get_bit_with_too_large_index)
{
  TStack<int> bf(10);

  
}

TEST(TStack, throws_when_clear_bit_with_negative_index)
{
  TStack<int> bf(10);

  
}

TEST(TStack, throws_when_clear_bit_with_too_large_index)
{
  TStack<int> bf(10);

  
}

TEST(TStack, can_assign_bitfields_of_equal_size)
{
  const int size = 2;
  TStack<int> bf1(size), bf2(size);
  
}

TEST(TStack, assign_operator_changes_bitfield_size)
{
  const int size1 = 2, size2 = 5;
  TStack<int> bf1(size1), bf2(size2);
  
}

TEST(TStack, can_assign_bitfields_of_non_equal_size)
{
  const int size1 = 2, size2 = 5;
  TStack<int> bf1(size1), bf2(size2);

}

TEST(TStack, compare_equal_bitfields_of_equal_size)
{
  const int size = 2;
  TStack<int> bf1(size), bf2(size);
  
}

TEST(TStack, or_operator_applied_to_bitfields_of_equal_size)
{
  const int size = 4;
  TStack<int> bf1(size), bf2(size), expBf(size);
  
}

TEST(TStack, or_operator_applied_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TStack<int> bf1(size1), bf2(size2), expBf(size2);
  
}

TEST(TStack, and_operator_applied_to_bitfields_of_equal_size)
{
  const int size = 4;
  TStack<int> bf1(size), bf2(size), expBf(size);
  
}

TEST(TStack, and_operator_applied_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TStack<int> bf1(size1), bf2(size2), expBf(size2);
  
}

TEST(TStack, can_invert_bitfield)
{
  const int size = 2;
  TStack<int> bf(size), negBf(size), expNegBf(size);
  
}

TEST(TStack, can_invert_large_bitfield)
{
  const int size = 38;
  TStack<int> bf(size), negBf(size), expNegBf(size);
  
}

TEST(TStack, invert_plus_and_operator_on_different_size_bitfield)
{
  const int firstSze = 4, secondSize = 8;
  TStack<int> firstBf(firstSze), negFirstBf(firstSze), secondBf(secondSize), testBf(secondSize);
  
}

TEST(TStack, can_invert_many_random_bits_bitfield)
{
  const int size = 38;
  TStack<int> bf(size), negBf(size), expNegBf(size);

  
}

TEST(TStack, bitfields_with_different_bits_are_not_equal)
{
  const int size = 4;
  TStack<int> bf1(size), bf2(size);

  }
