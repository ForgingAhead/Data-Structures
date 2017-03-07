#ifndef QUEUE
#define QUEUE
#include"linkedList.h"

template<typename T>
class Queue
{
	private:
		LinkedList<T> queueList;
	public:
		Queue();
		void q_insert(const T& elt);
		T q_delete();
		T q_front()const;
		int q_length()const{return queueList.get_size();};
		int q_empty(){return queueList.is_empty();};
		void q_clear();
};

template<typename T>
Queue<T>::Queue()
{
	;
}

template<typename T>
void Queue<T>::q_insert(const T& elt)
{
	queueList.insert_rear(elt);
}

template<typename T>
T Queue<T>::q_delete()
{
	if(queueList.is_empty())
	{
		cout<<"此队列是一个空队列!\n";
		exit(1);
	}
	queueList.reset();
	queueList.next();
	return queueList.delete_front();
}


template<typename T>
T Queue<T>::q_front()const
{
	if(queueList.is_empty())
	{
		cout<<"此队列是一个空队列!\n";
		exit(1);
	}
	queueList.reset();
	return queueList.get_data();
}

template<typename T>
void Queue<T>::q_clear()
{
	queueList.clearList();
}


#endif