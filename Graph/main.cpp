#include"graph_in_matrix.h"
#include"graph_in_adjacent.h"

int main()
{
	Graph_in_matrix<int> matrix;
	

	matrix.create();
	matrix.print_degree();
	
	cout<<"�������ڽӱ���ͼ��\n";
	Graph_in_adjacent<int> adj;
	adj.print_degree();
	
	cout<<"\n��������ȱ���Ϊ��\n";
	adj.depth_first_search();
	cout<<"\n�������ȱ���Ϊ��\n";
	adj.breadth_first_search();
	return 0;
}