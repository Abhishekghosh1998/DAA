#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct EdgeList{
	int vertex1;
	int vertex2;
	int cost;
	};
struct EdgeList *edges;
int* parent;
int t[MAX][3];

int find(int i)
{
	while(parent[i]>=0)
		i=parent[i];
	return i;
}

void Union(int i,int j)
{
	parent[i]=j;
}

int kruskal(int e,int v)
{
	int minCost=0;	
	parent=(int*)malloc((v+1)*sizeof(int));
	int i;
	for(i=1;i<=v;i++)
		parent[i]=-1;
	int p=0;
	for(i=1;i<=e;i++)
	{
		int x=find(edges[i].vertex1);
		int y=find(edges[i].vertex2);
		if(x!=y)
		{
			minCost+=edges[i].cost;
			t[p][1]=edges[i].vertex1;
			t[p][2]=edges[i].vertex2;
			p++;
			Union(x,y);
		}
	}
	printf("THE EDGES INCLUDED IN THE SPANNING TREE USING KRUSKAL'S ALGORITHM ARE :\n\n");
	for(i=0;i<p;i++)	
		printf("( %d , %d )\n",t[i][1],t[i][2]);
	free(parent);
	return minCost;
}

int main()
{
	printf("ENTER THE NUMBER OF VERTICES AND EDGES : ");
	int v,e;
	scanf("%d %d",&v,&e);
	edges=(struct EdgeList*)malloc((e+1)*sizeof(struct EdgeList));
	printf("ENTER THE EDGE AND THE COST\n");
	int i,j;
	for(i=1;i<=e;i++)
		scanf("%d %d %d",&edges[i].vertex1,&edges[i].vertex2,&edges[i].cost);
	for(i=1;i<e;i++)
		for(j=1;j<=e-i;j++)
			if(edges[j].cost>edges[j+1].cost)
			{
				struct EdgeList temp=edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=temp;
			}
	printf("THE MINIMUM COST IS : %d\n",kruskal(e,v));
	free(edges);
}
