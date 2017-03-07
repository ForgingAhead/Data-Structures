#ifndef GRAPH_IN_MATRIX
#define GRAPH_IN_MATRIX
#include"linkedList.h"

const int MaxGraphSize = 20;
template<typename T>
class Graph_in_matrix
{
private:
	LinkedList<T> vertexList;
	int edge[MaxGraphSize][MaxGraphSize];//邻接矩阵
	int graphsize;     //表示总的顶点个数
	int find_vertex(LinkedList<T>& list, const T& vertex);//检查顶点vertex是否已经在顶点表list中
	int get_vertex_pos(const T & vertex);
public:
	Graph_in_matrix();
	int graph_empty()const{return vertexList.is_empty();}
	int graph_full()const{return graphsize == MaxGraphSize;}
//以下是访问数据的方法
	int number_of_vertex()const;//
	int number_of_edges()const;//
	int get_weight(const T& vertex1,const T& vertex2);//
	LinkedList<T>& get_neighbors(const T& vertex);//
	int get_first_neighbor(const int v);
	int get_next_neighbor(const int v1,const int v2);//返回序号v1相对于序号v2的下一个邻接顶点的序号
//以下是修改图的方法
	void insert_vertex(const T& vertex);
	void insert_edge(const T& vertex1,const T& vertex2,int weight);
	void delete_vertex(const T& vertex);
	void delete_edge(const T& vertex1,const T& vertex2);
//以下是例程
	void create();//输入图的边和顶点
	int minimum_path(const T& startv,const T& endv);//返回两个顶点间的最小路径长度
	void depth_first_search(const T& v,int visited[]);//从指定顶点开始进行深度优先搜索
	void depth_first_search();//从顶点表的第一个顶点开始进行深度优先遍历
	void breadth_first_search(const T& v,int visited[]);//从指定顶点开始进行广度优先搜索
	void breadth_first_search();//从顶点表的第一个顶点开始进行广度优先遍历
	friend class VertexIterator;//

	void print_degree();
};

template<typename T>
Graph_in_matrix<T>::Graph_in_matrix()
{
	for(int i = 0;i < MaxGraphSize;i++)
		for(int j = 0;j < MaxGraphSize;j++)
			edge[i][j] = 0;
	graphsize = 0;
}

template<typename T>
int Graph_in_matrix<T>::find_vertex(LinkedList<T>& list, const T& vertex)
{
	if(list.find_data(vertex) == 0)
		return 0;
	else return 1;
}

template<typename T>
int Graph_in_matrix<T>::get_vertex_pos(const T& vertex)
{
	int pos;
	while(!vertexList.is_empty() && vertexList.get_data() != vertex)
	{
		pos++;
		vertexList.next();
	}
	if(!vertexList.is_empty())
		return pos;
	else return -1;
}

template<typename T>
int Graph_in_matrix<T>::number_of_vertex()const
{
	return graphsize;
}

template<typename T>
int Graph_in_matrix<T>::number_of_edges()const
{
	int count = 0;
	for(int i = 0;i < MaxGraphSize;i++)
		for(int j = 0;j < MaxGraphSize;j++)
			if(edge[i][j] != 0)
				count++;
	return count;
}

template<typename T>
int Graph_in_matrix<T>::get_weight(const T& vertex1,const T& vertex2)
{
	if((vertex1 < MaxGraphSize) && (vertex2 < MaxGraphSize) && (vertex1 > -1) && (vertex2 > -1))
		return edge[vertex1][vertex2];
	else 
	{
		std::cout<<"顶点并未在此图中！\n";
		return 0;
	}
}

template<typename T>
int Graph_in_matrix<T>::get_first_neighbor(const int v)
{	
	for(int i = 0;i < MaxGraphSize;i++)
		if(edge[v][i] != 0)
			return i;
	return -1;
}

template<typename T>
int Graph_in_matrix<T>::get_next_neighbor(const int v1,const int v2)
{
	if(v1 != -1 && v2 != -1 )
	{
		for(int i = v2 + 1;i < graphsize;i++)
			if(edge[v1][i] > 0)
				return i;
	}
	return -1;
}

