#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <typename T>
class Stack
{
	private:
		LinkedList<T> data;

	public:
		void push(T input);
		const T& peek();	
		T pop();
};

template <typename T>
void Stack<T>::push(T input) 
{
	data.insert(input);		
}		

template <typename T>
const T& Stack<T>::peek()
{
	//add exception handling
	return *(data.begin());
}

template <typename T>
T Stack<T>::pop()
{
	//add exception handling
	auto val = *(data.begin());
	auto elem = data.begin();
	data.remove(elem);
	return val;
}


#endif
