#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

struct node{
	int key;
	int vertex;
	};

struct node A[MAX];
int heapSize;

vector<pair<int,int>>adj[MAX];
int handle[MAX];
int d[MAX];

void heapify(int node)
{
	int val=A[node].key;
	int leftChild=2*node;
	int rightChild=2*node+1;
	int index=node;
	if(leftChild<=heapSize && A[leftChild].key<val)
		index=leftChild;
	if(rightChild<=heapSize && A[rightChild].key<A[index].key)
		index=rightChild;
	if(index!=node)
	{
		struct node temp=A[node];
		A[node]=A[index];
		A[index]=temp;
		handle[A[node].vertex]=node;
		handle[A[index].vertex]=index;
		heapify(index);
	}
}
int extractMin()
{
	struct node temp=A[1];
	A[1]=A[heapSize];
	heapSize--;
	handle[A[1].vertex]=1;
	heapify(1);
	return temp.vertex;
}


void decreaseKey(int index,int newKey)
{
	if(A[index].key<=newKey)
		return;
	A[index].key=newKey;
	int parent=index/2;
	while(parent>=1 && A[index].key<A[parent].key)
	{
		struct node temp=A[parent];
		A[parent]=A[index];
		A[index]=temp;
		handle[A[parent].vertex]=parent;
		handle[A[index].vertex]=index;
		index=parent;
		parent=index/2;
	}
}

void singleSourceInitialize(int n,int s)
{
	heapSize=n;
	for(int v=1;v<=n;v++)
	{
		d[v]=INT_MAX;
		A[v].key=INT_MAX;
		A[v].vertex=v;
		handle[v]=v;
	}
	d[s]=0;
	decreaseKey(handle[s],0);
}

void relaxEdge(int u,int v,int wt)
{
	if(d[u]+wt<d[v])
	{
		d[v]=d[u]+wt;
		decreaseKey(handle[v],d[v]);
	}
}

void dijkstra(int n,int s)
{
	singleSourceInitialize(n,s);
	while(heapSize)
	{
		int u=extractMin();
		for(auto v:adj[u])
			relaxEdge(u,v.first,v.second);
		
	}
}
	
int main()
{
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y,wt;
		cin>>x>>y>>wt;
		adj[x].push_back({y,wt});
	}
	dijkstra(n,1);
	cout<<"SINGLE SOURCE SHORTEST PATH : "<<endl;
	for(int i=1;i<=n;i++)
		cout<<"d["<<i<<"] : "<<d[i]<<endl;
}
