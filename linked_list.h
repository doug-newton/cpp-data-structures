#include "node.h"

template <typename T>
class LinkedList {

public:

	LinkedList();

	Node<T>* head();
	Node<T>* tail();

private:

	Node<T>* m_head;
	Node<T>* m_tail;
};

template <typename T>
LinkedList<T>::LinkedList() :
	m_head(nullptr),
	m_tail(nullptr) { }

template <typename T>
Node<T>* LinkedList<T>::head() {
	return this->m_head;
}

template <typename T>
Node<T>* LinkedList<T>::tail() {
	return this->m_tail;
}