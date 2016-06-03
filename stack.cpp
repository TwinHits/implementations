#include <vector>
#include <algorithm> 
#include <iostream>

class Stack 
{
	private:
		std::vector<int> stack;
	public:
		Stack() {}
		~Stack() {}
		void push(int input) 
		{
			stack.push_back(input);
		}		
		int pop()
		{
			if (!stack.empty())
			{
				int i = stack.back();
				stack.erase(stack.end() - 1);
				return i;
			}
			return 0;
		}
		int peek()
		{
			if (!stack.empty())
			{
				int i = stack.back();
				return i;
			}
			return 0;
		}
		int size()
		{
			return stack.size();
		}
		void stackTest()
		{
			for (auto i = stack.end() - 1; i != stack.begin(); --i)
			{
				std::cout << *i << std::endl;
			}
		}
};

class SetOfStacks
{
	private:
		std::vector<Stack> Set;
		int threshold;
		std::vector<Stack>::iterator ActiveStack = Set.begin();
	public:
		SetOfStacks(int i)
		{
			threshold = i;
			Stack stack;	
			Set.push_back(stack);
			ActiveStack = Set.begin();
		}
		~SetOfStacks() {}
		void push(int i) 
		{
			if (ActiveStack->size() < threshold)
			{
				ActiveStack->push(i);
			}
			else 
			{
				Stack stack;
				Set.push_back(stack);
				ActiveStack = Set.end() - 1;
				ActiveStack->push(i);
			}
		}
		int pop() 
		{
			if (!Set.empty())
			{
				int i = ActiveStack->pop();
				if (ActiveStack->size() == 0)
				{
					Set.erase(ActiveStack);
					ActiveStack = Set.end() - 1;	
				}
				return i;
			} 
			return 1;
		}
		int popAt(unsigned int index)
		{
			if (index < 0 || index > Set.size())
				return 0;

			ActiveStack = Set.begin() + index;
			int ret = this->pop();
			ActiveStack = Set.end() - 1;
			return ret;
		}
};

void TowerOfHanoi(const int n, Stack& fromTower, Stack& toTower, Stack& spareTower)
{
	if(n>0)
    {
		TowerOfHanoi((n-1), fromTower, spareTower, toTower);
		toTower.push(fromTower.pop());
		TowerOfHanoi((n-1), spareTower, toTower, fromTower);
	}
}

int main()
{
	Stack A;
	Stack B;
	Stack C;

	for (int i = 4; i > 0;--i)
	{
		A.push(i);
	}

	A.stackTest();

	TowerOfHanoi(4, A, C, B);

	C.stackTest();

	return 0;
}
