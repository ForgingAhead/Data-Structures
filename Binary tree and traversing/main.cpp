#include"BinTree.h"
int main()
{
	BinTree<int> bintree;
	bintree.creat_BinTree();

	bintree.postorder();//
	bintree.inorder();//
	bintree.preorder();//

	cout<<endl<<"���еĽ����Ϊ��"<<bintree.total_node_number()<<endl;

	return 0;
}