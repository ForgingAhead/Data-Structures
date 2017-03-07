#include"linkedList.h"
#include"stack.h"
//#include<iostream>
//#define N 5
void selectItem(Stack<int> & s, int n) ;
int main()
{
	LinkedList<int> list20;
	int N;
	cout<<"请输入要创建链表的长度：";
	cin>>N;
	int * array = new int[N];
	cout<<"请依次输入结点值：\n";
	for(int i = 0; i < N; i++)
	{
		cin>>array[i];
		list20.insert_rear(array[i]);//依次插入
	}
	//list20.delete_after();

	std::cout<<"排序后的链表：\n";
	list20.sort();
	list20.print();	

	int temp;
	std::cout<<"请输入一个整型数，以将其按大小次序插入链表：";
	std::cin>>temp;

	list20.insert_by_order(temp);
	list20.print();

	std::cout<<"\n颠倒链表：\n";
	list20.reverse();
	list20.print();
	
	Stack<int> stack;
	for(int j = 0; j < N; j++)
		stack.push(array[j]);
	std::cout<<"\n现在新建立的堆栈中的元素依次为：\n";
	stack.print_stack();
	std::cout<<"请输入要查找的元素，若在堆栈中，则移至栈顶，其他元素顺序不变： ";
	std::cin>>temp;
	selectItem(stack, temp);
	stack.print_stack();
	

	delete [] array;
	return 0;
}



void selectItem(Stack<int> & s, int n) 
{
	int pos = s.find_position(n);
	if(pos == -1)
	{
		std::cout<<"此堆栈中没有该元素！\n";
	}else{
		Stack<int> temp;
		for(int i = 0;i < pos;i++)
			temp.push(s.pop());
		temp.pop();
		for(int j = 0;j < pos - 1;j++)
			s.push(temp.pop());
		s.push(n);
	}
}
