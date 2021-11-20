#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#define PRG_NAME "Easy Line"

typedef double (func_t)(double);

func_t * pFunc = sqrt;

enum {ARR_LEN = 100};

typedef struct Gap  {
    char version;
    short value;
} GAP;

void eval_func1(){
    float *fPtr = (float []){-0.5, 0.0, +0.5};
    printf("sizeof fPtr is %lu\n", sizeof(fPtr));

    GAP gap;
    memset(&gap, 0, sizeof(gap));

    double x = 0.0, sum = 0.0;
    int count = 0;

    printf("\nEnter some numbers:\n"
        "Type a letter to end your input\n");
    while(scanf("%lf", &x) == 1){
        sum += x;
        ++count;
    }
    if (count == 0){
        printf("No input data!\n");
    }else{
        printf("The average of your number is %.2f\n", sum/count);
    }
}

int main(){
    int i,
        *pNumbers = malloc(ARR_LEN * sizeof(int));
    if(pNumbers == NULL){
        fprintf(stderr, "insufficient memory.\n");
        exit(1);
    }

    srand((unsigned) time(NULL));

    for(i=0; i< ARR_LEN; i++){
        pNumbers[i] = rand()%10000;
    }

    printf("\n%d random numbers between 0 and 9999:\n", ARR_LEN);

    for(i=0; i< ARR_LEN; i++){
        printf("%6d", pNumbers[i]);
        if( i%10 == 9)
            putchar('\n');
    }

    free(pNumbers);

    char doc_path[128] = ".\\share\\doc";
    printf("\asee the documentation in the directory \"%s\"\n", doc_path);

    char msg[] = "The installation of " PRG_NAME " is now complete\n";
    printf("%s", msg);

    _Bool is = true;

    double y = pFunc(2.0);
    printf("The square root of 2.0 is %f.\n",y);

    long *lPtr = NULL;

    eval_func1();

    return 0;
}