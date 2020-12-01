#include<stdio.h>
#include<math.h>
#define MAX 100
int cost[MAX][MAX];
int lim=pow(2,(sizeof(int)*8-1))-1;
int t[MAX][3];
int prim(int v)
{
	//finding the minimum edge
	int k,l;
	int min=lim;
	int i,j;
	for(i=1;i<=v;i++)
		for(j=i+1;j<=v;j++)
			if(cost[i][j]<min)
			{
				k=i;
				l=j;
				min=cost[i][j];
			}
	int near[v+1];
	for(i=1;i<=v;i++)
		if(cost[i][k]<cost[i][l])
			near[i]=k;
		else
			near[i]=l;
	near[l]=near[k]=0;
	int minCost=cost[k][l];
	int p=0;
	t[p][1]=k;t[p][2]=l;
	p++;
	for(i=2;i<=v-1;i++)
	{
		min=lim;
		int x;
		for(j=1;j<=v;j++)
			if(near[j] && cost[j][near[j]]<min)
			{
				min=cost[j][near[j]];
				x=j;
			}
		j=x;
		t[p][1]=j;t[p][2]=near[j];
		p++;
		minCost+=cost[j][near[j]];
		for(x=1;x<=v;x++)
			if(cost[x][j]<cost[x][near[x]])
				near[x]=j;
		near[j]=0;
	}
	printf("THE EDGES WHICH ARE INCLUDED TO FORM THE SPANNING TREE : \n");
	for(i=0;i<p;i++)
		printf("( %d , %d )\n",t[i][1],t[i][2]);
	return minCost;
}

int input()
{
	while(1)
	{
		int x,y,z;
		if(scanf("%d %d %d",&x,&y,&z)==-1)
			break;
		cost[x][y]=cost[y][x]=z;
	}
}

void main()
{
	int i,j;
	printf("ENTER THE NUMBER OF NODES : ");
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cost[i][j]=lim;
	printf("ENTER THE EDGE AND THE COST :\n");
	input();
	printf("THE MINIMUM COST IS : %d\n",prim(n));
}
