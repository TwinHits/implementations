#include <iostream>
#include <string>

template<typename T>
class BinaryTree {
	private:
		struct node {
			T item;
			node* left;
			node* right;
			node(T i) {
				item = i;
				left = nullptr;
				right = nullptr;
			}
		};
		node* root = nullptr;
		bool TreeSearch(node* r, T i);
		void TreeInsert(node*& r, T i);
		void InorderPrint(node* r);
		int CheckBalance(node* n);
	public:
		bool search(T i);
		void insert(T i);
		void print();
		bool balanced();
};

template <typename T>
bool BinaryTree<T>::search(T i)
{
	return TreeSearch(root, i);
}

template <typename T>
void BinaryTree<T>::insert(T i)
{
	TreeInsert(root, i);
}

template <typename T>
void BinaryTree<T>::print()
{
	InorderPrint(root);
}

template <typename T>
bool BinaryTree<T>::balanced()
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
bool BinaryTree<T>::TreeSearch(node* r, T i)
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
void BinaryTree<T>::TreeInsert(node*& n, T i)
{
		if (n == nullptr)
			n = new node(i);
		else if (i > n->item)
			TreeInsert(n->right, i);
		else if (i < n->item)
			TreeInsert(n->left, i);
}

template <typename T>
void BinaryTree<T>::InorderPrint(node* r)
{
	if (r != nullptr)
	{
		InorderPrint(r->left);	
		std::cout << r->item << std::endl;
		InorderPrint(r->right);
	}
}

template<typename T>
int BinaryTree<T>::CheckBalance(node* n)
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

int main()
{
	BinaryTree<std::string> stree;

	stree.insert("John");
	stree.insert("Kate");
	stree.insert("Zach");
	stree.insert("Allie");
	stree.insert("Sarah");
	stree.insert("Laura");
	stree.insert("Irene");
	stree.insert("Shira");
	stree.insert("Courtney");
	stree.insert("Jill");
	stree.insert("Emily");
	stree.insert("Megan");
	stree.insert("Lianna");

	stree.print();

	std::cout << stree.balanced() << std::endl;
}
