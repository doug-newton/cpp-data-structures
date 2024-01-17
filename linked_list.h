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

	void append(const T& value);
	void prepend(const T& value);

	Node<T>* element_at(int pos);

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

template <typename T>
void LinkedList<T>::append(const T& value) {
	Node<T>* node = new Node<int>(value);

	if (this->m_head == nullptr && this->m_tail == nullptr) {
		this->m_head = this->m_tail = node;
		return;
	}

	this->m_tail->append(node);
	this->m_tail = node;
}

template <typename T>
void LinkedList<T>::prepend(const T& value) {
	Node<T>* node = new Node<int>(value);

	if (this->m_head == nullptr && this->m_tail == nullptr) {
		this->m_head = this->m_tail = node;
		return;
	}

	this->m_head->prepend(node);
	this->m_head = node;
}

template <typename T>
Node<T>* LinkedList<T>::element_at(int pos) {
	Node<T>* node = this->m_head;
	int p = 0;

	while (p < pos && node != nullptr) {
		node = node->next();
		p++;
	}

	return node;
}