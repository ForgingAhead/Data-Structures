#ifndef NODE
#define NODE

#include<iostream>
using namespace std;

template<typename T>
class Node{
private :
	Node<T>* next;
	T data;
public :
	Node<T>* next_node();
	void set_next(Node<T>* ptr);
	void insert_after(Node<T>* p);
	Node<T>* delete_after();	//删除当前结点的后继结点，并返回被删结点的指针
	T get_data(){return data;}
	Node(T data);

};


template<typename T>
Node<T>:: Node(T data)
{
	this->data = data;
	next = 0;
}

template<typename T>
void Node<T>::set_next(Node<T>* ptr)
{
	next = ptr;
}

template<typename T>
Node<T>* Node<T>:: next_node()
{
	return next;
}

template<typename T>
void Node<T>:: insert_after(Node<T>* p)
{
	p->set_next( next);
	next = p;
}

template<typename T>
Node<T>* Node<T>:: delete_after()
{
	if(next != 0)
	{
		Node<T>* temp = next;
		next = temp->next_node();
		return temp;
	}
	return 0;
}

#endif