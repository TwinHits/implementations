#ifndef ITERATOR_H
#define ITERATOR_H

//Generic iterator for each data structure defined for easy traversal by other
//code.

template <typename T>
class Node;

template <typename T>
class LinkedList;

template <typename T>
class Node;

template <typename N>
class Iterator 
{
	friend class LinkedList<typename N::value_type>;

	private:
		N& node;

	public:
		Iterator(N& n) : node(n) {};

		typename N::value_type operator*();
		bool operator==(const Iterator<N>& rhs);
		bool operator!=(const Iterator<N>& rhs);
		Iterator<N> operator+(int steps);
		Iterator<N> operator++();
};

template <typename N>
typename N::value_type Iterator<N>::operator*()
{
	return this->node.data;
}

template <typename N>
bool Iterator<N>::operator==(const Iterator<N>& rhs)
{
	return &this->node == &rhs.node;
}

template <typename N>
bool Iterator<N>::operator!=(const Iterator<N>& rhs)
{
	return !(this->node == rhs.node);
}

template <typename N>
Iterator<N> Iterator<N>::operator+(int steps)
{
	auto tmp = this->node;
	for (int i = 0; i < steps && tmp.next != nullptr; ++i)
	{
		tmp = *(tmp.next);
	}
	return Iterator<N>(tmp);
}

template <typename N>
Iterator<N> Iterator<N>::operator++()
{
	if (this->node.next != nullptr)
		this->node = *(node.next);	
	return *this;
}

#endif
