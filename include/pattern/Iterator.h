#ifndef ITERATOR_H
#define ITERATOR_H

//Generic iterator for each data structure defined for easy traversal by other
//code.

template<typename T>
class LinkedList;

template<typename T>
class DoubleLinkedList;

template <typename N>
class Iterator 
{
	friend class LinkedList<typename N::value_type>;
	friend class DoubleLinkedList<typename N::value_type>;
	
	private:
		N* node;

	public:
		Iterator(N* n) : node(n) {};

		const typename N::value_type& operator*();
		bool operator==(const Iterator<N>& rhs);
		bool operator!=(const Iterator<N>& rhs); 
		Iterator<N> operator+(int steps);
		Iterator<N> operator++();
};

template <typename N>
const typename N::value_type& Iterator<N>::operator*()
{
	return this->node->data;
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
	N* result = *(this->node) + steps;
	return Iterator<N>(result);
}

template <typename N>
Iterator<N> Iterator<N>::operator++()
{	
	this->node = *(this->node) + 1;
	return *this;
}

#endif
