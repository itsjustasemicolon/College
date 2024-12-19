#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int val;
} Element;


int main() {
    
	printf("Enter no of elements of matrix ");
	int s;
	int i=0,rmax=-1,j=0;
	scanf("%d",&s);
    Element mat1[s];
	printf("Enter rol,col,val of Matrix\n");
    for(i=0;i<s;i++)
	{
		int r,c,v;
		scanf("%d %d %d",&r,&c,&v);
		mat1[i].row=r;
		mat1[i].col=c;
		mat1[i].val=v;
		if(r>rmax)
		rmax=r;
	}

	for(i=0;i<=rmax;i++)
	{
		int c=0;
		for(j=0;j<s;j++)
		{
			if(mat1[j].row==i && mat1[j].val==0)
			c++;
		}
		if(c!=0)
		printf("No. of zeroes in row %d is %d\n",i,c);
	}
    
    return 0;
}
