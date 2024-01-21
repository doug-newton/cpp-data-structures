#include "parser.h"
#include <string>

namespace newton_ds {
	namespace expression_tree {

		Node* Parser::parse(const std::string& expression) {
			std::string inner_expression = stripOuterBrackets(expression);

			SplitResult result = StringUtil::split(inner_expression, '+');

			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::ADD, 
					parse(result.right));
			}

			result = StringUtil::split(inner_expression, '-');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::SUBTRACT, 
					parse(result.right));
			}

			result = StringUtil::split(inner_expression, '*');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::MULTIPLY, 
					parse(result.right));
			}

			result = StringUtil::split(inner_expression, '/');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::DIVIDE, 
					parse(result.right));
			}

			//	no operators found, so assume expression is a constant

			double value = std::stod(inner_expression);
			return new Node(value);
		}

		std::string Parser::stripOuterBrackets(const std::string& input) {
			if (input[0] != '(' || input[input.length() - 1] != ')') {
				return input;
			}

			if (count_outer_bracket_pairs(input) > 1) {
				return input;
			}

			return input.substr(1, input.length() - 2);
		}

	}
}