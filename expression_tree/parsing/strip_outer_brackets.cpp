#include "../parsing.h"

namespace newton_ds {
	namespace expression_tree {

		std::string strip_outer_brackets(const std::string& input) {
			if (input[0] != '(' || input[input.length() - 1] != ')') {
				return input;
			}

			if (count_top_level_bracket_pairs(input) > 1) {
				return input;
			}

			return input.substr(1, input.length() - 2);
		}

	}
}
