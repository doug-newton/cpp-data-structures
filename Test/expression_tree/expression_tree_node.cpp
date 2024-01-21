#include "../pch.h"
#include "../../expression_tree/node.h"

using newton_ds::expression_tree::Node;
using newton_ds::expression_tree::Operator;

TEST(ExpressionTree_Node, Constructor_ValueOnly) {
	Node node(42);
	EXPECT_EQ(node.getValue(), 42);
}

TEST(ExpressionTree_Node, Operation_Basic) {
	Node node(
		new Node(32), Operator::ADD, new Node(64)
	);

	node.calculate();

	EXPECT_EQ(node.getValue(), 96);
}

TEST(ExpressionTree_Node, Operation_Nested) {
	Node node(
		new Node(32), Operator::ADD, new Node(
			new Node(7), Operator::MULTIPLY, new Node(3)
		)
	);

	node.calculate();

	EXPECT_EQ(node.getValue(), 53);
}

