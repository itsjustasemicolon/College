#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int val;
} Element;


Element* addSparseMatrices(Element* mat1, int size1, Element* mat2, int size2, int* resultSize) {
    Element* result = (Element*) malloc((size1 + size2) * sizeof(Element));
    int resultIndex = 0;

    
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col) {
            result[resultIndex].row = mat1[i].row;
            result[resultIndex].col = mat1[i].col;
            result[resultIndex].val = mat1[i].val + mat2[j].val;
            resultIndex++;
            i++;
            j++;
        } else if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[resultIndex] = mat1[i];
            resultIndex++;
            i++;
        } else {
            result[resultIndex] = mat2[j];
            resultIndex++;
            j++;
        }
    }

    while (i < size1) {
        result[resultIndex] = mat1[i];
        resultIndex++;
        i++;
    }
    while (j < size2) {
        result[resultIndex] = mat2[j];
        resultIndex++;
        j++;
    }

    *resultSize = resultIndex;
    return result;
}

int main() {
    
	printf("Enter no of elements of matrix 1 and 2: ");
	int s1,s2;
	scanf("%d %d",&s1,&s2);
    Element mat1[s1];
    Element mat2[s2];
	int i=0;
	printf("Enter rol,col,val of Matrix1\n");
    for(i=0;i<s1;i++)
	{
		int r,c,v;
		scanf("%d %d %d",&r,&c,&v);
		mat1[i].row=r;
		mat1[i].col=c;
		mat1[i].val=v;
	}
	printf("Enter rol,col,val of Matrix2\n");
    for(i=0;i<s2;i++)
	{
		int r,c,v;
		scanf("%d %d %d",&r,&c,&v);
		mat2[i].row=r;
		mat2[i].col=c;
		mat2[i].val=v;
	}
    int resultSize;
    Element* result = addSparseMatrices(mat1, s1, mat2, s2, &resultSize);

    
    for (int i = 0; i < resultSize; i++) {
        printf("(%d, %d, %d) ", result[i].row, result[i].col, result[i].val);
    }
    printf("\n");

    free(result);
    return 0;
}
