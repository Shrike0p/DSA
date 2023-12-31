#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int lenght;
    int size;
};

void display(struct array arr){
    int i;
    printf("Elements of Elements");
    
    for(i=0;i<arr.lenght;i++){
        printf("%d ", arr.A[i]);
    }
}

/*int LinearSearch(struct array arr,int key){
    for(int i=0;i<arr.lenght;i++)
    if(key==arr.A[i]){
        return i;
        
    }
    return -1;
}*/

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
//Transposition method of linear search
int LinearSearch(struct array *arr,int key){
    for(int i=0;i<arr->lenght;i++)
    if(key==arr->A[i]){
        swap(&arr->A[i],&arr->A[i-1]);
        return i;
    }
    return -1;
}

/*Movie to front/ head method of linear search
int LinearSearch(struct array *arr,int key){
    for(int i=0;i<arr->lenght;i++)
    if(key==arr->A[i]){
        swap(&arr->A[i],&arr->A[0]);
        return i;
    }
    return -1;
}*/

int main(){
    struct array arr={{2,3,4,5,6},5,10};
    
    printf("%d\n",LinearSearch(&arr,4));
    display(arr);
}
