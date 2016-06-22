#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
class node {
	public:
		T data;
		node* next;
};

template <typename T>
class LinkedList 
{
	private:
		node<T>* head;
		void Remove();

	public:
		LinkedList();
		~LinkedList();
		void Print(); void Insert(T input);
		void Remove(node<T>* n);
		void Remove(T n);
		node<T>* KthNodeFromEnd(int k);
		node<T>* Reverse();
		void RemoveDupesBuffed();
		void RemoveDupesUnBuffed();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(head != nullptr)
	{
		Remove();
	}
}

template <typename T>
void LinkedList<T>::Print()
{
	node<T>* elem = head;
	while (elem != nullptr)
	{
		std::cout << elem->data << std::endl;
		elem = elem->next;
	} 
}

template <typename T>
void LinkedList<T>::Insert(T input)
{
	node<T>* insert = new node<T>;
	insert->data = input;
	insert->next = head;
	head = insert;
}

template <typename T>
void LinkedList<T>::Remove()
{
	node<T>* prev = head;
	head = head->next;
	delete prev;
}

template <typename T>
void LinkedList<T>::Remove(node<T>* n)
{
	node<T>* elem = head;
	node<T>* prev = head;

	while (elem != nullptr)
	{
		if (elem != n)
		{
			prev = elem;
			elem = elem->next;
		}
		else if (elem == n)
		{
			prev->next = elem->next;
			delete elem;
			return;
		}
	}
}

template <typename T>
void LinkedList<T>::Remove(T n)
{
	node<T>* elem = head;
	node<T>* prev = head;

	while (elem != nullptr)
	{
		if (elem->data != n)
		{
			prev = elem;
			elem = elem->next;
		}
		else if (elem->data == n)
		{
			prev->next = elem->next;
			delete elem;
			return;
		}
	}
}

template <typename T>
node<T>* LinkedList<T>::KthNodeFromEnd(int k)
{
	//iterate only once, ptr2 is always k steps behind ptr1
	node<T>* ptr1 = head;
	node<T>* ptr2 = head;
	int i = 0;

	while (ptr1 != nullptr)
	{
		ptr1 = ptr1->next;
		++i;
		if (i > k)
		{
			ptr2 = ptr2->next;
		}
	}
	return ptr2;
}

template<typename T>
node<T>* LinkedList<T>::Reverse()
{
	node<T>* prev = head;
	node<T>* cur = head->next;
	node<T>* ptr = cur->next;

	prev->next = nullptr;
	while (cur->next != nullptr)
	{
		cur->next = prev;
		prev = cur;
		cur = ptr;
		ptr = ptr->next;
	}
	
	cur->next = prev;
	head = cur;

	return head;
}

template <typename T>
void LinkedList<T>::RemoveDupesBuffed()
{
	
	std::vector<T> buffer;
	node<T>* elem = head;
	node<T>* prev = head;

	while (elem != nullptr)
	{
		if (std::find(buffer.begin(), buffer.end(), elem->data) != buffer.end() && elem != head)
		{
				prev->next = elem->next;
				node<T>* deleted = elem;
				elem = elem->next;
				delete deleted;
		}
		else 
		{
			buffer.push_back(elem->data);
			prev = elem;
			elem = elem->next;
		}
	}
}

template <typename T>
void LinkedList<T>::RemoveDupesUnBuffed()
{
	node<T>* elem = head;
	node<T>* prev = head;
	node<T>* iter = head->next;

	while (elem != nullptr)
	{
		if (iter != nullptr)
		{
			if (iter->data == elem->data)
			{
				prev->next = iter->next;
				node<T>* deleteme = iter;
				iter = iter->next;
				delete deleteme;
			}
			else if (iter->data != elem->data)
			{
				prev = iter;
				iter = iter->next;
			}
		}
		else if (iter == nullptr)
		{
			elem = elem->next;
			if (elem != nullptr)
			{
				iter = elem->next;
				prev = elem;
			}
		}
	}
}
