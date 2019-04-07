#include"../Table/Table.h"
#include"../Gtest/Gtest.h"
#include "../Table/Disordered.h"
TEST(Disordered, can_create_a_table)
{
	ASSERT_NO_THROW(Disordered A);
}

TEST(Disordered, can_insert_a_row)
{
	Disordered H;
	Polynom A;
	row r;
	r.data = &A;
	r.key = "Polynom1";
	ASSERT_NO_THROW(H.Insert(r));
}

TEST(Disordered, can_find_a_polynom)
{
	struct m* pol;
	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < 3; i++) {
		pol[i].c = i + 1;
		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	string s = "Polynom2";
	Polynom A(pol, 3);
	Polynom B;
	B = A;
	row r;
	r.data = &A;
	r.key = s;
	Disordered H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));

}

TEST(Disordered, can_not_find_a_missing_polynom)
{
	struct m* pol;
	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < 3; i++) {
		pol[i].c = i + 1;
		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	string s = "Polynom3";
	string s1 = "Polynom4";
	Polynom A(pol, 3);

	row r;
	r.data = &A;
	r.key = s;
	Disordered H;
	H.Insert(r);
	EXPECT_EQ(NULL, H.Search(s1));
}

TEST(Disordered, can_delete_a_polynom)
{
	struct m* pol;
	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < 3; i++) {
		pol[i].c = i + 1;
		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	string s = "Polynom4";

	Polynom A(pol, 3);
	Polynom B;
	B = A;
	row r;
	r.data = &A;
	r.key = s;
	Disordered H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));
	H.Delete(s);
	EXPECT_EQ(NULL, H.Search(s));
}