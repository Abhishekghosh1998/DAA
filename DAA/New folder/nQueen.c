#include<stdio.h>
#include<stdlib.h>
int *x;

void draw(int n)
{
	printf("\n\n\n");
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(x[i]==j)
				printf("Q ");
			else
				printf("X ");
		printf("\n");
	}
	printf("\n\n\n");
}

int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
		if(x[j]==i || abs(k-j)==abs(x[j]-i))
			return 0;
	return 1;
}

void nQueen(int k,int n)
{
	int i;
	for(i=1;i<=n;i++)
		if(place(k,i))
 		{
 			x[k]=i;
 			if(k==n)
 				draw(n);
 			else
 				nQueen(k+1,n);
 		}
}
 
int main()
{
	int n;
	printf("ENTER THE VALUE OF N : ");
	scanf("%d",&n);
	x=(int*)malloc((n+1)*sizeof(int));
	nQueen(1,n);
	free(x);
	return 0;
}	
