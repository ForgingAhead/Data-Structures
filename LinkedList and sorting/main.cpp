#include"linkedList.h"
#include"stack.h"
//#include<iostream>
//#define N 5
void selectItem(Stack<int> & s, int n) ;
int main()
{
	LinkedList<int> list20;
	int N;
	cout<<"������Ҫ��������ĳ��ȣ�";
	cin>>N;
	int * array = new int[N];
	cout<<"������������ֵ��\n";
	for(int i = 0; i < N; i++)
	{
		cin>>array[i];
		list20.insert_rear(array[i]);//���β���
	}
	//list20.delete_after();

	std::cout<<"����������\n";
	list20.sort();
	list20.print();	

	int temp;
	std::cout<<"������һ�����������Խ��䰴��С�����������";
	std::cin>>temp;

	list20.insert_by_order(temp);
	list20.print();

	std::cout<<"\n�ߵ�����\n";
	list20.reverse();
	list20.print();
	
	Stack<int> stack;
	for(int j = 0; j < N; j++)
		stack.push(array[j]);
	std::cout<<"\n�����½����Ķ�ջ�е�Ԫ������Ϊ��\n";
	stack.print_stack();
	std::cout<<"������Ҫ���ҵ�Ԫ�أ����ڶ�ջ�У�������ջ��������Ԫ��˳�򲻱䣺 ";
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
		std::cout<<"�˶�ջ��û�и�Ԫ�أ�\n";
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
