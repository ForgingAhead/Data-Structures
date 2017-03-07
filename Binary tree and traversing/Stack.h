#ifndef STACK
#define STACK
#include"LinkedList.h"
template<class T>
class Stack
{
private:
	LinkedList<T> stackList;
	int top;
public:
	Stack();
	void push(T item);
	T pop();
	void clearStack();
	T peek();
	int is_empty()const;
	int length()const;
	int find_position(T key);
	void print_stack();
};

template<typename T>
Stack<T>::Stack()
{
	top = -1;
}

template<typename T>
void Stack<T>::push(T item)
{
	stackList.insert_front(item);
	top++;
}

template<typename T>
T  Stack<T>::pop()
{
	if(top != -1)
	{
		T temp = stackList.get_data();
		top--;////////////////////////////////////////
		stackList.delete_at();
		return temp;
	}
	/*else
	{
		std::cout<<"当前堆栈为空！\n";
		return ;
	}*/
}

template<typename T>
T Stack<T>::peek()
{
	if(top != -1)
	{
		return stackList.get_data();
	}/*
	else
	{
		std::cout<<"当前堆栈为空！\n";
		return ;
	}*/
}


template<typename T>
int Stack<T>::is_empty()const
{
	return top == -1;
}

template<typename T>
int Stack<T>::length()const
{
	return top + 1;
}

template<typename T>
void Stack<T>::clearStack()
{
	stackList.clearList();
	top = -1;
}

template<typename T>
int Stack<T>::find_position(T key)
{
	int pos = 0;
	Node<T>* p = stackList.get_front();
	while(p != 0)
	{
		pos++;
		if(p->get_data() == key)
			return pos;
		p = p->next_node();
	}
	return -1;
}

template<typename T>
void Stack<T>::print_stack()
{
	stackList.print();
}


#endif