#include<stdio.h>
int maxSon(int a[],int p,int k)
{
	int s=2*p+1;
	if(s>=k)
		return -1;
	if(s+1<k && a[s+1]>a[s])
		s++;
	return s;
}

void heapify(int a[],int p,int k)
{
	int s=maxSon(a,p,k);
	if(s>=0)
	{
		if(a[s]>a[p])
		{
			int temp=a[s];
			a[s]=a[p];
			a[p]=temp;
		}
		heapify(a,s,k);
	}
}

void BuildMaxHeap(int a[],int k)
{
	int i;
	for(i=k-1;i>=0;i--)
		heapify(a,i,k);
}

int deleteMax(int a[],int k)
{
	int data=a[0];
	a[0]=a[k-1];
	heapify(a,0,k-1);
	return data;
}

void heapSort(int a[],int n)
{
	BuildMaxHeap(a,n);
	int i;
	for(i=n-1;i>0;i--)
		a[i]=deleteMax(a,i+1);
}

void main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	heapSort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
