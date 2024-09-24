#include <stdio.h>

int main (){
  
    int n, i,j;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements into the array
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    printf("Reversed array: \n");
    i=0;
    j=n-1;
    while(i<j)
    {
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
        i++;
        j--;
    }
    
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
        

    printf("\n");
    return 0;
}
