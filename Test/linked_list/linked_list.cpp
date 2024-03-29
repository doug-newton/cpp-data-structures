#include "../pch.h"
#include "../../linked_list/linked_list.h"

using newton_ds::linked_list::LinkedList;
using newton_ds::linked_list::Node;

TEST(LinkedList, Constructor) {
	LinkedList<int> list;

	EXPECT_EQ(list.head(), nullptr);
	EXPECT_EQ(list.tail(), nullptr);
}

TEST(LinkedList, Clear) {
	LinkedList<int> list;

	list.append(12);
	list.append(23);
	list.append(45);

	EXPECT_EQ(list.count(), 3);

	list.clear();

	EXPECT_EQ(list.count(), 0);
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

TEST(LinkedList, Find_Empty) {
	LinkedList<int> list;

	Node<int>* result = list.find(42);

	EXPECT_EQ(result, nullptr);
}

TEST(LinkedList, Find_Missing) {
	LinkedList<int> list;

	list.append(23);

	Node<int>* result = list.find(42);

	EXPECT_EQ(result, nullptr);
}

TEST(LinkedList, Find_Exists) {
	LinkedList<int> list;

	list.append(23);
	list.append(45);
	list.append(56);

	Node<int>* result = list.find(45);

	EXPECT_EQ(result->getValue(), 45);
}

TEST(LinkedList, Remove_NotExists) {
	LinkedList<int> list;

	list.append(12);
	list.remove(23);

	EXPECT_EQ(list.count(), 1);
	EXPECT_EQ(list.element_at(0)->getValue(), 12);
}

TEST(LinkedList, Remove_Only) {
	LinkedList<int> list;

	list.append(23);
	list.remove(23);

	EXPECT_EQ(list.count(), 0);
}

TEST(LinkedList, Remove_Middle) {
	LinkedList<int> list;

	list.append(12);
	list.append(23);
	list.append(34);

	list.remove(23);

	EXPECT_EQ(list.count(), 2);

	Node<int>* first = list.element_at(0);
	Node<int>* last = list.element_at(1);

	EXPECT_EQ(first->next(), last);
	EXPECT_EQ(last->prev(), first);
}

TEST(LinkedList, Remove_First) {
	LinkedList<int> list;

	list.append(12);
	list.append(23);
	list.append(34);

	list.remove(12);

	EXPECT_EQ(list.count(), 2);
	EXPECT_EQ(list.head()->getValue(), 23);
}

TEST(LinkedList, Remove_Last) {
	LinkedList<int> list;

	list.append(12);
	list.append(23);
	list.append(34);

	list.remove(34);

	EXPECT_EQ(list.count(), 2);
	EXPECT_EQ(list.tail()->getValue(), 23);
}

TEST(LinkedList, Iterator_Begin) {
	LinkedList<int> list;
	list.append(12);

	LinkedList<int>::iterator it = list.begin();

	EXPECT_EQ((*it)->getValue(), 12);
}

TEST(LinkedList, Iterator_End) {
	LinkedList<int> list;
	list.append(12);

	LinkedList<int>::iterator it = list.end();

	EXPECT_EQ(*it, nullptr);
}

TEST(LinkedList, Iterator_Forward) {
	LinkedList<int> list;

	list.append(1);
	list.append(2);
	list.append(3);

	int expected[]{ 1, 2, 3 };
	int actual[3];

	int i = 0;

	for (LinkedList<int>::iterator it = list.begin(); it != list.end(); ++it) {
		actual[i] = (*it)->getValue();
		i++;
	}

	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(actual[i], expected[i]);
	}
}

TEST(LinkedList, Iterator_Reverse) {
	LinkedList<int> list;

	list.append(1);
	list.append(2);
	list.append(3);

	int expected[]{ 3, 2, 1 };
	int actual[3];

	int i = 0;

	for (LinkedList<int>::iterator it = list.begin_reverse(); it != list.end(); --it) {
		actual[i] = (*it)->getValue();
		i++;
	}

	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(actual[i], expected[i]);
	}
}