#include "node.h"

template <typename T>
class LinkedList {

public:

	LinkedList();
	~LinkedList();

	void clear();

	Node<T>* head();
	Node<T>* tail();

	int count();

private:

	Node<T>* m_head;
	Node<T>* m_tail;
};

template <typename T>
LinkedList<T>::LinkedList() :
	m_head(nullptr),
	m_tail(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
	this->clear();
}

template <typename T>
void LinkedList<T>::clear() {
	Node<T>* node = this->m_head;

	while (node != nullptr) {
		Node<T>* temp = node->next();
		delete node;
		node = temp;
	}
}

template <typename T>
Node<T>* LinkedList<T>::head() {
	return this->m_head;
}

template <typename T>
Node<T>* LinkedList<T>::tail() {
	return this->m_tail;
}

template <typename T>
int LinkedList<T>::count() {
	int count = 0;

	Node<T>* node = this->m_head;

	while (node != nullptr) {
		count++;
		node = node->next();
	}

	return count;
}