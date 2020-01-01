#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TCOUNT 10
#define WATCH_COUNT 12

int count = 0;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_threshold_cv = PTHREAD_COND_INITIALIZER;
long thread_ids[3] = {0, 1, 2};

void *watch_count(void *idp) {
  long myidp = (long)idp;
  pthread_mutex_lock(&count_mutex);
  while (count <= WATCH_COUNT) {
    pthread_cond_wait(&count_threshold_cv, &count_mutex);
    printf("watch_count(): Thread %ld,Count is %d\n", myidp, count);
  }
  pthread_mutex_unlock(&count_mutex);
  pthread_exit(NULL);
}
void *inc_count(void *idp) {
  int i;
  long myidp = (long)idp;
  for (i = 0; i < TCOUNT; i++) {
    pthread_mutex_lock(&count_mutex);
    count++;
    printf("inc_count(): Thread %ld, old count %d, new count %d\n", myidp,
           count - 1, count);
    if (count == WATCH_COUNT) {
      pthread_cond_signal(&count_threshold_cv);
    }
    pthread_mutex_unlock(&count_mutex);
  }
  pthread_exit(NULL);
}
int main(void) {
  int i;
  pthread_t threads[3];
  pthread_create(&threads[0], NULL, inc_count, (void *)thread_ids[0]);
  pthread_create(&threads[1], NULL, inc_count, (void *)thread_ids[1]);
  pthread_create(&threads[2], NULL, watch_count, (void *)thread_ids[2]);
  for (i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
