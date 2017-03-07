#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
template<typename T>
class TreeNode
{
   // friend class Tree;
    public:
        T data;
        TreeNode<T> *firstChild,*nextBrother;
        TreeNode(T value = 0,TreeNode<T>*L = 0,TreeNode<T> *R = 0):data(value),firstChild(L),nextBrother(R)
            {}
};



#endif // TREENODE_H_INCLUDED
