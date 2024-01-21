#pragma once

#include <exception>

namespace newton_ds {
	namespace expression_tree {
		class DivisionByZeroException : public std::exception {

		public:
			const char* what() const noexcept override {
				return "cannot divide by zero";
			}

		};
	}
}
