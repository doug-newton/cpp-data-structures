#include "node.h"

namespace newton_ds {
	namespace expression_tree {

		Node::Node(double value) : 
			m_value(value), 
			m_operator(Operator::NONE),
			m_left(nullptr),
			m_right(nullptr) {
		}

		Node::Node(const Node& node): 
			m_value(node.m_value), 
			m_operator(node.m_operator),
			m_left(node.m_left),
			m_right(node.m_right) {
		}

		Node::Node(Node* left, Operator op, Node* right):
			m_value(0),
			m_operator(op),
			m_left(left),
			m_right(right) {
		}

		Node::~Node() {
			if (this->m_left != nullptr) {
				delete this->m_left;
			}
			if (this->m_right != nullptr) {
				delete this->m_right;
			}
		}

		void Node::calculate() {
			if (this->m_operator == NONE) {
				return;
			}

			if (this->m_left != nullptr) {
				this->m_left->calculate();
			}

			if (this->m_right != nullptr) {
				this->m_right->calculate();
			}

			switch (this->m_operator) {
			case ADD:
				this->m_value = this->m_left->getValue() + this->m_right->getValue();
				break;
			case SUBTRACT:
				this->m_value = this->m_left->getValue() - this->m_right->getValue();
				break;
			case MULTIPLY:
				this->m_value = this->m_left->getValue() * this->m_right->getValue();
				break;
			case DIVIDE:
				this->m_value = this->m_left->getValue() / this->m_right->getValue();
				break;
			}

		}

		double Node::getValue() {
			return this->m_value;
		}

	}
}