#pragma once

#include "operator.h"
#include "division_by_zero_exception.h"

namespace newton_ds {
	namespace expression_tree {

		class Node {

		public:

			Node(double value);
			Node(const Node& node);
			Node(Node* left, Operator op, Node* right);
			~Node();

			void calculate();
			double getValue();

		private:
			double m_value;
			Operator m_operator;

			Node* m_left;
			Node* m_right;

		};

	}
}