template<typename T>
LinkedList<T>& Graph_in_matrix<T>::get_neighbors(const T& v)
{
	LinkedList<T> *list = new LinkedList<T>();
	for(int i = 0;i < MaxGraphSize;i++)
		if(edge[v][i] != 0)
			list.insert_rear(i);
	return *list;
}

template<typename T>
void Graph_in_matrix<T>::insert_edge(const T& vertex1,const T& vertex2,int weight)
{
	if((vertex1 < MaxGraphSize) && (vertex2 < MaxGraphSize) && (vertex1 > -1) && (vertex2 > -1) && (weight > 0))
		edge[vertex1][vertex2] = weight;
}

template<typename T>
void Graph_in_matrix<T>::insert_vertex(const T&  vertex)
{
	if(graphSize < MaxGraphSize)
	{
		if(find_vertex(vertexList,vertex) == 0)
		{
			vertexList.insert_by_order(vertex);
			graphSize++;
		}
		else
		{
			std::cout<<"该顶点已经在图中!\n";
		}
	}
	else
	{
		std::cout<<"图中顶点个数已经超过规定的顶点个数的上界!\n";
	}
}

template<typename T>
void Graph_in_matrix<T>::delete_vertex(const T& vertex)
{
	int pos,row,col;
	if((pos = get_vertex_pos(vertex)) == -1)
		std::cout<<"该顶点不在此图中。\n";
	else
	{
		vertexList.delete_data(vertex);
		graphSize--;
		for(row = 0;row < pos;row++)
			for(col = pos + 1;col <= graphsize;col++)
				edge[row][col - 1] = edge[row][col];
		for(row = pos + 1;row <= graphsize;row++)
			for(col = 0;col < pos;col++)
				edge[row - 1][col] = edge[row][col];
		for(row = pos + 1;row <= graphsize;row++)
			for(col = pos + 1;col <= graphsize;col++)
			edge[row - 1][col - 1] = edge[row][col];
	}
}


template<typename T>
void Graph_in_matrix<T>::create()
{
	int number,i ,j,data;
	T vertex;
	cout<<"请按要求输入以创建图的邻接矩阵。\n";
	cout<<"请输入总的顶点个数：";
	cin>>number;
	graphsize = number;
	cout<<"请依次输入各顶点：\n";
	for(i = 0;i < number;i++)
	{
		cin>>vertex;
		vertexList.insert_rear(vertex);
	}
	cout<<"请依次按实际邻接矩阵的行列值输入：\n";
	for(i = 0;i < number;i++)
	{
		cout<<"请输入第 "<<i + 1<<" 行所对应的值：\n";
		for(j = 0;j < number;j++)
		{
			cin>>data;
			edge[i][j] = data;
		}
	}
	cout<<"邻接矩阵创建成功 !\n";
}

template<typename T>
void Graph_in_matrix<T>::print_degree()
{
	vertexList.reset();
	for(int i = 0;i < graphsize;i++)
	{
		int count = 0;
		cout<<"顶点 "<<vertexList.get_data()<<" 的度为 ：";
		for(int j = 0;j < graphsize;j++)
		{
			if(edge[i][j] != 0)
				count++;
		}
		cout<<count<<endl;
		vertexList.next();
	}
}


template<typename T>
void Graph_in_matrix<T>::delete_edge(const T& vertex1,const T& vertex2)
{
	if((vertex1 < MaxGraphSize) && (vertex2 < MaxGraphSize) && (vertex1 > -1) && (vertex2 > -1))
		edge[vertex1][vertex2] = 0;
}
//返回两个顶点间的最小路径
template<typename T>
int Graph_in_matrix<T>::minimum_path(const T& startv,const T& endv)
{

;
}
//从指定顶点开始深度优先搜索
template<typename T>
void Graph_in_matrix<T>::depth_first_search(const T& v,int visited[])
{
;
}

template<typename T>
void Graph_in_matrix<T>::depth_first_search()
{

;
}


template<typename T>
void Graph_in_matrix<T>::breadth_first_search()
{
;
 
}
//
template<typename T>
void Graph_in_matrix<T>::breadth_first_search(const T& v,int visited[])
{
;
}

#endif	