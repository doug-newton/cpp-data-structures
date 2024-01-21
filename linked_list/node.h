#pragma once

template <typename T>
class Node {

public:

	Node(T data);
	T getValue();

	Node<T>* next();
	Node<T>* prev();

	void append(Node<T>* node);
	void prepend(Node<T>* node);

private:

	T m_data;
	Node<T>* m_next;
	Node<T>* m_prev;
};

template <typename T>
Node<T>::Node(T data) :
	m_data(data),
	m_next(nullptr),
	m_prev(nullptr) { }

template <typename T>
T Node<T>::getValue() {
	return this->m_data;
}

template <typename T>
Node<T>* Node<T>::next() {
	return this->m_next;
}

template <typename T>
Node<T>* Node<T>::prev() {
	return this->m_prev;
}

template <typename T>
void Node<T>::append(Node<T>* node) {
	this->m_next = node;
	if (node != nullptr) {
		node->m_prev = this;
	}
}

template <typename T>
void Node<T>::prepend(Node<T>* node) {
	this->m_prev = node;
	if (node != nullptr) {
		node->m_next = this;
	}
}
