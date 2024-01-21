#include "parser.h"
#include <string>

namespace newton_ds {
	namespace expression_tree {

		Node* Parser::parse(const std::string& expression) {

			SplitResult result = StringUtil::split(expression, '+');

			if (result.result == SplitResult::ResultValue::OK) {
				double left_value = std::stod(result.left);
				double right_value = std::stod(result.right);
				return new Node(new Node(left_value), Operator::ADD, new Node(right_value));
			}

			result = StringUtil::split(expression, '-');
			
			if (result.result == SplitResult::ResultValue::OK) {
				double left_value = std::stod(result.left);
				double right_value = std::stod(result.right);
				return new Node(new Node(left_value), Operator::SUBTRACT, new Node(right_value));
			}

			result = StringUtil::split(expression, '*');
			
			if (result.result == SplitResult::ResultValue::OK) {
				double left_value = std::stod(result.left);
				double right_value = std::stod(result.right);
				return new Node(new Node(left_value), Operator::MULTIPLY, new Node(right_value));
			}

			result = StringUtil::split(expression, '/');
			
			if (result.result == SplitResult::ResultValue::OK) {
				double left_value = std::stod(result.left);
				double right_value = std::stod(result.right);
				return new Node(new Node(left_value), Operator::DIVIDE, new Node(right_value));
			}
		}

	}
}