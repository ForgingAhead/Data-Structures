
#include"Tree.h"

int main()
{
    Tree<int> tree;
    tree.creatTree();
	cout<<"�������ȸ����������ǣ�\n";
	tree.preOrder();
	cout<<endl;
	char flag = 'y';
	while(flag == 'y'||flag == 'Y'){
	int father,child;
	cout<<"��������Ҫ�����½�㴦�ĸ���㣺";
	cin>>father;
	if(tree.find(father))
	{
		cout<<"��������Ҫ������ӽ��:";
		cin>>child;
		cout<<"���������ȸ����������ǣ�\n";
		tree.insertChild(child);
		tree.reset();
		tree.preOrder();
		cout<<endl<<endl;
	}
	else
	{
		cout<<"�ý�㲻�ڴ����С�\n";
	}
	
	cout<<"������Ҫɾ���Ľ��ĸ���㣺";
	cin>>father;
	if(tree.find(father))
	{
		cout<<"������Ҫɾ���ø����ĵڼ����ӽ�㣺";
		cin>>child;
		tree.deleteChild(child);
		tree.reset();
		cout<<"ɾ���ý����ȸ����������ǣ�\n";
		tree.preOrder();
		cout<<endl<<endl;
	}
	else
	{
		cout<<"�ý�㲻�ڴ����С�\n";
	}
	cout<<"�Ƿ������y.�� ����.��  ��";
	cin>>flag;
	}

    return 0;
}
