#include "node.h"

template <typename T>
class LinkedList {

public:

	class iterator {

	public:

		iterator(Node<T>* node);
		Node<T>* operator*();
		void operator++();
		bool operator==(const iterator& other);
		bool operator!=(const iterator& other);

	private:

		Node<T>* m_node;

	};

	LinkedList();
	~LinkedList();

	void clear();

	Node<T>* head();
	Node<T>* tail();

	int count();

	void append(const T& value);
	void prepend(const T& value);

	Node<T>* element_at(int pos);
	Node<T>* find(const T& value);

	void remove(const T& value);

	iterator begin();
	iterator end();

private:

	Node<T>* m_head;
	Node<T>* m_tail;
};

template <typename T>
LinkedList<T>::iterator::iterator(Node<T>* node) :
	m_node(node) { }

template <typename T>
Node<T>* LinkedList<T>::iterator::operator*() {
	return this->m_node;
}

template <typename T>
void LinkedList<T>::iterator::operator++() {
	if (this->m_node == nullptr) {
		return;
	}

	this->m_node = this->m_node->next();
}

template <typename T>
bool LinkedList<T>::iterator::operator==(const LinkedList::iterator& other) {
	return other.m_node == this->m_node;
}


template <typename T>
bool LinkedList<T>::iterator::operator!=(const LinkedList::iterator& other) {
	return other.m_node != this->m_node;
}

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

	this->m_head = nullptr;
	this->m_tail = nullptr;
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

template <typename T>
Node<T>* LinkedList<T>::find(const T& value) {
	Node<T>* node = this->m_head;

	while (node != nullptr) {
		if (node->getValue() == value) {
			return node;
		}
		node = node->next();
	}

	return nullptr;
}

template <typename T>
void LinkedList<T>::remove(const T& value) {
	Node<T>* node = this->find(value);

	if (node == nullptr) {
		return;
	}

	Node<T>* prev = node->prev();
	Node<T>* next = node->next();

	if (prev == nullptr && next == nullptr) {
		this->m_head = nullptr;
		this->m_tail = nullptr;
	}
	else if (prev == nullptr) {
		//	node is the head, so next becomes head
		this->m_head = next;
		this->m_head->prepend(nullptr);
	}
	else if (next == nullptr) {
		//	node is the tail, so prev becomes tail
		this->m_tail = prev;
		this->m_tail->append(nullptr);
	}
	else {
		//	prev and append exist, so join together
		prev->append(next);
	}

	delete node;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin() {
	return LinkedList<T>::iterator(this->m_head);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
	return LinkedList<T>::iterator(nullptr);
}
