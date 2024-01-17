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
