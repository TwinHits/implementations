#ifndef SET_H
#define SET_H

#include "BinarySearchTree.h"

template <typename T>
class Set: public BinarySearchTree<T>
{
	public:
		void insert(T i);

		Set<T> operator+=(Set<T>& rhs);
		Set<T> operator+(Set<T>& rhs);
		Set<T> operator*(Set<T>& rhs);

	private:
		void Union(Set<T>& rhs, node<T>* n, Set<T>& un);
		void Intersection(Set<T>& rhs, node<T>* n, Set<T>& intersection);
};

template <typename T>
void Set<T>::insert(T i)
{
	if (!this->search(i))
		this->BinarySearchTree<T>::insert(i);
}

template <typename T>
void Set<T>::Union(Set<T>& rhs, node<T>* n, Set<T>& un)
{
	//O(n)
	if (n != nullptr)
	{
		un.insert(n->item);
		this->Union(rhs, n->left, un);
		this->Union(rhs, n->right, un);
	}
}

template <typename T>
void Set<T>::Intersection(Set<T>& rhs, node<T>* n, Set<T>& intersection)
{
	//O(n)
	if (n != nullptr)
	{
		if (this->search(n->item))
			intersection.insert(n->item);
		
		this->Intersection(rhs, n->left, intersection);
		this->Intersection(rhs, n->right, intersection);
	}
}

template <typename T>
Set<T> Set<T>::operator+=(Set<T>& rhs)
{
	if (this->BinarySearchTree<T>::operator==(rhs))
		return *this;

	Set<T> un;
	this->Union(rhs, rhs.root, un);
	this->Union(*this, this->root, un);
	return un;
}	

template <typename T>
Set<T> Set<T>::operator+(Set<T>& rhs)
{
	return *this += rhs;		
}

template <typename T>
Set<T> Set<T>::operator*(Set<T>& rhs) 
{
	Set<T> intersection;
	this->Intersection(rhs, rhs.root, intersection);
	
	return intersection;
}

#endif
