#ifndef BINTREENODE
#define BINTREENODE
#include<iostream>
using namespace std;
template<typename T>
class BinTreeNode
{
private:
	T data;
	BinTreeNode<T>* left, *right;

public:
	BinTreeNode<T>* get_left(){return left;}
	BinTreeNode<T>* get_right(){return right;}
	T get_data(){return data;}
	friend ostream& operator<<(ostream& out, BinTreeNode<T>& current)
	{   if(&current != 0)
            return 	out<<current.get_data();
		else
			return out<<"·ÃÎÊNULL½áµã!\n";
	}
	BinTreeNode(T data,BinTreeNode<T>* left = 0,BinTreeNode<T> *right = 0)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
	void set_data(T data)
	{
		this->data = data;
	}
	void set_left(BinTreeNode<T>* left)
	{
		this->left = left;
	}
	void set_right(BinTreeNode<T>* right)
	{
		this->right = right;
	}
};
#endif