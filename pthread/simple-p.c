#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void do_one_thing(int *);
void do_another_thing(int *);
void do_wrap_up(int, int);

int shared_mem_id;
int *shared_mem_ptr;
int *r1p;
int *r2p;

extern int main(void) {
    pid_t child1_pid, child2_pid;
    int status;
    // inti shared memroy segment
    shared_mem_id = shmget(IPC_PRIVATE, 2 * sizeof(int), 0660);
    shared_mem_ptr = (int *)shmat(shared_mem_id, (void *)0, 0);
    r1p = shared_mem_ptr;
    r2p = (shared_mem_ptr + 1);
    if ((child1_pid = fork()) == 0) {
	do_one_thing(r1p);
	exit(0);
    }

    if ((child2_pid = fork()) == 0) {
	do_another_thing(r2p);
	exit(0);
    }

    waitpid(child1_pid, &status, 0);
    waitpid(child2_pid, &status, 0);
    do_wrap_up(*r1p, *r2p);
    return 0;
}
void do_one_thing(int *pnum_times) {
    int i, j, x;
    for (i = 0; i < 4; i++) {
	printf("doint one thing\n");
	for (j = 0; j < 10000; j++) x = x + i;
	(*pnum_times)++;
    }
}
void do_another_thing(int *pnum_times) {
    int i, j, x;
    for (i = 0; i < 4; i++) {
	printf("doing another thing\n");
	for (j = 0; j < 10000; j++) x = x + i;
	(*pnum_times)++;
    }
}
void do_wrap_up(int one_times, int another_times) {
    int total;
    total = one_times + another_times;
    printf("wrap up: one thing %d, another %d, total %d\n", one_times,
	   another_times, total);
}

