#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template<typename T>
class node 
{
	public:
		T item;
		node<T>* left;
		node<T>* right;

		node(T i);
};

template<typename T>
node<T>::node(T i)
{
	item = i;
	left = nullptr;
	right = nullptr;
}

template<typename T>
class BinarySearchTree 
{
	public:
		bool search(T i);
		void insert(T i);
		bool balanced();
		void print();

		bool operator==(BinarySearchTree<T>& rhs);
		BinarySearchTree<T> operator=(BinarySearchTree<T> rhs);

	protected:
		node<T>* root = nullptr;
		int size = 0;

	private:
		bool TreeSearch(node<T>* r, T i);
		void TreeInsert(node<T>*& r, T i);
		void InorderPrint(node<T>* r);
		int CheckBalance(node<T>* n);
		bool PreorderEquality(node<T>* n, BinarySearchTree<T>& rhs);
};

template <typename T>
bool BinarySearchTree<T>::search(T i)
{
	return TreeSearch(root, i);
}

template <typename T>
void BinarySearchTree<T>::insert(T i)
{
	TreeInsert(root, i);
	size++;
}

template <typename T>
void BinarySearchTree<T>::print()
{
	InorderPrint(root);
}

template <typename T>
bool BinarySearchTree<T>::balanced()
{
	int right = CheckBalance(root->right);
	int left = CheckBalance(root->left);
	if (right == left || right - left == 1 || left - right == 1)
	{
		return true;	
	}		
	return false;
}

template <typename T>
bool BinarySearchTree<T>::TreeSearch(node<T>* r, T i)
{
	if (r == nullptr)
		return false;
	else if (r->item == i)
		return true;	
	else if (i > r->item)
		return TreeSearch(r->right, i);
	else
		return TreeSearch(r->left, i);
}

template <typename T>
void BinarySearchTree<T>::TreeInsert(node<T>*& n, T i)
{
		if (n == nullptr)
			n = new node<T>(i);
		else if (i > n->item)
			TreeInsert(n->right, i);
		else if (i < n->item)
			TreeInsert(n->left, i);
}

template <typename T>
void BinarySearchTree<T>::InorderPrint(node<T>* r)
{
	if (r != nullptr)
	{
		InorderPrint(r->left);	
		std::cout << r->item << std::endl;
		InorderPrint(r->right);
	}
}

template<typename T>
int BinarySearchTree<T>::CheckBalance(node<T>* n)
{
	if (n != nullptr)
	{
		int count = 1;
		count += CheckBalance(n->left);
		count += CheckBalance(n->right);
		return count;	
	}

	return 0;
}

template<typename T>
bool BinarySearchTree<T>::PreorderEquality(node<T>* n, BinarySearchTree<T>& rhs)
{
	bool check = true;

	if (this->size != rhs.size)
		return false;

	if (n != nullptr && check == true)
	{
		check = rhs.search(n->item);

		if (check == true)
			check = PreorderEquality(n->left, rhs);

		if (check == true)
			check = PreorderEquality(n->right, rhs);
	}

	return check;
}

template<typename T>
bool BinarySearchTree<T>::operator==(BinarySearchTree<T>& rhs)
{
	return PreorderEquality(root, rhs);		
}

#endif
