#include "pch.h"
#include "../node.h"

TEST(Node, Constructor) {
	Node<int> n(42);
	EXPECT_EQ(n.getValue(), 42);
}

TEST(Node, Append) {
	Node<int> n1(23);
	Node<int> n2(34);

	n1.append(&n2);

	EXPECT_EQ(n1.next(), &n2);
	EXPECT_EQ(n2.prev(), &n1);
}

TEST(Node, Append_Null) {
	Node<int> n1(23);

	n1.append(nullptr);

	EXPECT_EQ(n1.next(), nullptr);
}

TEST(Node, Prepend) {
	Node<int> n1(23);
	Node<int> n2(34);

	n1.prepend(&n2);

	EXPECT_EQ(n2.next(), &n1);
	EXPECT_EQ(n1.prev(), &n2);
}

TEST(Node, Prepend_Null) {
	Node<int> n1(23);

	n1.prepend(nullptr);

	EXPECT_EQ(n1.prev(), nullptr);
}

