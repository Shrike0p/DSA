#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int lenght;
    int size;
};

void reverse(struct array *arr){
    int i,j;
    int *B;
    B=(int *)malloc(arr->lenght*sizeof(int));
    for(i=arr->lenght-1,j=0;i>=0;i--,j++){
        B[j]=arr->A[i];
    }
    for(i=0;i<arr->lenght;i++){
        arr->A[i]=B[i];
    }
}

void reverse2(struct array *arr){
    int i,j;
    for(i=0,j=arr->lenght-1;i<=j;i++,j--){
        int temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
void display(struct array arr){
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.lenght;i++){
        printf("%d ", arr.A[i]);
    }
}

int main(){
    struct array arr={{2,3,4,5,6},5,10};
    
    reverse2(&arr);
    display (arr);
}
