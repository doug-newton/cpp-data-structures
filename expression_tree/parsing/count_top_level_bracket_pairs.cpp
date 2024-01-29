#include "../parsing.h"

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

		int count_top_level_bracket_pairs(const std::string& input) {
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

	}
}

