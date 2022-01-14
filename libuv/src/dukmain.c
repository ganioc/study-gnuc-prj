#include <stdio.h>
#include "duktape.h"

static duk_ret_t native_print(duk_context *ctx){
    duk_push_string(ctx, "XX");
    duk_insert(ctx, 0);
    duk_join(ctx, duk_get_top(ctx) -1);
    printf("%s\n", duk_safe_to_string(ctx, -1));
    return 0;
}
static duk_ret_t native_adder(duk_context *ctx){
    int i;
    int n = duk_get_top(ctx);
    double res = 0.0;

    for(i=0; i< n; i++){
        res += duk_to_number(ctx, i);
    }

    duk_push_number(ctx, res);
    return 1;
}

int main(int argc, char *argv[]){
    printf("dukmain()\n");
    duk_context *ctx = duk_create_heap_default();
    char *str;
    char* buf;
    (void)argc;
    (void)argv;
    int len,i;
    duk_idx_t child;

    duk_idx_t arr_idx;

    duk_push_string(ctx, "base");

    arr_idx = duk_push_array(ctx);
    printf("origin top on value stack %d\n", duk_get_top(ctx));
    printf("arr_idx: %d\n", arr_idx);
    // duk_push_int(ctx, 123);
    // duk_push_int(ctx, 234);
    // duk_push_int(ctx, 345);
    duk_push_string(ctx, "foo");
    duk_put_prop_index(ctx, arr_idx, 0);
    duk_push_string(ctx, "bar");
    duk_put_prop_index(ctx, arr_idx, 1);
    // arr_idx = duk_get_top(ctx);
    printf("get_top: %d\n", duk_get_top(ctx));
    duk_pop(ctx); // pop out array

    duk_push_int(ctx,123);
    duk_push_string(ctx, "context_dump");
    duk_push_context_dump(ctx);
    printf("%s\n", duk_to_string(ctx, -1));
    duk_pop(ctx);
    duk_pop_2(ctx);

    str = duk_get_string(ctx, -1);
    printf("stack -1: %s\n", str);

    // arr_idx = duk_push_array(ctx);
    buf = duk_push_dynamic_buffer(ctx, 0);
    // buf[0] = 'a';
    // buf[1] = 'a';
    // buf[2] = 'a';
    buf = duk_require_buffer(ctx, -1, &len);
    printf("len: %d\n", len);
    buf = duk_resize_buffer(ctx, -1, len + 2);
    buf[len+0] = 'b';
    buf[len+1] = 'b';

    // buf =  duk_push_buffer(ctx,2,0);
    // buf[0] = 'b';
    // buf[1] = 'b';

    if(duk_is_array(ctx, -1)){
        printf("-1 is array\n");
    }else if(duk_is_buffer(ctx, -1)){
        printf("-1 is buffer\n");
    }
    else{
        printf("-1 is not array\n");
    }

    buf=duk_require_buffer(ctx, -1, &len);
    for(i=0; i< len; i++){
        printf("%d,%c - ", buf[i], buf[i]);
    }
    printf("\n");
    duk_pop(ctx);


    printf("test global object =>\n");
    duk_push_global_object(ctx);
    duk_push_string(ctx,"ABCD");
    // // buf[0]='B';
    duk_put_global_string(ctx,"spawn_sync_stdout");
    // // duk_put_prop_string(ctx,-2,"spawn_sync_cb");
    duk_pop(ctx);

    printf("read global object out =>\n");
    duk_get_global_string(ctx, "spawn_sync_stdout");
    str = duk_get_string(ctx, -1);
    printf("%s\n", str);
    duk_push_null(ctx);
    duk_put_global_string(ctx,"spawn_sync_stdout");
    duk_pop(ctx);

    printf("read again =>\n");
    duk_get_global_string(ctx, "spawn_sync_stdout");
    str = duk_get_string(ctx, -1);
    printf("%s\n", str);
    duk_pop(ctx);

    printf("--------------------------------------\n");

    duk_push_int(ctx,10);
    duk_push_int(ctx,12);
    printf("get push int 0: %d\n", duk_get_int(ctx,0));
    printf("get push int -1: %d\n", duk_get_int(ctx,-1));

    duk_push_c_function(ctx, native_print, DUK_VARARGS);
    duk_put_global_string(ctx, "print");
    duk_push_c_function(ctx, native_adder, DUK_VARARGS);
    duk_put_global_string(ctx, "adder");

    duk_eval_string(ctx, "print('hello world for it!');");
    duk_eval_string(ctx, "print('2+4+5=' + adder(2,4,5));");
    duk_pop(ctx);



    duk_destroy_heap(ctx);

    return 0;
}