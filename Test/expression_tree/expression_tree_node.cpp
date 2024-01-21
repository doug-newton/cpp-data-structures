#include "../pch.h"
#include "../../expression_tree/node.h"

using newton_ds::expression_tree::Node;

TEST(ExpressionTree_Node, Constructor_ValueOnly) {
	Node node(42);
	EXPECT_EQ(node.getValue(), 42);
}
