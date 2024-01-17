#include "pch.h"
#include "../linked_list.h"

TEST(LinkedList, Constructor) {
	LinkedList<int> list;

	EXPECT_EQ(list.head(), nullptr);
	EXPECT_EQ(list.tail(), nullptr);
}

TEST(LinkedList, Count_Empty) {
	LinkedList<int> list;

	EXPECT_EQ(list.count(), 0);
}

TEST(LinkedList, Append_First) {
	LinkedList<int> list;

	list.append(23);

	EXPECT_FALSE(list.head() == nullptr);
	EXPECT_FALSE(list.tail() == nullptr);
	EXPECT_EQ(list.count(), 1);
}

TEST(LinkedList, Prepend_First) {
	LinkedList<int> list;

	list.prepend(23);

	EXPECT_FALSE(list.head() == nullptr);
	EXPECT_FALSE(list.tail() == nullptr);
	EXPECT_EQ(list.count(), 1);
}
