#include "node.h"

namespace newton_ds {
	namespace expression_tree {

		Node::Node(double value) : 
			m_value(value), 
			m_operator(Operator::NONE) {
		}

		void Node::calculate() {
			if (this->m_operator == NONE) {
				return;
			}
		}

		double Node::getValue() {
			return this->m_value;
		}

	}
}