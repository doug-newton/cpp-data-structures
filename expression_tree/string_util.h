#pragma once

#include <string>

namespace newton_ds {
	namespace expression_tree {

		struct split_by_delim_result {
			enum {
				OK = 0,
				FAIL
			} result;
			std::string left;
			std::string right;
		};

		split_by_delim_result split_by_delim_outside_brackets(const std::string& input, char delim);
		int count_outer_bracket_pairs(const std::string& input);
		std::string strip_outer_brackets(const std::string& input);

		struct operator_split_result {
			enum {
				FOUND = 0,
				NOT_FOUND
			} status;
			char op;
			std::string left;
			std::string right;
		};

		operator_split_result split_by_operator(const std::string& input);

		bool is_operator(char c);

	}
}
