#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int lenght;
    int size;
};

void display(struct array arr){
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.lenght;i++){
        printf("%d ",arr.A[i]);
    }
}

void append(struct array *arr, int x){
    
    if(arr->lenght<arr->size){
        arr->A[arr->lenght]=x;
        arr->lenght++;
    }
}


void insert(struct array *arr, int index, int x){
    int i;
    if(index>=0 && index<=arr->lenght){
        for(i=arr->lenght; i>index; i--){
            arr->A[i]=arr->A[i-1];
    
        }
        arr->A[index]=x;
        arr->lenght++;
    }
}

int delete(struct array *arr, int index){
    int i;
    int x=0;
    
    if(index>=0 && index<arr->lenght){
        x=arr->A[index];
        for(i=index;i<arr->lenght;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->lenght--;
        return x;
    }
    return 0;
}





int main(){
    struct array arr={{2,3,4,5,6},5,10};
    append(&arr, 10);
    insert(&arr,4,2);
    printf("%d",delete(&arr,3));
    display(arr);
    
}
