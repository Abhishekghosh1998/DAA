#include<stdio.h>
#include<math.h>
#define MAX 100
int lim=pow(2,8*(sizeof(int))-1)-1;
int m[MAX][MAX];int s[MAX][MAX];
void matrix_chain_order(int* p,int x)//p is the p array and x is the length of the of p
{
	int n=x-1;
	//first we shall process all the sub-lists of length 1 ... i.e. A1; A2; A3 ...
	//now for processing a single array the cost is 0, so we do as follows
	int i;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	//now we shall process all sublists of length 2 then length 3 and so on upto length n
	//length 2, A1,A2 ; A2,A3 ; A3,A4; ...
	//length 3, A1,A2,A3; A2,A3,A4; ....
	// ...
	//length n, A1,A2,A3,...An-1,An;
	int l;//l stands for l
	for(l=2;l<=n;l++)
	{
		//now we develope all the sub-lists of length l
		//for a given length l, each sublists start with i= 1,2,3,..., till such an i 
		//such that after adding (l-1) more matrices(such that sublist of length l)
		// i+l-1 = n 
		//=>  i=n-l+1
		int i;
		for(i=1;i<=n-l+1;i++)
		{
			//for each i to form a sublist of length l within Ai,Ai+1,Ai+2,..Aj-1,Aj
			int j=i+l-1;
			//now we choose such a k to partition <Ai,Ai+1,Ai+2,..Aj-1,Aj>
			//as <Ai,Ai+1,Ai+2,..Ak-1,Ak> and <Ak+1,Ak+2,...,Aj>
			//now k varies between i and j as i<=k<j so
			int k;
			m[i][j]=lim;//lim <=> infinity
			for(k=i;k<j;k++)
			{ 
				int q= m[i][k] +//cost of multiplying sublist <Ai,Ai+1,Ai+2,..Ak-1,Ak> 
						//forms a matrix of dimension p[i-1] x p[k]
					m[k+1][j]+//cost of multiplying sublist <Ak+1,Ak+2,..Aj-1,Aj>
						////forms a matrix of dimension p[k] x p[j]
					p[i-1]*p[k]*p[j];//cost of multiplying the two matrices formed
				//this is where dp comes into play... by the time we calculate m[i][j]
				//m[i][k] and m[k+1][j] has already been solved previously and stored 
				//in memory
				if(q<m[i][j])
				{
					//we store the optimal cost of multiplying sublist <Ai,...Aj> and 
					//store the partition position k in s[i][j]
					m[i][j]=q;
					s[i][j]=k;
				}
			}//end of for k
		}//end of for i
	}//end of for l
}

//below is the vital method the method which displays the parenthesizing (optimal)
void optimal(int i,int j)//this method uses the gobal s matrix
{
	//i and j represents the limits of the sublist i.e. <Ai,Ai+1,....,Aj-1,Aj>
	if(i==j)//single element in the sublist (base case)
	{
		printf(" A%d ",i);
		return;
	}
	//the inductive situation
	//the optimal partion value for the current sublist <Ai,Ai+1,....,Aj-1,Aj> 
	// is stored in s[i][j], so from this we two sublists with limits as
	// i: s[i][j]//s[i][j]+1:j corresponding to <Ai,Ai+1,...Ak> <Ak+1,Ak+2,...Aj> as s[i][j] stored k
	printf("(");
	optimal(i,s[i][j]);
	optimal(s[i][j]+1,j);
	printf(")");
}

void main()
{
	printf("\n~~~~~~~~~~~~~~~~~~~THIS CODE HAS BEEN DEVELOPED BY HITECH GA~~~~~~~~~~~~~~~~\n\n\n");
	printf("ENTER THE NUMBER OF MATRICES : ");
	int n;
	scanf("%d",&n);
	int p[n+1];
	//stores the dimensions of the array
	printf("ENTER THE DIMENSIONS OF THE MATRICES SEPERATED BY A SPACE... \n");
	int i;
	for(i=1;i<=n;i++)
	{
		printf("A%d ? ",i);
		scanf("%d %d",p+i-1,p+i);
	}
	matrix_chain_order(p,n+1);
	optimal(1,n);
	printf("\n");
	return;
}

