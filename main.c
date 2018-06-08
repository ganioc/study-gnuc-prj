#include <stdio.h>
#define max 3;
#define search(array, target) \
    ({ \
    __label__ found; \
    int value; \
    int i, j;  \
    typeof (target) _SEARCH_target = (target); \
    typeof (*(array)) *_SEARCH_array = (array); \
    for(i=0; i<3; i++) \
    { \
        for(j=0; j<3; j++) \
        { \
            if(_SEARCH_array[i][j]==_SEARCH_target) \
            { \
                value =_SEARCH_target; \
                goto found; \
            } \
        }; \
    }; \
    value=29; \
    found: value; })

void func_nest()
{
    void print_nest()
    {
        printf("In func_nest()\n");
    }
    print_nest();
}

int main()
{
    __label__ something, otherthing;
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int target = search(array, 8);

    printf("Found %d\n", target);

    func_nest();

    goto otherthing;
something:
    printf("hello gnuc\n");
    return 0;
otherthing:
    printf("hello otherthing\n");
    return 0;
}