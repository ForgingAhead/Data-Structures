#include"queue.h"
#include<iostream>
using namespace std;
const int Default = 10;

//template<typename T>
//class Graph_in_adjacent<T>;

//template<typename T>
struct Edge
{
	//friend class Graph_in_adjacent<T>;
	int verAdj;
	int cost;
	Edge* link;
	Edge();
	Edge(int d,int c):verAdj(d),cost(c),link(0){}
	int operator !=(const Edge& e)const {return verAdj != e.verAdj;}
};

template<typename T>
struct Vertex
{
//	friend class Graph_in_adjacent<T>;
	T verName;
	Edge* adjacent;
};

template<typename T>
class Graph_in_adjacent
{
public:
	Vertex<T>* head;
	int graphsize;
	int MaxGraphSize;
	int numEdge;
	int MaxNumEdge;
	int get_vertex_pos(const T& vertex);
	T get_name(int v){return head[v].verName;}
public:
	Graph_in_adjacent(int sz = Default);
	~Graph_in_adjacent();

	int graph_empty()const{return graphsize == 0;}
	int graph_full()const{return graphsize == MaxGraphSzie || numEdge ==MaxNumEdge;}
//以下是访问数据的方法
	int number_of_vertex()const{return graphsize;}
	int number_of_edges()const{return numEdge;}
	int get_weight(const T& vertex1,const T& vertex2);//
	Edge* get_neighbors(const T& vertex);//
	int get_first_neighbor(const int v);
	int get_next_neighbor(const int v1,const int v2);//返回序号v1相对于序号v2的下一个邻接顶点的序号
//以下是修改图的方法
	void insert_vertex(const T& vertex);
	void insert_edge(const T& vertex1,const T& vertex2,int weight);
	void delete_vertex(const T& vertex);
	void delete_edge(const T& vertex1,const T& vertex2);
//以下是例程
	void creat_graph();//输入图的边和顶点
	int minimum_path(const int& startv,const int& endv);//返回两个顶点间的最小路径长度
	void depth_first_search(const int& v,int visited[]);//从指定顶点开始进行深度优先搜索
	void depth_first_search();//从顶点表的第一个顶点开始进行深度优先遍历
	void breadth_first_search(const int& v,int visited[]);//从指定顶点开始进行广度优先搜索
	void breadth_first_search();//从顶点表的第一个顶点开始进行广度优先遍历

	void print_degree();
};


template<typename T>
Graph_in_adjacent<T>::Graph_in_adjacent(int sz):numEdge(0),graphsize(0),MaxGraphSize(sz)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	int n,e,weight;
	T name,from,to;
	//用数组实现顶点表
	head = new Vertex<T>[MaxGraphSize];
	cout<<"请输入图中顶点个数：\n";
	cin>>n;
	cout<<"请依次输入各顶点名：\n";
	for(int i = 0;i < n;i++)
	{
		cin>>name;
		insert_vertex(name);
	}
	cout<<"请输入边的个数：";
	cin>>e;
	cout<<"请依次输入各边的始点 终点 和权值：\n";
	for(int j = 0;j < e;j++)
	{
		cin>>from>>to>>weight;
		insert_edge(from,to,weight);
	}
}

template<typename T>
void Graph_in_adjacent<T>::insert_vertex(const T& vertex)
{
	Vertex<T>* temp = new Vertex<T>();
	temp->verName = vertex;
	temp->adjacent = 0;
	head[graphsize++] = *temp;
}

template<typename T>
void Graph_in_adjacent<T>::insert_edge(const T& vertex1,const T& vertex2,int weight)
{
	int pos = get_vertex_pos(vertex2);
	Edge* temp = new Edge(pos,weight);
	Edge* p = head[get_vertex_pos(vertex1)].adjacent;
	if(p != 0)
	{
		while(p->link)
			p = p->link;
		p->link = temp;	
	}
	else
		head[get_vertex_pos(vertex1)].adjacent = temp;
}

template<typename T>
Graph_in_adjacent<T>::~Graph_in_adjacent()
{
	for(int i = 0;i < graphsize;i++)
	{
		Edge* p = head[i].adjacent,*q;
		while(p)
		{
			q = p->link;
			delete p;
			p = q;
		}
	}
	delete[] head;
}


template<typename T>
int Graph_in_adjacent<T>::get_vertex_pos(const T& vertex)
{
	for(int i = 0;i < graphsize;i++)
		if(head[i].verName == vertex)
			return i;
	return -1;
}

template<typename T>
int Graph_in_adjacent<T>::get_weight(const T& vertex1,const T& vertex2)
{
	int a = get_vertex_pos(vertex1);
	int b = get_vertex_pos(vertex2);
	if(a != -1 && b != -1)
	{
		Edge* p = head[a].adjacent;
		while(p)
		{
			if(p->verAdj == b)
				return p->cost;
			p = p->link;
		}
		return 0;
	}
	else
	{
		cout<<"输入错误，该顶点不在此图中。\n";
	}
}

template<typename T>
Edge* Graph_in_adjacent<T>::get_neighbors(const T& vertex)
{
	int i = get_vertex_pos(vertex);
	if(i != -1)
		return head[i].adjacent;
	return 0;
}

template<typename T>
int Graph_in_adjacent<T>::get_first_neighbor(const int v)
{
	if(v != -1)
	{
		Edge* p = head[v].adjacent;
		if(p)
			return p->verAdj;
	}
	return -1;
}


template<typename T>
int Graph_in_adjacent<T>::get_next_neighbor(const int v1,const int v2)
{
	if(v1 != -1 && v2 != -1)
	{
		Edge* p = head[v1].adjacent;
		while(p && p->verAdj != v2)
			p = p->link;
		p = p->link;
		if(p) return p->verAdj;
	}
	return -1;
}


template<typename T>
void Graph_in_adjacent<T>::depth_first_search()
{
	int* visited = new int[graphsize];
	for(int i = 0;i < graphsize;i++)
		visited[i] = 0;
	depth_first_search(0,visited);
	delete[] visited;
}


template<typename T>
void Graph_in_adjacent<T>::depth_first_search(const int& v,int visited[])
{
	cout<<get_name(v)<<"  ";
	visited[v] = 1;
	int w = get_first_neighbor(v);
	while(w != -1)
	{
		if(!visited[w])
			depth_first_search(w,visited);
		w = get_next_neighbor(v,w);
	}
}

template<typename T>
void Graph_in_adjacent<T>::breadth_first_search(const int& v,int visited[])
{
	Queue<int> Q;
	Q.q_insert(v);
	int w,k;
	while(!Q.q_empty())
	{
		w = Q.q_delete();
		if(!visited[w])
		{
			visited[w] = 1;
			cout<<get_name(w)<<"  ";
		}
		k = get_first_neighbor(w);
		while(k != -1)
		{
			if(visited[k] == 0)
				Q.q_insert(k);
			k = get_next_neighbor(w,k);
		}
	}
}


template<typename T>
void Graph_in_adjacent<T>::breadth_first_search()
{
	int* visited = new int[graphsize];
	for(int i = 0;i < graphsize;i++)
		visited[i] = 0;
	breadth_first_search(0,visited);
	delete[] visited;	
}


template<typename T>
void Graph_in_adjacent<T>::print_degree()
{
	for(int i = 0;i < graphsize;i++)
	{
		cout<<head[i].verName<<" 的出度为 ";
		int count = 0;
		Edge* p = head[i].adjacent;
		while(p)
		{
			count++;
			p = p->link;
		}
		cout<<count<<endl;
	}
}
