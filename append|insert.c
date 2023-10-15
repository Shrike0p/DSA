#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int lenght;
    int size;
};

void display(struct array arr){
    int i;
    printf("Eleemnts are\n");
    for(i=0;i<arr.lenght;i++)
        printf("%d ", arr.A[i]);

}

void append(struct array *arr, int x){
    
    if(arr->lenght<arr->size){
        arr->A[arr->lenght++]=x;
 
    }

}

void insert (struct array *arr, int index, int x ){
    if(index>=0 && index<=arr->lenght){
        for(int i=arr->lenght;i>index;i--){
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->lenght++;
        }
    }
}

int main(){
    struct array arr={{2,3,4,5,6},5,10};

    
    append(&arr, 7);
    insert(&arr,3,10);
    display( arr);
    return 0;


}
