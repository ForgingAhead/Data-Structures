#ifndef BINTREE
#define BINTREE
#include"BinTreeNode.h"
#include"Stack.h"
template<typename T>
class BinTree
{
private:
	BinTreeNode<T>* root;//ָ������
	int stop;  //��־�������ֹ
	BinTreeNode<T>* find_father(BinTreeNode<T>* begin, BinTreeNode<T>* currptr);
	BinTreeNode<T>* find(BinTreeNode<T>* currptr, const T item);
	BinTreeNode<T>* creat_BinTree(int empty);
	void preorder(BinTreeNode<T>* currptr, ostream& out)const;//�ȸ�����
	void inorder(BinTreeNode<T>* currptr, ostream& out)const;//�и�����
	void postorder(BinTreeNode<T>* currptr, ostream& out)const;//�������
	int total_node_number(BinTreeNode<T>* currptr);
public:
	BinTree():root(0){}
	BinTree(int mark):stop(mark),root(0){}
	void creat_BinTree();
	~BinTree(){delete_subtree(root);}

	void insert_on_left(BinTreeNode<T>* currptr, const T item);
	void insert_on_right(BinTreeNode<T>* currptr, const T item);
	void delete_subtree(BinTreeNode<T>* ptr);
	void delete_node(BinTreeNode<T>* ptr);

	BinTreeNode<T>* find_father(BinTreeNode<T>* ptr);
	BinTreeNode<T>* find_last_right(BinTreeNode<T>* ptr);
	BinTreeNode<T>* find_last_left(BinTreeNode<T>* ptr);
	BinTreeNode<T>* find(const T item);

	BinTreeNode<T>* get_leftChild(BinTreeNode<T>* ptr){if(ptr != 0)return ptr->get_left();}
	BinTreeNode<T>* get_rightChild(BinTreeNode<T>* ptr){if(ptr != 0)return ptr->get_right();}
	T get_data(BinTreeNode<T>* ptr){return ptr->get_data();}
	BinTreeNode<T>* get_root(){return root;}
	int is_empty(){return root == 0;}

	void preorder();
	void inorder();
	void postorder();

	int total_node_number();

};
template<typename T>
void BinTree<T>::insert_on_left(BinTreeNode<T>* currptr, const T item)
{
	if(currptr != 0)
	{
		BinTreeNode<T>* ptr = new BinTreeNode<T>(item);
		BinTreeNode<T>* temp = currptr->get_left();
		currptr->set_left(ptr);
		ptr->set_left(temp);
	}
}

template<typename T>
void BinTree<T>::insert_on_right(BinTreeNode<T>* currptr, const T item)
{
	if(currptr != 0)
	{
		BinTreeNode<T>* ptr = new BinTreeNode<T>(item);
		BinTreeNode<T>* temp = currptr->get_right();
		currptr->set_right(ptr);
		ptr->set_right(temp);
	}
}

template<typename T>
void BinTree<T>::delete_subtree(BinTreeNode<T>* ptr)
{
	if(ptr != 0)
	{
		delete_subtree(ptr->get_left());
		delete_subtree(ptr->get_right());
		BinTreeNode<T>* temp = find_father(ptr);
		if(temp != 0)
		{
			if(temp->get_left() == ptr)
				temp->set_left(0);
			else temp->set_right(0);
		}
		delete ptr;
	}
}

template<typename T>
void BinTree<T>::delete_node(BinTreeNode<T>* ptr)
{
	if(ptr != 0)
	{
		BinTreeNode<T>* temp = find_father(ptr);
		if(temp->get_left() == ptr)
		{
			temp->set_left(ptr->get_left());
			BinTreeNode<T>* right = ptr->get_right();
			if(right != 0)
				(find_last_right(ptr->get_left()))->set_right(right);
		}
		else
		{
			temp->set_right(ptr->get_right());
			BinTreeNode<T>* left = ptr->get_left();
			if(left != 0)
				find_last_left(ptr->get_right())->set_left(left);
		}
		delete ptr;
	}
}

template<typename T>
BinTreeNode<T>* BinTree<T>::find_father(BinTreeNode<T>* ptr)
{
	if(ptr == 0 ||ptr == root)return 0;
	return find_father(root, ptr);
}

template<typename T>
BinTreeNode<T>* BinTree<T>::find_father(BinTreeNode<T>* begin, BinTreeNode<T>* ptr)
{
	if(begin == 0)return 0;
	if((begin->get_left() == ptr)||(begin->get_right() == ptr))return begin;
	BinTreeNode<T>* temp;
	if((temp = find_father(begin->get_left(), ptr)) != 0)
		return temp;
	else
		return find_father(root->get_right(), ptr);
}

template<typename T>
BinTreeNode<T>* BinTree<T>::find(const T item)
{
	return find(root, item);
}

