#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Iterator.h"

#include <iostream>

template <typename T>
class Node {
	public:
		typedef T value_type;
		T data;
		Node* next;
};

template <typename T>
class LinkedList 
{
	private:
		Node<T>* head;
		int size;

		void remove();

	public:
		LinkedList();
		~LinkedList();
		int getSize();
		void insert(T input);
		void remove(Node<T>* n);
		void remove(T n);
		Node<T>* kthNodeFromEnd(int k);
		Node<T>* reverse();

		Iterator<Node<T> > begin();
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
		remove();
	}
}

template <typename T>
void LinkedList<T>::insert(T input)
{
	Node<T>* insert = new Node<T>;
	insert->data = input;
	insert->next = head;
	head = insert;
	++size;
}

template <typename T>
void LinkedList<T>::remove()
{
	Node<T>* prev = head;
	head = head->next;
	delete prev;
	--size;
}

template <typename T>
void LinkedList<T>::remove(Node<T>* n)
{
	Node<T>* elem = head;
	Node<T>* prev = head;

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
	--size;
}

template <typename T>
void LinkedList<T>::remove(T n)
{
	Node<T>* elem = head;
	Node<T>* prev = head;

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
Node<T>* LinkedList<T>::kthNodeFromEnd(int k)
{
	//iterate only once, ptr2 is always k steps behind ptr1
	Node<T>* ptr1 = head;
	Node<T>* ptr2 = head;
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
Node<T>* LinkedList<T>::reverse()
{
	Node<T>* prev = head;
	Node<T>* cur = head->next;
	Node<T>* ptr = cur->next;

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

template<typename T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template<typename T>
Iterator<Node<T> > LinkedList<T>::begin()
{
	return Iterator<Node<T> >(*head);
}

#endif