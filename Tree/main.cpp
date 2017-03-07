
#include"Tree.h"

int main()
{
    Tree<int> tree;
    tree.creatTree();
	cout<<"此树的先根遍历次序是：\n";
	tree.preOrder();
	cout<<endl;
	char flag = 'y';
	while(flag == 'y'||flag == 'Y'){
	int father,child;
	cout<<"请输入想要插入新结点处的父结点：";
	cin>>father;
	if(tree.find(father))
	{
		cout<<"请输入想要插入的子结点:";
		cin>>child;
		cout<<"插入后此树先根遍历次序是：\n";
		tree.insertChild(child);
		tree.reset();
		tree.preOrder();
		cout<<endl<<endl;
	}
	else
	{
		cout<<"该结点不在此树中。\n";
	}
	
	cout<<"请输入要删除的结点的父结点：";
	cin>>father;
	if(tree.find(father))
	{
		cout<<"请输入要删除该父结点的第几个子结点：";
		cin>>child;
		tree.deleteChild(child);
		tree.reset();
		cout<<"删除该结点后，先根遍历次序是：\n";
		tree.preOrder();
		cout<<endl<<endl;
	}
	else
	{
		cout<<"该结点不在此树中。\n";
	}
	cout<<"是否继续（y.是 其他.否  ）";
	cin>>flag;
	}

    return 0;
}
