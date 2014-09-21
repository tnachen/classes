#include <stdio.h>
#include <stdlib.h>
#include "gtthread.h"

static int answer = 100;

/* Tests creation.
   Should print "Hello World!" */

void *thr1(void *in) {
  printf("Hello World!\n");
  fflush(stdout);
  return &answer;
}

int main() {
  gtthread_t t1;
  gtthread_t t2;

  gtthread_init(0);
  gtthread_create( &t1, thr1, NULL);
  gtthread_create( &t2, thr1, NULL);
  void * i1;
  void * i2;
  gtthread_join(t1, &i1);
  gtthread_join(t2, &i2);

  printf("i1 %i\n", *(int *)i1);
  printf("i2 %i\n", *(int *)i2);
  
  return EXIT_SUCCESS;
}
