#include<stdio.h>
#include<math.h>

int main(){
    int deg;
	int c=0;
    printf("Enter the degree of the  polynomial: ");
    scanf("%d",&deg);
    int i;

    printf("Enter the polynomial 1: \n");
    int pol[deg+1];
    for(i=deg;i>=0;i--){
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&pol[i]);
    }

    printf("\nThe entered polynomial is: ");
    for(i=deg;i>=0;i--){
        if(pol[i]==0){
            continue;
        }
		c++;
		if(c>1)
		printf(" + ");
        if(i==0){
            printf("%d",pol[i]);
            continue;
        }
        printf("%d x^%d",pol[i],i);
    }

    printf("\n\nEnter the value of x = ");
    int x;
    scanf("%d",&x);

    long long int ans=0, int i;
    for(i=0;i<=deg;i++){
        ans+=pol[i]*pow(x,i);
    }
    printf("The evaluated value is = %d",ans);
    return 0;
}
