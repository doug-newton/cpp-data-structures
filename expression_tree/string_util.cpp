#include "string_util.h"
#include <iostream>

namespace newton_ds {
	namespace expression_tree {

		SplitResult StringUtil::split(const std::string& input, char delim) {
			int bracketCounter = 0;

			SplitResult result;

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
				result.result = SplitResult::ResultValue::FAIL;
				return result;
			}

			result.result = SplitResult::ResultValue::OK;
			result.left = input.substr(0, pos);
			result.right = input.substr(pos + 1, input.length() - pos);

			return result;
		}

	}
}