#include "../pch.h"
#include "../../expression_tree/string_util.h"

using newton_ds::expression_tree::StringUtil;
using newton_ds::expression_tree::SplitResult;

TEST(ExpressionTree_StringUtil, Split_Found) {
	std::string input = "12+345";

	SplitResult result = StringUtil::split(input, '+');

	EXPECT_EQ(result.result, SplitResult::ResultValue::OK);
	EXPECT_EQ(result.left, std::string("12"));
	EXPECT_EQ(result.right, std::string("345"));
}

TEST(ExpressionTree_StringUtil, Split_NotFound) {
	std::string input = "12+345";

	SplitResult result = StringUtil::split(input, '-');

	EXPECT_EQ(result.result, SplitResult::ResultValue::FAIL);
}

TEST(ExpressionTree_StringUtil, Split_OuterDelim) {
	std::string input = "12+(34+56)";

	SplitResult result = StringUtil::split(input, '+');

	EXPECT_EQ(result.result, SplitResult::ResultValue::OK);
	EXPECT_EQ(result.left, std::string("12"));
	EXPECT_EQ(result.right, std::string("(34+56)"));
}