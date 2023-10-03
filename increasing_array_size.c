/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(){
    int *p,*q;
    
    p=(int *)malloc(5*sizeof(int));
    
    p[0]=1;p[1]=1;p[2]=3;p[3]=3;p[4]=4;
    
    q=(int *)malloc(10*sizeof(int));
    
    for(int i=0; i<5; i++){
        q[i]=p[i];
    }
    
    free(p);
    p=q;
    q=NULL;
    
    for (int i=0;i<5;i++)
        printf("%d ", p[i]);
    return 0;
}

