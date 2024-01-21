#include "parser.h"
#include <string>

namespace newton_ds {
	namespace expression_tree {

		Node* Parser::parse(const std::string& expression) {

			SplitResult result = StringUtil::split(expression, '+');

			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::ADD, 
					parse(result.right));
			}

			result = StringUtil::split(expression, '-');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::SUBTRACT, 
					parse(result.right));
			}

			result = StringUtil::split(expression, '*');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::MULTIPLY, 
					parse(result.right));
			}

			result = StringUtil::split(expression, '/');
			
			if (result.result == SplitResult::ResultValue::OK) {
				return new Node(
					parse(result.left),
					Operator::DIVIDE, 
					parse(result.right));
			}

			//	no operators found, so assume expression is a constant

			double value = std::stod(expression);
			return new Node(value);
		}

	}
}