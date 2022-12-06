#include <stdio.h>

void main(){
    int arr[100],value,i,j,n, flag=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&value);
        arr[i]=value;  
    }


    printf("\nEnter an Element to search in the array: ");
    scanf("%d",&j);
    for(i=0;i<n;i++){
        if(arr[i]==j){
            printf("Given element present in position %d ",i+1);
            flag = 1;
            break;
        }

    }
    if(flag == 0){
        printf("Element not present");
    }
    
}
