#include<stdio.h>
#include<stdlib.h>
int* p;

int find(int i)
{
	while(p[i]>0)
		i=p[i];
	return i;
}

void Union(int i,int j)
{
	p[i]=j;
}

int main()
{
	int n;
	printf("ENTER THE NUMBER OF NODES : ");
	scanf("%d",&n);
	p=(int*)calloc(n+1,sizeof(int));
	int i,j;
	for(i=1;i<=n;i++)
		p[i]=-1;
	while(1)
	{
		printf("YOUR OPTIONS ARE :\n1.UNION\n2.FIND\n3.DISPLAY\n4.END\n");
		int ch;
		printf("ENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("ENTER THE TWO ROOTS : ");
				scanf("%d %d",&i,&j);
				Union(i,j);
				break;
			case 2: printf("ENTER THE NODE WHOSE ROOT IS TO BE FOUND : ");
				scanf("%d",&i);
				printf("ROOT OF %d IS %d \n",i,find(i));
				break;
			case 3: for(i=1;i<=n;i++)
					printf("%d\t",i);
				printf("\n");
				for(i=1;i<=n;i++)
					printf("%d\t",p[i]);
				printf("\n");
				break;
			case 4: printf("~~~~~~~~~~~~~END OF PROGRAM~~~~~~~~~~~\n");
				return 0;
			default:printf("WRONG CHOICE, PLEASE RETRY !!!!\n");
		}
	}
	free(p);
	return 0;
}
				
