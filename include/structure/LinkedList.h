#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../pattern/Iterator.h"

template <typename T>
class LLNode {
	public:
		typedef T value_type;
		T data;
		LLNode* next;

		LLNode<T>* operator+(int steps); 
};

template <typename T>
LLNode<T>* LLNode<T>::operator+(int steps)
{
	auto tmp = this;
	for (int i = 0; i < steps && tmp->next != nullptr; ++i)
	{
		tmp = tmp->next;
	}
	return tmp;
}

template <typename T>
class LinkedList 
{
	private:
		int size;
		LLNode<T>* head;

	public:
		LinkedList();
		~LinkedList();
		int getSize();
		void insert(T input);
		void remove(Iterator<LLNode<T> >& i);
		void remove(LLNode<T>* n);
		void remove(T n);

		Iterator<LLNode<T> > begin();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(head != nullptr)
	{
		remove(head);
	}
}

template <typename T>
void LinkedList<T>::insert(T input)
{
	LLNode<T>* insert = new LLNode<T>;
	insert->data = input;
	insert->next = head;
	head = insert;
	++size;
}

template <typename T>
void LinkedList<T>::remove(LLNode<T>* n)
{
	LLNode<T>* elem = head;
	LLNode<T>* prev = head;

	while (elem != nullptr)
	{
		if (elem != n)
		{
			prev = elem;
			elem = elem->next;
		}
		else if (elem == n)
		{
			if (elem == head)
				head = elem->next;
			else
				prev->next = elem->next;

			delete elem;
			--size;
			return;
		}
	}
}

template <typename T>
void LinkedList<T>::remove(T n)
{
	LLNode<T>* elem = head;
	LLNode<T>* prev = head;

	while (elem != nullptr)
	{
		if (elem->data != n)
		{
			prev = elem;
			elem = elem->next;
		}
		else if (elem->data == n)
		{
			if (elem == head)
				head = elem->next;
			else
				prev->next = elem->next;

			delete elem;
			--size;
			return;
		}
	}
}

template <typename T>
void LinkedList<T>::remove(Iterator<LLNode<T> >& i)
{
	remove(i.node);
}

template<typename T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template<typename T>
Iterator<LLNode<T> > LinkedList<T>::begin()
{
	return Iterator<LLNode<T> >(head);
}

#endif
