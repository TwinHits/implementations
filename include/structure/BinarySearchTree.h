#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "../pattern/Iterator.h"

//A binary search tree is a top down set of BSTNodes with ptr's to the next BSTNodes
//starting with the root.

template <typename T>
class BSTNode 
{
	public:
		typedef T value_type;

		T data;
		BSTNode<T>* parent;
		BSTNode<T>* left;
		BSTNode<T>* right;

		BSTNode(T i, BSTNode<T>* p);
		BSTNode<T>* operator+(int steps);
};

template <typename T>
BSTNode<T>* BSTNode<T>::operator+(int steps)
{
	auto tmp = this;
	while (steps > 0)
	{
		if (tmp->right != nullptr)
			tmp = tmp->right;


		--steps;		
	}
	return tmp;
}

template <typename T>
BSTNode<T>::BSTNode(T i, BSTNode<T>* p)
{
	data = i;
	parent = p;	
	left = nullptr;
	right = nullptr;
}

template <typename T>
class BinarySearchTree 
{
	private:
		BSTNode<T>* root = nullptr;
		int size = 0;
		bool TreeSearch(BSTNode<T>* r, T i);
		void TreeInsert(BSTNode<T>*& n, T i, BSTNode<T>* parent);
		int CheckBalance(BSTNode<T>* n);
		bool PreorderEquality(BSTNode<T>* n, BinarySearchTree<T>& rhs);

	public:
		bool search(T i);
		void insert(T i);
		bool balanced();

		bool operator==(BinarySearchTree<T>& rhs);
		BinarySearchTree<T> operator=(BinarySearchTree<T> rhs);

		Iterator<BSTNode<T> > begin();
};

template <typename T>
bool BinarySearchTree<T>::search(T i)
{
	return TreeSearch(root, i);
}

template <typename T>
void BinarySearchTree<T>::insert(T i)
{
	TreeInsert(root, i, nullptr);
	size++;
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
bool BinarySearchTree<T>::TreeSearch(BSTNode<T>* r, T i)
{
	if (r == nullptr)
		return false;
	else if (r->data == i)
		return true;	
	else if (i > r->data)
		return TreeSearch(r->right, i);
	else
		return TreeSearch(r->left, i);
}

template <typename T>
void BinarySearchTree<T>::TreeInsert(BSTNode<T>*& n, T i, BSTNode<T>* parent)
{
		if (n == nullptr)
			n = new BSTNode<T>(i, parent);
		else if (i > n->data)
			TreeInsert(n->right, i, n);
		else if (i <= n->data)
			TreeInsert(n->left, i, n);
}

template<typename T>
int BinarySearchTree<T>::CheckBalance(BSTNode<T>* n)
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
bool BinarySearchTree<T>::PreorderEquality(BSTNode<T>* n, BinarySearchTree<T>& rhs)
{
	bool check = true;

	if (this->size != rhs.size)
		return false;

	if (n != nullptr && check == true)
	{
		check = rhs.search(n->data);

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

template<typename T>
Iterator<BSTNode<T> > BinarySearchTree<T>::begin()
{
	//In order traversal to left most BSTNode
	auto elem = root;
	while (elem->left != nullptr)
	{
		elem = elem->left;
	}

	return Iterator<BSTNode<T> >(elem);
}

#endif
