#pragma once

#include "operator.h"

namespace newton_ds {
	namespace expression_tree {

		class Node {

		public:

			Node(double value);
			void calculate();
			double getValue();

		private:
			double m_value;
			Operator m_operator;

		};

	}
}
