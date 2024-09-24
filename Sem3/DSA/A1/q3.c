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
    if(deg1<=deg2)
    {
        for(i=0;i<=deg1;i++)
        {
            pol2[i]+=pol1[i];
        }
        for(i=deg2;i>=0;i--)
        {
            if(pol2[i]==0){
            continue;
            }
            if(i==0){
            printf("%d",pol2[i]);
            continue;
            }
            printf("%d x^%d + ",pol2[i],i);
        }
    }
    else
    {
        for(i=0;i<=deg2;i++)
        {
            pol1[i]+=pol2[i];
        }
        for(i=deg1;i>=0;i--)
        {
            if(pol1[i]==0){
            continue;
            }
            if(i==0){
            printf("%d",pol1[i]);
            continue;
            }
            printf("%d x^%d + ",pol1[i],i);
        }
    }
    return 0;
}

