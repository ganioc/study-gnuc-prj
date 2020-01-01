#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void do_one_thing(int *);
void do_another_thing(int *);
void do_wrap_up(int, int);

int r1 = 0, r2 = 0, r3 = 0;
pthread_mutex_t r3_mutex = PTHREAD_MUTEX_INITIALIZER;
void do_wrap_up(int r1, int r2) {
    printf("r1 is: %d\n", r1);
    printf("r2 is: %d\n", r2);
}
void do_another_thing(int *pnum_times) {
  int i, j, x;
  pthread_mutex_lock(&r3_mutex);
  if (r3 > 0) {
    x = r3;
    r3--;
  } else {
    x = 1;
  }
  pthread_mutex_unlock(&r3_mutex);
  for (i = 0; i < 4; i++) {
    printf("doing another thing\n");
    for (j = 0; j < 10000; j++) {
      x = x + i;
    }
    (*pnum_times)++;
  }
}


void do_one_thing(int *pnum_times) {
   int i, j, x;
    pthread_mutex_lock(&r3_mutex);
    if (r3 > 0) {
	x = r3;
	r3--;
    } else {
	x = 1;
    }
    pthread_mutex_unlock(&r3_mutex);
    for (i = 0; i < 4; i++) {
	printf("doing one thing\n");
	for (j = 0; j < 10000; j++) {
	    x = x + i;
	}
	(*pnum_times)++;
    }
}

extern int
main(int argc, char **argv){
	pthread_t thread1, thread2;
	r3 = atoi(argv[1]);

	pthread_create(&thread1,
			NULL,
			(void *)do_one_thing,
			(void *) &r1);
	pthread_create(&thread2,
			NULL,
			(void *) do_another_thing,
			(void *) &r2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	do_wrap_up(r1,r2);
	return 0;

}


