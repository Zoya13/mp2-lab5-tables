// Tests.cpp: определяет точку входа для консольного приложения.
//



#include"../Gtest/Gtest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
