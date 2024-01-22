#include "../pch.h"
#include "../../expression_tree/parsing.h"

using newton_ds::expression_tree::split_by_operator;
using newton_ds::expression_tree::operator_split_result;
using newton_ds::expression_tree::Operator;

TEST(ExpressionTree_StringUtil, Split_Found) {
	std::string input = "12+345";

	operator_split_result result = split_by_operator(input);

	EXPECT_EQ(result.status, operator_split_result::FOUND);
	EXPECT_EQ(result.op, Operator::ADD);
	EXPECT_EQ(result.left, std::string("12"));
	EXPECT_EQ(result.right, std::string("345"));
}

TEST(ExpressionTree_StringUtil, Split_NotFound) {
	std::string input = "12:345";

	operator_split_result result = split_by_operator(input);

	EXPECT_EQ(result.op, Operator::NONE);
	EXPECT_EQ(result.status, operator_split_result::NOT_FOUND);
}

TEST(ExpressionTree_StringUtil, Split_OuterDelim) {
	std::string input = "(34*56)-12";

	operator_split_result result = split_by_operator(input);

	EXPECT_EQ(result.status, operator_split_result::FOUND);
	EXPECT_EQ(result.op, Operator::SUBTRACT);
	EXPECT_EQ(result.left, std::string("(34*56)"));
	EXPECT_EQ(result.right, std::string("12"));
}