#pragma once

#include <string>

namespace newton_ds {
	namespace expression_tree {

		class SplitResult {
		public:
			enum ResultValue {
				OK = 0,
				FAIL
			} result;
			std::string left;
			std::string right;
		};

		class StringUtil {
		public:
			static SplitResult split(const std::string& input, char delim);
		};

		int count_outer_bracket_pairs(const std::string& input);

	}
}
