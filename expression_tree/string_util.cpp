#include "string_util.h"
#include <iostream>

namespace newton_ds {
	namespace expression_tree {

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

		split_by_delim_result split_by_delim(const std::string& input, char delim) {
			int bracketCounter = 0;

			split_by_delim_result result;

			int pos = 0;
			int len = input.length();

			for (; pos < len; pos++) {
				char c = input[pos];
				if (c == '(') {
					bracketCounter++;
				}
				else if (c == ')') {
					bracketCounter--;
				}
				if (c == delim && bracketCounter == 0) {
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

	}
}