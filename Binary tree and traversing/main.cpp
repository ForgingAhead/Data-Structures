#include"BinTree.h"
int main()
{
	BinTree<int> bintree;
	bintree.creat_BinTree();

	bintree.postorder();//
	bintree.inorder();//
	bintree.preorder();//

	cout<<endl<<"所有的结点数为："<<bintree.total_node_number()<<endl;

	return 0;
}