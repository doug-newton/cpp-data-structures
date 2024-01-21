#include "parser.h"
#include <string>

namespace newton_ds {
	namespace expression_tree {

		Node* Parser::parse(const std::string& expression) {
			std::string inner_expression = strip_outer_brackets(expression);

			SplitResult result = split_by_delim(inner_expression, '+');

			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::ADD, 
					parse(result.right));
			}

			result = split_by_delim(inner_expression, '-');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::SUBTRACT, 
					parse(result.right));
			}

			result = split_by_delim(inner_expression, '*');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::MULTIPLY, 
					parse(result.right));
			}

			result = split_by_delim(inner_expression, '/');
			
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


	}
}