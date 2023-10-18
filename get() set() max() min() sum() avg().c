#include<stdio.h>
#include<stdlib.h>

struct array{
    int A[10];
    int lenght;
    int size;
};

int get(struct array arr, int index){
    if(index>=0 && index<arr.lenght){
        return arr.A[index];
    }
    return -1;
}

void set(struct array *arr, int x, int index){
    if (index>=0 && index<arr->lenght){
        arr->A[index]=x;
    }

    
}
int max(struct array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.lenght;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}

int min(struct array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.lenght;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}

int sum(struct array arr){
    int s=0;
    int i;
    for(i=0;i<arr.lenght;i++){
        s+=arr.A[i];
    }
    return s;
}

float avg(struct array arr){
    return (float)sum(arr)/arr.lenght;
}




int main(){
    struct array arr={{2,5,7,3,2},5,10};
    printf("%d \n",get(arr,2));
    set(&arr,10,2);
    printf("%d \n",get(arr,2));
    printf("%d \n",max(arr));
    printf("%d \n",min(arr));
    printf("%d \n",sum(arr));
    printf("%d \n",avg(arr));
    
    
}
