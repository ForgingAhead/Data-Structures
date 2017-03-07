#include"graph_in_matrix.h"
#include"graph_in_adjacent.h"

int main()
{
	Graph_in_matrix<int> matrix;
	

	matrix.create();
	matrix.print_degree();
	
	cout<<"现在用邻接表创建图：\n";
	Graph_in_adjacent<int> adj;
	adj.print_degree();
	
	cout<<"\n其深度优先遍历为：\n";
	adj.depth_first_search();
	cout<<"\n其广度优先遍历为：\n";
	adj.breadth_first_search();
	return 0;
}