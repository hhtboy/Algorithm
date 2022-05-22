#pragma once

template <class T>
class Node {
private:
	T data;
	Node* link;
public:
	Node(T n, Node* ptr);
	template<class C> friend class Chain;
};

template <class T>
Node<T>::Node(T n, Node* ptr)
{
	data = n;
	link = ptr;
}

