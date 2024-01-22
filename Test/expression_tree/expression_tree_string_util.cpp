#include "../pch.h"
#include "../../expression_tree/string_util.h"

using newton_ds::expression_tree::split_by_delim_outside_brackets;
using newton_ds::expression_tree::split_by_delim_result;
using newton_ds::expression_tree::split_by_operator;
using newton_ds::expression_tree::operator_split_result;

TEST(ExpressionTree_StringUtil, Split_Found) {
	std::string input = "12+345";

	split_by_delim_result result = split_by_delim_outside_brackets(input, '+');

	EXPECT_EQ(result.result, split_by_delim_result::OK);
	EXPECT_EQ(result.left, std::string("12"));
	EXPECT_EQ(result.right, std::string("345"));
}

TEST(ExpressionTree_StringUtil, Split_NotFound) {
	std::string input = "12+345";

	split_by_delim_result result = split_by_delim_outside_brackets(input, '-');

	EXPECT_EQ(result.result, split_by_delim_result::FAIL);
}

TEST(ExpressionTree_StringUtil, Split_OuterDelim) {
	std::string input = "12+(34+56)";

	split_by_delim_result result = split_by_delim_outside_brackets(input, '+');

	EXPECT_EQ(result.result, split_by_delim_result::OK);
	EXPECT_EQ(result.left, std::string("12"));
	EXPECT_EQ(result.right, std::string("(34+56)"));
}

TEST(ExpressionTree_StringUtil, Split_ByOperator) {
	std::string input = "12*(34+56)";

	operator_split_result result = split_by_operator(input);

	EXPECT_EQ(result.status, operator_split_result::FOUND);
	EXPECT_EQ(result.op, '*');
	EXPECT_EQ(result.left, std::string("12"));
	EXPECT_EQ(result.right, std::string("(34+56)"));
}