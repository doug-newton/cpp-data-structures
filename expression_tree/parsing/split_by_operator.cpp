#include "../parsing.h"

namespace newton_ds {
	namespace expression_tree {

		/*
		* splits by any delimeter outside brackets, 
		* by counting the number of opening and closing brackets
		* e.g.
		* splitting (4+3)+2 will split into (4+3) and 2 with Operator::PLUS
		*/

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

	}
}

