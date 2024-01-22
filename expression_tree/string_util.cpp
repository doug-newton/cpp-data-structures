#include "string_util.h"
#include <iostream>

namespace newton_ds {
	namespace expression_tree {

		/*
		* counts bracket pairs by adding and subtracting from a balance factor
		* when balance factor is 0, an outer bracket pair has been closed
		* e.g. this has 2 sets of outer brackets
		* (1+2)-(1+2)
		* and this has one set of outer brackets
		* (1+(1-2))
		*/

		int count_outer_bracket_pairs(const std::string& input) {
			int bracket_balance = 0;
			int num_outer_brackets = 0;
			int str_len = input.length();

			for (int pos = 0; pos < str_len; pos++) {
				if (input[pos] == '(') {
					bracket_balance++;
				}
				if (input[pos] == ')') {
					bracket_balance--;
					if (bracket_balance == 0) {
						num_outer_brackets++;
					}
				}
			}

			return num_outer_brackets;
		}

		std::string strip_outer_brackets(const std::string& input) {
			if (input[0] != '(' || input[input.length() - 1] != ')') {
				return input;
			}

			if (count_outer_bracket_pairs(input) > 1) {
				return input;
			}

			return input.substr(1, input.length() - 2);
		}

		/*
		* splits by a delimeter if not between brackets, 
		* by counting the number of opening and closing brackets
		* splitting (4+3)+2 with delimeter '+' will split into (4+3) and 2
		*/

		split_by_delim_result split_by_delim_outside_brackets(const std::string& input, char delim) {
			int bracket_balance = 0;

			split_by_delim_result result;

			int pos = 0;
			int len = input.length();

			for (; pos < len; pos++) {
				char c = input[pos];
				if (c == '(') {
					bracket_balance++;
				}
				else if (c == ')') {
					bracket_balance--;
				}
				if (c == delim && bracket_balance == 0) {
					break;
				}
			}

			if (pos == len) {
				result.result = split_by_delim_result::FAIL;
				return result;
			}

			result.result = split_by_delim_result::OK;
			result.left = input.substr(0, pos);
			result.right = input.substr(pos + 1, input.length() - pos);

			return result;
		}

		operator_split_result split_by_operator(const std::string& input) {
			operator_split_result result;

			int str_len = input.length();
			int bracket_balance = 0;
			int pos = 0;

			for (; pos < str_len; pos++) {

				char c = input[pos];

				if (c == '(') {
					bracket_balance++;
					continue;
				}

				if (c == ')') {
					bracket_balance--;
					continue;
				}

				if (bracket_balance != 0) {
					continue;
				}

				if (is_operator(c)) {
					result.op = to_operator(c);
					result.status = operator_split_result::FOUND;
					break;
				}

			}

			if (pos == str_len) {
				result.op = NONE;
				result.status = operator_split_result::NOT_FOUND;
				return result;
			}

			result.left = input.substr(0, pos);
			result.right = input.substr(pos + 1, input.length() - pos);

			return result;
		}

		bool is_operator(char c) {
			return c == '+' || c == '-' || c == '*' || c == '/';
		}

		Operator to_operator(char c) {
			switch (c) {
			case '+': return ADD;
			case '-': return SUBTRACT;
			case '*': return MULTIPLY;
			case '/': return DIVIDE;
			default: return NONE;
			}
		}

	}
}