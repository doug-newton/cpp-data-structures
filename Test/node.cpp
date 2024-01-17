#include "pch.h"
#include "../node.h"

TEST(Node, Constructor) {
	Node<int> n(42);
	EXPECT_EQ(n.getValue(), 42);
}