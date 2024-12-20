#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int val;
} Matrix;

int main()
{
    printf("Enter the number of elements in the matrix: ");
    int s;
    int i = 0, rmax = -1, j = 0;
    scanf("%d", &s);
    Matrix mat1[s];
    for (i = 0; i < s; i++)
    {
    printf("Enter row, col, val of the matrix:\n");
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        mat1[i].row = r;
        mat1[i].col = c;
        mat1[i].val = v;
        if (r > rmax)
            rmax = r;
    }

    // Find the number of non-zero elements in each row
    for (i = 0; i <= rmax; i++)
    {
        int count = 0;
        for (j = 0; j < s; j++)
        {
            if (mat1[j].row == i && mat1[j].val != 0)
                count++;
        }
        if (count != 0)
            printf("No. of non-zero elements in row %d is %d\n", i, count);
    }

    return 0;
}
