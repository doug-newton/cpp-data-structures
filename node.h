#pragma once

template <typename T>
class Node {

public:

	Node(T data);
	T getValue();

private:

	T m_data;
};

template <typename T>
Node<T>::Node(T data) :
	m_data(data) { }

template <typename T>
T Node<T>::getValue() {
	return this->m_data;
}