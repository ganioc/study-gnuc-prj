#include<stdio.h>
#include<string.h>
#include <stdarg.h>
#include <stdlib.h>

struct Node{
    long key;
    char name[32];
    struct Node * next;
};

void initNode(struct Node *pNode){
    memset(pNode, 0, sizeof(struct Node));
    strcpy(pNode->name, "XXXX");
}
void printNode(const struct Node *pNode){
    printf("Key: %ld\n", pNode->key);
    printf("Name: %s\n", pNode->name);
}
// at most 1+log2(n); 因为是二分法，所以次数里面有了log2(n);

long *binarySearch(long val, long array[], int n){
    int m = n/2;
    if(n <= 0) return NULL;
    if( val == array[m]) return array + m;
    if( val < array[m]) return binarySearch(val, array, m);
    else    
        return binarySearch(val, array + m + 1, n - m -1);
}
double upgradedAdd(int n, ...){
    int i = 0;
    double sum = 0.0;
    va_list argptr;

    va_start(argptr,n);
    for(i=0; i< n; ++i){
        sum += va_arg(argptr, double);
    }
    va_end(argptr);
    return sum;
}
// offsetof

typedef int ElemType;

typedef struct node
{
    /* data */
    ElemType data;
    struct node *next;
}LNode, *LinkList;

LinkList CreateLinkList(int n){
    LinkList p, r, list=NULL;
    ElemType e;
    int i;

    for(i=1; i<=n; i++){
        scanf("%d", &e);
        p= (LinkList)malloc(sizeof(LNode));
        p->data = e;
        p->next =NULL;
        if(!list){
            list=p;
        }else{
            r->next=p;
        }
        r=p; // r is latest node
    }
        return list;
}
void insertList(LinkList *list, LinkList q, ElemType e){
    LinkList p;
    p=(LinkList) malloc(sizeof(LNode));
    p->data = e;
    if(!*list){
        *list=p;
        p->next =  NULL;
    }
    else{
        p->next =  q->next;
        q->next = p;
    }
}
void delLink(LinkList*list, LinkList q){
    LinkList r;
    if(q == *list){
        *list=q->next;
        free(q);
    }
    else{
        for(r=*list; r->next!=q; r=r->next);
        if(r->next!=NULL){
            r->next = q->next;
            free(q);
        }
    }
}
void destroyLinkList(LinkList *list){
    LinkList p,q;
    p=*list;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    *list=NULL;
}
int main(int argc, char* argv[]){
    printf("The program now running: %s\n", argv[0]);
    register int i,j;

    upgradedAdd(2,2,2,2);

    int (*arrPtr) [10] = NULL;

    int e;
    LinkList l,q;
    q=l=CreateLinkList(1);

    scanf("%d", &e);
    while(e){
        insertList(&l, q, e);
        q=q->next;
        scanf("%d", &e);
    }
    q=l;
    printf("The content of the linklist\n");
    while(q){
        printf("%d ", q->data);
        q=q->next;
    }
    destroyLinkList(&l);

    return 0;
}

