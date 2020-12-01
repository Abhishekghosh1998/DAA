#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int G[MAX][MAX]={0};
int m;
int* x;

void write(int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",x[i]);
	printf("\n\n");
}

int input()
{
	while(1)
	{
		int x,y;
		if(scanf("%d %d",&x,&y)==-1)
			break;
		G[x][y]=G[y][x]=1;
	}
}

void nextk(int k,int n)
{
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		int j;
		for(j=1;j<=k-1;j++)
			if(G[j][k]&&x[j]==x[k])
				break;
		if(j==k)
			return;
	}
}

void graphCol(int k,int n)
{
	while(1)
	{
		nextk(k,n);
		if(x[k]==0)
			return;
		if(k==n)
			write(n);
		else
			graphCol(k+1,n);
	}
}


int main()
{
	printf("ENTER THE NUMBER OF COLOURS IN HAND : ");
	scanf("%d",&m);	
	int n;
	printf("ENTER THE NUMBER OF VERTICES IN THE GRAPH : ");
	scanf("%d",&n);
	printf("ENTER THE EDGES \n");
	input();
	x=(int*)calloc(n+1,sizeof(int));
	graphCol(1,n);
	free(x);
}
