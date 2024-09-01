#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeff;
    int exp;
} Term;


Term* multiplySparsePolynomials(Term* poly1, int size1, Term* poly2, int size2, int* resSize) {
    Term* res = (Term*) malloc((size1 * size2) * sizeof(Term));
    int resInd = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            int coeff = poly1[i].coeff * poly2[j].coeff;
            int exp = poly1[i].exp + poly2[j].exp;

            
            res[resInd].coeff = coeff;
            res[resInd].exp = exp;
            resInd++;
        }
    }

    *resSize = resInd;
    

    return res;
}

int main() {
    
    Term poly1[] = {{3, 5}, {2, 1}};
    Term poly2[] = {{1, 3}, {4, 0}};
    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    int resSize;
    Term* res = multiplySparsePolynomials(poly1, size1, poly2, size2, &resSize);

    
    for (int i = 0; i < resSize; i++) {
        printf("%dx^%d ", res[i].coeff, res[i].exp);
    }
    printf("\n");

    free(res);
    return 0;
}
