#pragma once

#include <string>
#include "operator.h"
#include "node.h"

namespace newton_ds {
	namespace expression_tree {

		int count_outer_bracket_pairs(const std::string& input);
		std::string strip_outer_brackets(const std::string& input);

		struct operator_split_result {
			enum {
				FOUND = 0,
				NOT_FOUND
			} status;
			Operator op;
			std::string left;
			std::string right;
		};

		operator_split_result split_by_operator(const std::string& input);

		bool is_operator(char c);
		Operator to_operator(char c);

		Node* parse(const std::string& expression);

	}
}
