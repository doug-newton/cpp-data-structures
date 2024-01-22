#include "../parsing.h"

namespace newton_ds {
	namespace expression_tree {

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