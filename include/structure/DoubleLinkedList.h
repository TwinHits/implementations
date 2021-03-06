#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "../pattern/Iterator.h"

template <typename T>
class DLLNode {
	public:
		typedef T value_type;
		T data;
		DLLNode* next;
		DLLNode* prev;

		DLLNode<T>* operator+(int steps);
};

template <typename T>
DLLNode<T>* DLLNode<T>::operator+(int steps)
{
	//returns pointer to the node x steps ahead. For Iterator
	auto tmp = this;
	for (int i = 0; i < steps && tmp->next != nullptr; ++i)
	{
		tmp = tmp->next;
	}
	return tmp;
}

template <typename T>
class DoubleLinkedList 
{
	private:
		int size;
		DLLNode<T>* head;
		DLLNode<T>* tail;

	public:
		DoubleLinkedList();
		~DoubleLinkedList();
		int getSize();
		void insert(T input);
		void remove(Iterator<DLLNode<T> >& i);
		void remove(DLLNode<T>* n);
		void remove(T n);

		Iterator<DLLNode<T> > begin();
		Iterator<DLLNode<T> > end();
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while(head != nullptr)
	{
		remove(head);
	}
}

template <typename T>
void DoubleLinkedList<T>::insert(T input)
{
	DLLNode<T>* insert = new DLLNode<T>;
	insert->data = input;
	insert->next = head;

	if (head != nullptr)
		head->prev = insert;

	head = insert;
	
	if (head->next == nullptr)
		tail = head;

	++size;
}

template <typename T>
void DoubleLinkedList<T>::remove(Iterator<DLLNode<T> >& i)
{
	remove(i.node);
}

template <typename T>
void DoubleLinkedList<T>::remove(DLLNode<T>* n)
{
	DLLNode<T>* elem = head;
	DLLNode<T>* prev = head;

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
			{
				head = elem->next;
				elem->prev = nullptr;
			}
			else if (elem == tail)
			{
				tail = tail->prev;
				tail->next = nullptr;
			}
			else
			{
				prev->next = elem->next;
				elem->next->prev = prev;
			}

			delete elem;
			--size;
			return;
		}
	}
}

template <typename T>
void DoubleLinkedList<T>::remove(T n)
{
	DLLNode<T>* elem = head;
	DLLNode<T>* prev = head;

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
			{
				head = elem->next;
				elem->prev = nullptr;
			}
			else if (elem == tail)
			{
				tail = tail->prev;
				tail->next = nullptr;
			}
			else
			{
				prev->next = elem->next;
				elem->next->prev = prev;
			}

			delete elem;
			--size;
			return;
		}
	}
}

template<typename T>
int DoubleLinkedList<T>::getSize()
{
	return this->size;
}

template<typename T>
Iterator<DLLNode<T> > DoubleLinkedList<T>::begin()
{
	return Iterator<DLLNode<T> >(head);
}

template<typename T>
Iterator<DLLNode<T> > DoubleLinkedList<T>::end()
{
	return Iterator<DLLNode<T> >(tail);
}

#endif
