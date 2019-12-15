#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

struct thread_data {
    int thread_id;
    int sum;
    char *message;
};

void *PrintHello(void *thread) {
    struct thread_data *my_data;

    long tid;
    int sum;
    char *hello_msg;
    my_data = (struct thread_data *)thread;
    tid = my_data->thread_id;
    sum = my_data->sum;
    hello_msg = my_data->message;

    printf("Hello world! It's me, thread #%ld!\n", tid);
    printf("Msg: %s\n", hello_msg);
    printf("Sum: %d\n", sum);
    pthread_exit(NULL);
}

struct thread_data thread_data_array[NUM_THREADS];
char *messages[NUM_THREADS] = {"Mary", "John", "Joe", "Clare", "Gun"};
int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    // long taskids[NUM_THREADS];

    printf("exam1\n");

    for (t = 0; t < NUM_THREADS; t++) {
	thread_data_array[t].thread_id = t;
	thread_data_array[t].sum = t + 5;
	thread_data_array[t].message = messages[t];

	printf("In main: creating thread %ld\n", t);
	rc = pthread_create(&threads[t], NULL, PrintHello,
			    (void *)&thread_data_array[t]);
	if (rc) {
	    printf("Error; return code from pthread_create()is %d\n", rc);
	    exit(-1);
	}
	}

	pthread_exit(NULL);
}

