#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(char num1[], char num2[], char ans[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, sum, i, j, k;
    k = 0;
    for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--, k++) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        ans[k] = (sum % 10) + '0';
    }
    ans[k] = '\0';
    strrev(ans);
}
int main() {
    char num1[1000], num2[1000], ans[1001];
    printf("Enter the first number = ");
    scanf("%s", num1);
    printf("Enter the second very long number = ");
    scanf("%s", num2);
    add(num1, num2, ans);
    printf("The sum is: %s\n", ans);
    return 0;
}



//7 add sparse matrices
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int val;
} Element;


Element* addSparseMatrices(Element* mat1, int size1, Element* mat2, int size2, int* resSize) {
    Element* res = (Element*) malloc((size1 + size2) * sizeof(Element));
    int resInd = 0;

    
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col) {
            res[resInd].row = mat1[i].row;
            res[resInd].col = mat1[i].col;
            res[resInd].val = mat1[i].val + mat2[j].val;
            resInd++;
            i++;
            j++;
        } else if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            res[resInd] = mat1[i];
            resInd++;
            i++;
        } else {
            res[resInd] = mat2[j];
            resInd++;
            j++;
        }
    }

    while (i < size1) {
        res[resInd] = mat1[i];
        resInd++;
        i++;
    }
    while (j < size2) {
        res[resInd] = mat2[j];
        resInd++;
        j++;
    }

    *resSize = resInd;
    return res;
}



int main() {
    
    Element mat1[] = {{0, 0, 1}, {1, 1, 2}, {2, 2, 3}};
    Element mat2[] = {{0, 1, 4}, {1, 0, 5}, {2, 2, 6}};
    int size1 = sizeof(mat1) / sizeof(mat1[0]);
    int size2 = sizeof(mat2) / sizeof(mat2[0]);

    int resSize;
    Element* res = addSparseMatrices(mat1, size1, mat2, size2, &resSize);

    
    for (int i = 0; i < resSize; i++) {
        printf("(%d, %d, %d) ", res[i].row, res[i].col, res[i].val);
    }
    printf("\n");

    free(res);
    return 0;
}


