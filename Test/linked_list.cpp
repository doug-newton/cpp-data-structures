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

TEST(LinkedList, Append_Subsequent) {
	LinkedList<int> list;

	list.append(23);
	list.append(45);

	EXPECT_EQ(list.count(), 2);

	EXPECT_EQ(list.head()->getValue(), 23);
	EXPECT_EQ(list.head()->next()->getValue(), 45);

	EXPECT_EQ(list.tail()->getValue(), 45);
	EXPECT_EQ(list.tail()->prev()->getValue(), 23);
}

TEST(LinkedList, Prepend_First) {
	LinkedList<int> list;

	list.prepend(23);

	EXPECT_FALSE(list.head() == nullptr);
	EXPECT_FALSE(list.tail() == nullptr);
	EXPECT_EQ(list.count(), 1);
}

TEST(LinkedList, Prepend_Subsequent) {
	LinkedList<int> list;

	list.prepend(23);
	list.prepend(45);

	EXPECT_EQ(list.count(), 2);

	EXPECT_EQ(list.head()->getValue(), 45);
	EXPECT_EQ(list.head()->next()->getValue(), 23);

	EXPECT_EQ(list.tail()->getValue(), 23);
	EXPECT_EQ(list.tail()->prev()->getValue(), 45);
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
