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

struct array* merge(struct array *arr1, struct array *arr2){
    int i,j,k;
    i=j=k=0;
    struct array *arr3;
    arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->lenght && arr2->lenght){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for( ;i<arr1->lenght;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for( ;j<arr2->lenght;j++)
        arr3->A[k++]=arr2->A[j];
    
    arr3->lenght=arr1->lenght+arr2->lenght;
    arr3->size=10;
    return arr3;
}

struct array* Union(struct array *arr1, struct array *arr2){
    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->lenght && j<arr2->lenght){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->lenght;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->lenght;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->lenght=k;
    arr3->size=10;
    return arr3;
}

struct array* Intersection(struct array *arr1, struct array *arr2){
    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array*)malloc(sizeof(struct array));
    while(i<arr1->lenght && j<arr2->lenght){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else if(arr1->A[i]==arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->lenght=k;
    arr3->size=10;
    return arr3;
}

struct array* difference(struct array *arr1, struct array *arr2){
    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array*)malloc(sizeof(struct array));
    while(i<arr1->lenght && j<arr2->lenght){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i]){
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    arr3->lenght=k;
    arr3->size=10;
    return arr3;
}
int main(){
    struct array arr1={{2,4,5,6,7},5,10};
    struct array arr2={{8,4,10,7,12},5,10};
    struct array *arr3;
    
    arr3=difference(&arr1, &arr2);
    display(*arr3);
    
}
