#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template<typename T, typename P>
class PQNode
{
	public:
		typedef T value_type;		
		T data;
		P priority;

		PQNode<T,P>* next = nullptr;

		PQNode<T,P>* operator+(int steps);
};

template <typename T, typename P>
PQNode<T,P>* PQNode<T,P>::operator+(int steps)
{
	auto tmp = this;
	for (int i = 0; i < steps && tmp->next != nullptr; ++i)
	{
		tmp = tmp->next;
	}
	return tmp;
}

template<typename T, typename P>
class PriorityQueue
{
	private:
		PQNode<T,P>* head = nullptr;

		void remove(PQNode<T,P>*);
	public:
		~PriorityQueue<T,P>();

		void push(T data, P priority);
		const T& peek();
		T pop();
};

template<typename T, typename P>
PriorityQueue<T,P>::~PriorityQueue()
{
	while (head != nullptr)
	{
		remove(head);
	}
}

template<typename T, typename P>
void PriorityQueue<T,P>::push(T data, P priority)
{
	//Insert new element by comparing priorities O(N)
	//This method would love a cleverer implementation that naturally deals with
	auto insert = new PQNode<T,P>();	
	insert->data = data;
	insert->priority = priority;

	if (head == nullptr)
	{
		//if the new element is the first element
		head = insert;
		return;
	}

	auto elem = head;
	auto prev = head;
	while (elem != nullptr)
	{
		if (insert->priority > elem->priority)
		{
			if (elem == head)
			{
				//if the new element is the new head
				insert->next = elem;
				head = insert;
				return;
			}
			else
			{
				//if the new element is in the middle
				prev->next = insert;			
				insert->next = elem;	
				return;
			}
		}	
		else if (elem->next == nullptr)
		{
			//if the new element is at the end
			elem->next = insert;
			return;
		}
		prev = elem;
		elem = elem->next;
	}
}

template <typename T, typename P>
const T& PriorityQueue<T,P>::peek()
{
	//needs exception
	return head->data;	
}


template <typename T, typename P>
T PriorityQueue<T,P>::pop()
{
	auto popped = head->data;
	remove(head);
	return popped;
}

template <typename T, typename P>
void PriorityQueue<T,P>::remove(PQNode<T,P>* n)
{
	//Remove element by node
	if (n == head)
	{
		//if element is head
		auto rm = head;
		head = head->next;
		delete rm;
		return;
	}

	auto elem = head;
	auto prev = head;
	while (elem != nullptr)
	{
		if (n == elem)
		{
			///if element is in the middle
			prev->next = elem->next;
			delete elem;
			return;
		}	
		prev = elem;
		elem = elem->next;
	}
}

#endif