template<typename T>
BinTreeNode<T>* BinTree<T>::find(BinTreeNode<T>* currptr, const T item)
{
	if(currptr != 0)
	{	BinTreeNode<T>* temp;
		if(currptr->get_data() == item)
			return currptr;
		else if((temp = find(currptr->get_left(), item)) != 0)
			return temp;
		else return find(currptr->get_right(), item);
	}
	return 0;
}

template<typename T>
BinTreeNode<T>* BinTree<T>::find_last_left(BinTreeNode<T>* ptr)//ò���д�ȡ����ʵ�ʰ�~~~
{
	if(ptr->get_left() == 0)return ptr;
	return find_last_left(ptr->get_left());
}

template<typename T>
BinTreeNode<T>* BinTree<T>::find_last_right(BinTreeNode<T>* ptr)
{
	if(ptr->get_right() == 0)return ptr;
	return find_last_right(ptr->get_right());
}

template<typename T>
void BinTree<T>::preorder()
{
    cout<<"�˶������ȸ������Ľ��Ϊ��\n";
	preorder(root, std::cout);
	std::cout<<std::endl;
}

template<typename T>
void BinTree<T>::inorder()
{
	inorder(root, std::cout);
	std::cout<<std::endl;
}

template<typename T>
void BinTree<T>::postorder()
{
	postorder(root,std::cout);
	std::cout<<std::endl;
}

template<typename T>
void BinTree<T>::preorder(BinTreeNode<T>* currptr, ostream& out)const
{
	if(currptr != 0){
		out<<(*currptr).get_data()<<"  ";
		preorder(currptr->get_left(),out);
		preorder(currptr->get_right(), out);
	}
}

template<typename T>
void BinTree<T>::inorder(BinTreeNode<T>* currptr, ostream& out)const
{
/*�ݹ��㷨
	cout<<"�˶������и������Ľ��Ϊ��\n";
	if(currptr != 0)
	{
		inorder(currptr->get_left(), out);
		out<<(*currptr)<<"  ";
		inorder(currptr->get_right(), out);
	}
*/
//�ǵݹ��㷨
	BinTreeNode<T>* p = root;
	Stack<BinTreeNode<T>*> stack;
	cout<<"�˶������и������Ľ��Ϊ��\n";
	while(!stack.is_empty() || p )
	{
                  //�Ӹ��ڵ㿪ʼ������ߵ�Ҷ�ӽڵ㣬��ջ
		while (p != 0)
		{
			stack.push(p);
			p = p->get_left();
		}
		p = stack.pop();
		cout<<p->get_data()<<"  "; //���ʽڵ�
		p = p->get_right(); //��һ��ѭ���ѽڵ�p����������ջ
	}
	cout<<endl;
}

template<typename T>
void BinTree<T>::postorder(BinTreeNode<T>* currptr, ostream& out)const
{
/*
	cout<<"�˶�������������Ľ��Ϊ��\n";
	if(currptr != 0)
	{
		postorder(currptr->get_left(), out);
		postorder(currptr->get_right(), out);
		out<<(*currptr)<<"  ";
	}
*/
//�ǵݹ��㷨
    cout<<"�˶�������������Ľ��Ϊ��\n";
	Stack<BinTreeNode<T>*> s;
	BinTreeNode<T>* p = root;
	BinTreeNode<T>* pre = 0;
	while(p || !s.is_empty())
	{
		while(p)
		{
			s.push(p);
			p = p->get_left();
		}
		p = s.peek();
		if(p && (p->get_right() == 0 || p->get_right() == pre))
		{
			cout<<(*p).get_data()<<"  ";
			s.pop();
			pre = p;
			p = 0;
		}
		else
		{
			p = p->get_right();
		}
	}
	cout<<endl;
}

template<typename T>
void BinTree<T>::creat_BinTree()
{
	cout<<"������һ����������־�ý��Ϊ�գ�\n";
	cin>>stop;
	cout<<"�밴Ҫ�����룬�Դ���������������" <<stop<<" ��־�ý��Ϊ�գ�\n";
	root = creat_BinTree(stop);

}

template<typename T>
BinTreeNode<T>* BinTree<T>::creat_BinTree(int stop)
{
	T data;
	cin>>data;
	BinTreeNode<T>* temp;
		if(data != stop)
		{
			temp = new BinTreeNode<T>(data);
			temp->set_left(creat_BinTree(stop));
			temp->set_right(creat_BinTree(stop));
		}else
			temp = 0;
	return temp;

}

template<typename T>
int BinTree<T>::total_node_number()
{
	if(root != 0)
	{
		int left = total_node_number(root->get_left());
		int right = total_node_number(root->get_right());
		return left + right + 1;
	}
	return 0;
}


template<typename T>
int BinTree<T>::total_node_number(BinTreeNode<T>* currptr)
{
	if(currptr != 0)
	{
		int left = total_node_number(currptr->get_left());
		int right = total_node_number(currptr->get_right());
		return left + right + 1;
	}
	return 0;
}

#endif