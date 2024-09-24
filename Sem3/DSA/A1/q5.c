#include<stdio.h>

int main(){
    int deg1,deg2;
    printf("Enter the degree of the first and second polynomials respectively: ");
    scanf("%d",&deg1);
    scanf("%d",&deg2);
    int i;

    printf("Enter the polynomial 1: \n");
    int pol1[deg1+1];
    for(i=deg1;i>=0;i--){
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&pol1[i]);
    }

    printf("\n Enter the polynomial 2: \n");
    int pol2[deg2+1];
    for(i=deg2;i>=0;i--){
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&pol2[i]);
    }
    
    int polres[(deg1+deg2+1)];
    for(i=0;i<=deg1+deg2;i++)
    polres[i]=0;
    for(i=0;i<=deg1;i++)
    {
        for(int j=0;j<=deg2;j++)
        {
            polres[i+j]+=pol1[i]*pol2[j];
        }
    }
    
    for(i=(deg1+deg2);i>=0;i--)
    {
        if(polres[i]==0){
        continue;
        }
        if(i==0){
        printf("%d",polres[i]);
        continue;
        }
        printf("%d x^%d + ",polres[i],i);
    }
    
    return 0;
}

