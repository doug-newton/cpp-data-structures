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

TEST(LinkedList, ElementAt_Empty) {
	LinkedList<int> list;

	Node<int>* result = list.element_at(5);

	EXPECT_EQ(result, nullptr);
}

TEST(LinkedList, ElementAt_OutOfRange) {
	LinkedList<int> list;

	list.append(23);
	list.append(34);

	Node<int>* result = list.element_at(2);

	EXPECT_EQ(result, nullptr);
}

TEST(LinkedList, ElementAt_Valid) {
	LinkedList<int> list;

	list.append(23);
	list.append(34);

	Node<int>* result = list.element_at(1);

	EXPECT_FALSE(result == nullptr);
	EXPECT_EQ(result->getValue(), 34);
}
