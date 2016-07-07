#ifndef QUEUE_H
#define QUEUE_H

#include "DoubleLinkedList.h"

template <typename T>
class Queue
{
	private:
		DoubleLinkedList<T> data;

	public:
		void push(T i);
		const T& peek();
		T pop();
};

template <typename T>
void Queue<T>::push(T i)
{
	data.insert(i);
}

template <typename T>
const T& Queue<T>::peek()
{
	return *(data.end());
}

template <typename T>
T Queue<T>::pop()
{
	auto elem = data.end();
	auto val = *elem;
	data.remove(elem);	
	return val;
}

#endif
