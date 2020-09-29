#include <stdio.h>
#include "main.h"

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
    // void print_nest()
    // {
    printf("In func_nest()\n");
    // }
    // print_nest();
}

struct MY_STRUCT
{
    char c1;
    char c2;
    char c_array[5];
};

int function1(char *string, int num)
{
    printf("function1 is %s\n", string);
    return num + 1;
}
int function2(char *string, int num)
{
    void *arg_list;
    void *return_value;

    // arg_list = __builtin_apply_args();

    return 0;
}
int compute_example()
{
    int a = function2("", 0);
    printf("I am compute exmaple : %s\n", __FUNCTION__);
    return 0;
}
int main()
{
    __label__ something, otherthing;
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int target = search(array, 8);
    int i = 0;
    int test_a_arr[5] = {[0] = 10, [2] = 12};

    printf("Found %d\n", target);
    printf("file:%s, function:%s, line:%d\n", __FILE__, __FUNCTION__, __LINE__);

    func_nest();

    struct MY_STRUCT myStru;

    myStru.c1 = 1;
    myStru.c2 = 2;

    for (i = 0; i < 5; i++)
    {
        // int temp = i;
        myStru.c_array[i] = i;
    }

    debug("Error:%d\n", 99999);

    for (i = 0; i < sizeof(test_a_arr) / sizeof(int); i++)
    {
        printf("%d ", test_a_arr[i]);
    }
    printf("\n");
    debug("size of int:%lu\n", sizeof(int));

    compute_example();

    goto otherthing;
something:
    printf("hello gnuc\n");
    return 0;
otherthing:
    printf("hello otherthing\n");
    return 0;
}