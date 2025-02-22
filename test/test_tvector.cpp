#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);
	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	TVector<int> v1(v);
	EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	TVector<int> v1(v);
	v[0] = 1;
	EXPECT_NE(1, v1[0]);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(10);
	EXPECT_EQ(10, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(10, 5);
	EXPECT_EQ(5, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(10);
	v[0] = 5;
	EXPECT_EQ(5, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(10);
	ASSERT_ANY_THROW(v[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[10]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10), v1(10);
	v[5] = 5;
	v1 = v;
	v = v;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(5), v1(5);
	v1[0] = 1;
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(5), v1(10);
	v = v1;
	EXPECT_EQ(v.GetSize(), 10);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5), v1(10);
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(5), v1(5);
	EXPECT_TRUE(v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);
	EXPECT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5), v1(10);
	EXPECT_TRUE(v != v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(5), v2(5), v3;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	v3 = v1 + 1;
	EXPECT_EQ(v2, v3);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(5), v2(5), v3;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	v3 = v2 - 1;
	EXPECT_EQ(v1, v3);

}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(5), v2(5), v3;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	v3 = v1 * 2;
	EXPECT_EQ(v2, v3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	v3 = v1 + v2;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 2;
	}
	EXPECT_EQ(v1, v3);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(5), v1(10);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v3 = v1 - v2;
	EXPECT_EQ(v2, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5), v1(10);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5);
	int mul = 0;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	mul = v1 * v2;
	EXPECT_EQ(5, mul);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(5), v1(10);
	ASSERT_ANY_THROW(v * v1);
}