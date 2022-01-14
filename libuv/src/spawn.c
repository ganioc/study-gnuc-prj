#include <stdio.h>
#include <uv.h>
<<<<<<< HEAD
=======
#include <stdlib.h>
#include <unistd.h>
>>>>>>> master

uv_loop_t *loop;
uv_process_t child_req;
uv_process_options_t options;

<<<<<<< HEAD
void on_exit(
    uv_process_t *req,
    int64_t exit_status,
    int term_signal){
    fprintf(stderr, "Process exited with status %llx, signal %d\n", exit_status, term_signal);
    uv_close((uv_handle_t*) req, NULL);

}

int main(){
    char* args[3];
    printf("spawn process.\n");

    loop = uv_default_loop();
    args[0] = "mkdir";
    args[1] = "test-dir";
    args[2] = NULL;

    options.exit_cb = on_exit;
    options.file = "mkdir";
    options.args = args;

    int r;
    if((r = uv_spawn(loop, &child_req, &options))){
        fprintf(stderr, "%s\n", uv_strerror(r));
        return 1;
    }else{
        fprintf(stderr, "Launched process with ID%d\n", child_req.pid);
    }
    return uv_run(loop, UV_RUN_DEFAULT);
    // return 0;
=======
void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
  buf->base = malloc(suggested_size);
  buf->len = suggested_size;
}

void echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
    
    if (nread > 0) {
        printf("echo_read : %zd\n", nread);
        printf("---------------------------\n");
        printf("%s\n",buf->base);
        printf("---------------------------\n");
    }

    if (nread < 0) {
        if (nread != UV_EOF)
            fprintf(stderr, "Read error %s\n", uv_err_name(nread));
        uv_close((uv_handle_t*) client, NULL);
    }

    free(buf->base);
}
void on_exit(
    uv_process_t *req,
    int64_t exit_status,
    int term_signal)
{
    fprintf(stderr, "Process exited with status %llx, signal %d\n", exit_status, term_signal);
    uv_close((uv_handle_t *)req, NULL);
}

int main()
{
    char *args[3];
    printf("spawn process.\n");

    loop = uv_default_loop();
    args[0] = "ls";
    args[1] = "-la";
    args[2] = NULL;

    uv_stdio_container_t child_stdio[3];
    uv_pipe_t pipe;
    uv_pipe_init(loop, &pipe, 0);

    child_stdio[0].flags =UV_IGNORE;
    child_stdio[1].flags = UV_CREATE_PIPE | UV_WRITABLE_PIPE;
    child_stdio[1].data.stream = (uv_stream_t*)&pipe;
    child_stdio[2].flags = UV_IGNORE;

    options.stdio = child_stdio;
    options.stdio_count = 3;
    options.exit_cb = on_exit;
    options.file = args[0];
    options.args = args;

    int r;
    if ((r = uv_spawn(loop, &child_req, &options)))
    {
        fprintf(stderr, "%s\n", uv_strerror(r));

        return 1;
    }
    else
    {
        fprintf(stderr, "Launched process with ID%d\n", child_req.pid);
    }
    uv_read_start((uv_stream_t *)&pipe,alloc_buffer, echo_read);

    uv_run(loop, UV_RUN_DEFAULT);

    return 0;
>>>>>>> master
}