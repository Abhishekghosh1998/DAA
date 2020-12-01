#include<stdio.h>

void max_min(int* a,int*max,int*min,int low,int high)
{
	if(low==high)
		*max=*min=a[low];
	else if(low<high)
	{
		int mid=(low+high)/2;
		int min1,max1,min2,max2;
		max_min(a,&max1,&min1,low,mid);
		max_min(a,&max2,&min2,mid+1,high);
		*max=(max1>max2)?max1:max2;
		*min=(min1<min2)?min1:min2;
	}
}

int main()
{
	int n;
	printf("ENTER THE NUMBER OF ELEMENTS : ");
	scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("a[%d] ? ",i);
		scanf("%d",a+i);
	}
	int max,min;
	max_min(a,&max,&min,0,n-1);
	printf("THE MAXIMUM ELEMENT IS : %d\n",max);
	printf("THE MINIMUM ELEMENT IS : %d\n",min);
	return 0;
}

		
