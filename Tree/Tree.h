#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include<iostream>
using namespace std;
#include"TreeNode.h"
template<typename T>
class Tree
{
    private:
        TreeNode<T>*root,*current;
        void preOrder(TreeNode<T>*p ,ostream & out);
        int find(TreeNode<T>*p,T target);
        int findFather(TreeNode<T>*t,TreeNode<T>*p);
        void delSubtree(TreeNode<T>*p);
    public:
        Tree(){root = current = 0;}
		~Tree(){delSubtree(root);}
        void creatTree();
        void insertChild(T value);
        void deleteChild(int i);
        int find(T target);
        int father();
        int is_empty(){return (current == 0)&&(root == 0);}
		int firstChild();
		int nextBrother();
		void preOrder();
		void reset(){current = root;}
};

template<typename T>
int Tree<T>::firstChild()
{
	if(current != 0 && current->firstChild != 0)
	{
		current = current->firstChild;
		return 1;
	}
	current = 0;
	return 0;
}

template<typename T>
int Tree<T>::nextBrother()
{
	if(current && current->nextBrother != 0)
	{
		current = current->nextBrother;
		return 1;
	}
	current = 0;
	return 0;
}

template<typename T>
void Tree<T>::preOrder()
{
	if(!is_empty())
		{
			std::cout<<current->data<<"  ";
			TreeNode<T> *p = current;
			int k = firstChild();
			while(k)
			{
				preOrder();
				k = nextBrother();
			}
			current = p;
		}
}

template<typename T>
void Tree<T>::preOrder(TreeNode<T> *p,ostream &out)
{
	
}


template<typename T>
int Tree<T>::findFather(TreeNode<T>*t,TreeNode<T> *p)
{
    TreeNode<T> *q = t->firstChild;
    while(q != 0 && q != p)
    {
        if(findFather(q,p) == 1)
            return 1;
        q = q->nextBrother;
    }
    if(q == p)
    {
        current = t;
        return 1;
    }
    else
        return 0;
}

template<typename T>
int Tree<T>::father()
{
    TreeNode<T> *p = current, *t;
    if(current || current == root)
    {
        current = 0;
        return 0;
    }
    t = root;
    return findFather(t,p);
}

template<typename T>
int Tree<T>::find(TreeNode<T> *t,T target)
{
    if(t->data == target)
    {
        current = t;
        return 1;
    }
    else
    {
        TreeNode<T> *p = t->firstChild;
        while(p && find(p,target) != 1)
        {
            p = p->nextBrother;
        }
        if(p)return 1;
    }
    return 0;

}

template<typename T>
int Tree<T>::find(T target)
{
    if(is_empty())
        return 0;
    return find(root,target);
}

template<typename T>
void Tree<T>::delSubtree(TreeNode<T>* p)
{
    if(p)
    {
        TreeNode<T>*q = p->firstChild,*next;
        while(q)
        {
            next = q->nextBrother;
            delSubtree(q);
            q = next;
        }
        delete p;
    }
}

template<typename T>
void Tree<T>::creatTree()
{
    T data;
    int num = 0/*记录该输入子结点的结点*/,number/*总的结点数*/,count1 = 0/*记录指针位置*/ ;
    int count = 0/*记录当前输入的是哪个结点*/;
    TreeNode<T>*p = 0,*q = 0;
    std::cout<<"输入依次输入各结点 0 代表该结点为空，请按要求输入，以创建树.\n";
    std::cout<<"请输入总的结点数：";
    std::cin>>number;
    T* array = new T[number];
    TreeNode<T>** ptr = new TreeNode<T>*[number];
    std::cout<<"请输入根节点：";
    std::cin>>data;
    if(data != 0)
    {
        array[count] = data;
        p = root = new TreeNode<T>(data);
        ptr[count1++] = p;
        while(1)
        {
            if(num < number)
            {
                std::cout<<"请依次输入结点 "<<array[num++]<<" 的子结点：";
                std::cin>>data;
                if(data)
                {
                    ptr[num - 1]->firstChild = q = new TreeNode<T>(data);
                    ptr[count1++] = q;
                    array[++count] = data;
					std::cin>>data;
                    while(data)
                    {
                        q->nextBrother = new TreeNode<T>(data);
                        q = q->nextBrother;
                        ptr[count1++] = q;
                        array[++count] = data;
						std::cin>>data;
                    }
                }
            }else break;
        }
    }
	cout<<"成功创建此树。\n";
	current = root;////////////////////////
	delete array;
	delete ptr;
}

template<typename T>
void Tree<T>::insertChild(T value)
{
    if(!is_empty())
    {
        TreeNode<T>* temp = new TreeNode<T>(value);
        TreeNode<T>* last = current->firstChild;
        if(last)
        {
            while(last->nextBrother)
                last = last->nextBrother;
            last->nextBrother = temp;
        }
        else
        current->firstChild = temp;
    }
}

template<typename T>
void Tree<T>::deleteChild(int i)
{
    if(!is_empty())
    {
        TreeNode<T> *p = current->firstChild ,*last = p;
        while(p && (i - 1))
        {
            last = p;
            p = p->nextBrother;
            i--;
        }
        if(p)
        {
            if(p == current->firstChild)
            {
                current->firstChild = p->nextBrother;
				delSubtree(p);            
            }
            else
            {
                last->nextBrother = p->nextBrother;
                delSubtree(p);
            }
        }
    }

}

#endif // TREE_H_INCLUDED
