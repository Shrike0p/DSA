#include <stdio.h>
#include <stdlib.h>

struct array {
    int A[10];
    int lenght;
    int size;
};

void swap (int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void insert(struct array *arr, int x){
    int i=arr->lenght-1;
    while(arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i]=x;
    arr->lenght++;
    
}

int isSorted(struct array arr){
    for(int i=0;i<arr.lenght-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
        
    }
    return 1;
}

void arrange(struct array *arr){
    int i=0;
    int j=arr->lenght-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j++;}
        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}
void display(struct array arr){
    int i;
    printf("Elements are\n");
    for(int i=0;i<arr.lenght;i++){
        printf("%d ", arr.A[i]);
    }
}
int main(){
    struct array arr={{2,4,5,6,7},5,10};
    insert(&arr, 8);
 
    display(arr);
}
