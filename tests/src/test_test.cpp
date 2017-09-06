#include "gtest/gtest.h"
#include "../coordinates.h"

#include <iostream>

class TestCoordinates : public ::testing::Test
{
protected:
	void SetUp()
	{
		coordinates = new Coordinates(5, 6);
	}
	void TearDown()
	{
		delete coordinates;
	}
	Coordinates *coordinates;
};

TEST_F(TestCoordinates, test1)
{
	ASSERT_EQ(coordinates->m_x, 5);
}

TEST_F(TestCoordinates, test2)
{
	ASSERT_EQ(coordinates->m_x, 5);
}

TEST_F(TestCoordinates, test3)
{
	ASSERT_EQ(coordinates->m_y, 6);
}

/*
class Foo
{
public:
	Foo()
		: i(0)
	{
		std::cout << "CONSTRUCTED" << std::endl;
	}
	~Foo()
	{
		std::cout << "DESTRUCTED" << std::endl;
	}
	int i;
};
*/



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}