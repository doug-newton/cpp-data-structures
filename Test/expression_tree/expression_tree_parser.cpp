#include "../pch.h"
#include "../../expression_tree/parser.h"

using newton_ds::expression_tree::Node;
using newton_ds::expression_tree::Parser;

TEST(ExpressionTreeParser, Parse_Value) {
	const std::string expression = "42";

	Node* result = Parser::parse(expression);
	EXPECT_EQ(result->getValue(), 42);

	delete result;
}
TEST(ExpressionTreeParser, Parse_Add) {
	const std::string expression = "10+5";

	Node* result = Parser::parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 15);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Subtract) {
	const std::string expression = "10-5";

	Node* result = Parser::parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 5);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Multiply) {
	const std::string expression = "10*5";

	Node* result = Parser::parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 50);

	delete result;
}

 TEST(ExpressionTreeParser, Parse_Divide) {
	const std::string expression = "10/5";

	Node* result = Parser::parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 2);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Nested) {
	const std::string expression = "(10/5)+1";

	Node* result = Parser::parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 3);

	delete result;
}

