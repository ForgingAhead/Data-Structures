
#ifndef LINKEDLIST
#define LINKEDLIST
#include<stdlib.h>
#include"Node.h"
template<typename T>
class LinkedList{
private:
	Node<T>* front , *rear;
	Node<T>* currptr, *prevptr;
	int size;
	int position;

public:
	LinkedList()
	{
		front = rear = currptr = prevptr = 0;
		size = position =0;
	}
	LinkedList(LinkedList<T> &list);
	bool is_empty();
	void reset();
	void insert_rear(T item);		//在链表尾部插入
	void insert_front(T item);	//在链表首插入
	void insert_by_order(T item);
	void delete_after();	//在当前结点
	void delete_front();	//
	void delete_at();	//
	Node<T>* get_prevptr(){return prevptr;}
	T get_data();
	int get_size(){return size;}
	int get_position(){return position;}
	Node<T>* get_rear(){return rear;}
	Node<T>* get_front(){return front;}
	void clearList();
	void next();
	void sort();
	void print();
	void reverse();
	Node<T>* find_data(T key);
	LinkedList<T>& operator=(LinkedList<T>& list);

};


template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &list)
{
	size = list.get_size();
	prevptr = list.get_prevptr();
	position = list.get_position();
	front = 0;
	rear = 0;
	for(int i = 0;i < list.get_size(); i++) ///???????
	{
		Node<T>* temp = new Node<T>(list.get_data());
		list.next();
		if(front == 0)
		{
			front = temp;
		}
		currptr = temp;
		if(prevptr != 0)
		{
			prevptr->set_next( temp);
		}
		prevptr = temp;
	}
	currptr->set_next( 0);
	rear = currptr;
}

template<class T>
T LinkedList<T>::get_data()
{
	if(currptr == 0)
	{
		std::cout<<"当前结点指针为NULL！无法访问其数据，请重置。\n";
		return 0;
	}else
		return currptr->get_data();
}

template<typename T>
void LinkedList<T>::insert_front(T item)
{
	if(front == 0)
	{
		front = currptr = new Node<T>(item);
		size = 1;
		position = 1;
		prevptr = 0;
		rear = front;
	}
	else
	{
		Node<T>* temp = new Node<T>(item);
		temp->set_next( front);
		front = temp;
		size++;
		prevptr = currptr;
		currptr = temp;
	}

}

template<typename T>
void LinkedList<T>::insert_rear(T item)
{
	if(rear == 0)
	{
		rear = front = currptr = new Node<T>(item);
		size = 1;
		position = 1;
		prevptr = 0;
	}
	else
	{
		Node<T> * temp = new Node<T>(item);
		rear->insert_after(temp);
		rear = temp;
		prevptr = currptr;
		currptr = temp;
		size++;
		position++;
	}
}

template<typename T>
void LinkedList<T>::delete_after()
{
	if(currptr == rear)
	{
		std::cout<<"当前结点已是尾节点，不能删除他的后继结点\n";
	}else if(currptr->next_node() == rear)
	{
		rear = currptr;
		delete currptr->delete_after();
	}else
		delete currptr->delete_after();
	size--;
}

template<typename T>
void LinkedList<T>::delete_at()
{
	if(currptr == front)
	{
		currptr = front->next_node();
		delete front;
		front = currptr;
		prevptr = 0;
		size--;
	}
	else if(currptr != 0)
	{
		prevptr->set_next( currptr->next_node());
		delete currptr;
		currptr = prevptr->next_node();
		size--;
	}
	else
		std::cout<<"当前要删除的结点指针为NULL！\n";
}

template<typename T>
void LinkedList<T>::delete_front()
{
	int data = prevptr->get_data();
	Node<T>* temp = front;
	Node<T>* last = front;
	if(currptr == front)
	{
		std::cout<<"当前结点已是头结点,不能删除他的前驱结点\n";
	}else if(prevptr == front)
	{
		delete front;
		front = currptr;
		prevptr = 0;
		size--;
		position--;
	}else
	{
		for(int i = 0;i < size; i++)
		{
			if(temp->get_data() == data)
				break;
			last = temp;
			temp = temp->next_node();
		}
		last->delete_after();
		last->set_next( currptr);
		size--;
		position--;
	}
}

template<typename T>
bool LinkedList<T>::is_empty()
{
	if(front == 0)
		return true;
	else return false;
}

template<typename T>
void LinkedList<T>::reset()
{
	position = 1;
	currptr = front;
}

template<typename T>
void LinkedList<T>::clearList()
{
	Node<T>* tmp = front;
	Node<T>* next;
	for(int i = 0; i < size; i++)
	{
		next = tmp->next_node();
		delete tmp;
	}
}

template<typename T>
void LinkedList<T>::next()
{
	if(currptr == rear)
	{
		currptr = front;
	}
	else
	{
		prevptr = currptr;
		currptr = currptr->next_node();
	}
	position ++;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list)
{
	LinkedList<T> *temp = new LinkedList();
	temp->position = list.position;
	temp->currptr = list.currptr;
	temp->front = list.front;
	temp->prevptr = list.prevptr;
	temp->rear = list.rear;
	temp->size = list.size;
	return *temp;
}


template<typename T>
void LinkedList<T>::sort()
{
	Node<T> *p,*q,*last;
	int flag = 1,j = 1;
	while(flag)
	{
		p =  front;
		last = front;
		q = p->next_node();
		flag = 0;
		for(int i = 0;i < size - j; i++)
		{
			if(p->get_data() > q->get_data())
			{
				p->set_next(q->next_node());
				q->set_next(p);
				if(p == front)
				{
					front = q;
					last = front;
				}
				if(q == rear)
					rear =p;
				flag = 1;
				if(i != 0)
				{
					last->set_next( q);
					last = q;
				}
				q = p->next_node();
			}
			else
			{
				last = p;
				p = q;
				q = q->next_node();
			}
		}
		j++;
	}
}

template<typename T>
void LinkedList<T>::print()
{
	int count = 0;
	reset();
	for(int jj = 0; jj < size; jj++)
	{
		std::cout<<get_data()<<"  ";
		count++;
		if((count % 9) == 0)
			std::cout<<std::endl;
		next();
	}
	std::cout<<std::endl;
}


template<typename T>
void LinkedList<T>::reverse()
{
	rear = front;
	Node<T> *p = front;
	Node<T> *q = front->next_node();
	Node<T> *r = q->next_node();
	rear->set_next( 0);
	while(r != 0)
	{
		q->set_next(p);
		p = q;
		q = r;
		r = r->next_node();
	}
	q->set_next( p);
	front = q;
}


template<typename T>
void LinkedList<T>::insert_by_order(T item)
{
	size++;
	Node<T>* temp = new Node<T>(item);
	Node<T> *p = front, *last = front;
	while(p != 0)
	{
		if(p->get_data () > item)
		{
			temp->set_next( p);
			if(p == front)
				front = temp;
			else last->set_next( temp);
			break;
		}
		last = p;
		p = p->next_node();
	}
	if(p == 0)
	{
		rear->set_next( temp);
		rear = temp;
	}
}

template<typename T>
Node<T>* LinkedList<T>::find_data(T key)
{
	Node<T>* p = front;
	while(p != 0)
	{
		if(p->get_data() == key)
			break;
		p = p->next_node();
	}
	return p;
}
#endif