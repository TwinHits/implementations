#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class LinkedList {
	private:
		struct node {
			int data;
			node* next;
		};
		node* head;
	public:
		LinkedList()
		{
			head = nullptr;
		}
		node* getHead() const
		{
			return head;
		}
		void Test()
		{
			node* elem = head;
			while (elem != nullptr)
			{
				std::cout << elem->data << std::endl;
				elem = elem->next;
			} 
		}
		void Insert(int input)
		{
			node* insert = new node;
			insert->data = input;
			insert->next = head;
			head = insert;
		}
		void Remove()
		{
			node* prev = head;
			head = head->next;
			delete prev;
		}
		void RemoveNode(node* n)
		{
			node* elem = head;
			node* prev = head;

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
		node* KthNodeFromEnd(int k)
		{
			//iterate only once, ptr2 is always k steps behind ptr1
			node* ptr1 = head;
			node* ptr2 = head;
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
		node* Reverse()
		{
			node* prev = head;
			node* cur = head->next;
			node* ptr = cur->next;

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
		void RemoveDupesBuffed()
		{
			
			std::vector<int> buffer;
			node* elem = head;
			node* prev = head;

			while (elem != nullptr)
			{
				if (std::find(buffer.begin(), buffer.end(), elem->data) != buffer.end() && elem != head)
				{
						prev->next = elem->next;
						node* deleted = elem;
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
		void RemoveDupesUnBuffed()
		{
			node* elem = head;
			node* prev = head;
			node* iter = head->next;

			while (elem != nullptr)
			{
				if (iter != nullptr)
				{
					if (iter->data == elem->data)
					{
						prev->next = iter->next;
						node* deleteme = iter;
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
		~LinkedList()
		{
			while(head != nullptr)
			{
				Remove();
			}
		}
};

LinkedList* AddNumeric(const LinkedList* listA, const LinkedList* listB)
{
	//This takes two linked lists of numbers and converts them to their number via string, adds them, and then splits the numbers into a new linked list and returns it.
	auto ptrA = listA->getHead();
	auto ptrB = listB->getHead();
	std::string numA, numB;

	while (ptrA != nullptr || ptrB != nullptr)
	{
		if (ptrA != nullptr)
		{
			numA += std::to_string(ptrA->data);
			ptrA = ptrA->next;
		}
		if (ptrB != nullptr)
		{
			numB += std::to_string(ptrB->data);
			ptrB = ptrB->next;
		}
	}
	//Take number strings, convert to num, add together, convert back to string, iterate to make list
	std::string sum = std::to_string(std::stoi(numA) + std::stoi(numB));

	LinkedList* listC = new LinkedList();
	for (auto i = sum.end()-1; i >= sum.begin(); --i)
	{
		listC->Insert((*i) - 48);
	}
	return listC;
}

int main()
{
	LinkedList* listA = new LinkedList();
	listA->Insert(5);
	listA->Insert(1);
	listA->Insert(3);

	LinkedList* listB = new LinkedList();
	listB->Insert(2);
	listB->Insert(9);
	listB->Insert(5);

	LinkedList* listC = AddNumeric(listA, listB);
	listC->Test();

	delete listA;
	delete listB;
	delete listC;
	return 0;
}
