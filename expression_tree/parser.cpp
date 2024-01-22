#include "parser.h"
#include <string>

namespace newton_ds {
	namespace expression_tree {

		Node* Parser::parse(const std::string& expression) {
			std::string inner_expression = strip_outer_brackets(expression);

			operator_split_result result = split_by_operator(inner_expression);

			if (result.status == operator_split_result::NOT_FOUND) {
				double value = std::stod(inner_expression);
				return new Node(value);
			}

			return new Node(
				parse(result.left),
				result.op,
				parse(result.right));
		}


	}
}