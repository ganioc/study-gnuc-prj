#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE  64

typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;

}ListElmt;

int f(){
    int a[10], *iptr;
    iptr = a;
    iptr[0] = 5;
    return 0;
}

int g(){
    int a[10], *iptr;
    iptr = a;
    *iptr = 5;
    return 0;
}

int(*match)(void *key1, void *key2);

void swap2(int *x, int *y){
    int tmp;
    tmp =*x;
    *x = *y;
    *y = tmp;
    return;
}
int main(){
    printf("hello algri\n");
    void *tmp;

    if((tmp = malloc(SIZE)) == NULL){
        return -1;
    }
    printf("malloc succeed.\n");

    free(tmp);
    
    return 0;
}