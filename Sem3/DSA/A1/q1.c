#include <stdio.h>

int main() {
    

int arr[10] ;
int i ;

printf(" Enter 10 elements in the array : \n") ;

for(i=0;i<10;i++){
    
    scanf("%d",&arr[i]) ;
    
}

// delete of the 3rd element :

for(i = 2 ; i<9 ; i++){
    
    arr[i]=arr[i+1] ;
}

// delete of the 6th element :

for(i = 4 ; i<9 ; i++){
    
    arr[i] = arr[i+1] ;
}

printf("the 5th element of this array is : %d\n",arr[4]) ;


return 0 ;  
}
