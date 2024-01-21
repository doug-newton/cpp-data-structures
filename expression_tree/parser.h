#pragma once

#include <string>
#include "node.h"
#include "string_util.h"

namespace newton_ds {
	namespace expression_tree {

		class Parser {

		public:
			static Node* parse(const std::string& expression);
			static std::string stripOuterBrackets(const std::string& input);
		};

	}
}

