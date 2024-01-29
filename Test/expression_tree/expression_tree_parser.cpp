#include "../pch.h"
#include "../../expression_tree/parsing.h"

using newton_ds::expression_tree::Node;
using newton_ds::expression_tree::parse;

TEST(ExpressionTreeParser, Parse_Value) {
	const std::string expression = "42";

	Node* result = parse(expression);
	EXPECT_EQ(result->getValue(), 42);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Add) {
	const std::string expression = "10+5";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 15);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Subtract) {
	const std::string expression = "10-5";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 5);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Multiply) {
	const std::string expression = "10*5";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 50);

	delete result;
}

 TEST(ExpressionTreeParser, Parse_Divide) {
	const std::string expression = "10/5";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 2);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Nested_1) {
	const std::string expression = "(10/5)+1";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 3);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Nested_2) {
	const std::string expression = "(10-5)*(2+3)";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 25);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Nested_3) {
	const std::string expression = "(10-5)*(2*(12-10))";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 20);

	delete result;
}

TEST(ExpressionTreeParser, Parse_Double_Brackets) {
	const std::string expression = "(((1+2)))";

	Node* result = parse(expression);

	result->calculate();
	EXPECT_EQ(result->getValue(), 3);

	delete result;
}

