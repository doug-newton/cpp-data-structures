#include "string_util.h"
#include <iostream>

namespace newton_ds {
	namespace expression_tree {

		SplitResult StringUtil::split(const std::string& input, char delim) {
			SplitResult result;

			size_t pos = input.find(delim);

			if (pos == std::string::npos) {
				result.result = SplitResult::ResultValue::FAIL;
			}
			else {
				result.result = SplitResult::ResultValue::OK;
				result.left = input.substr(0, pos);
				result.right = input.substr(pos + 1, input.length() - pos);
			}

			return result;
		}

	}
}