#include <stdio.h>
#include <stdlib.h>
#include "gtthread.h"

static gtthread_t t1;
static gtthread_t t2;
static bool a = true;

/* Tests creation.
   Should print "Hello World!" */

void *thr1(void *in) {
  while(a) {
    gtthread_yield();
  }
  printf("Hello World!\n");
  fflush(stdout);
  return NULL;
}

void *thr2(void *in) {
  a = false;
  gtthread_join(t2, NULL);
  printf("Hello World 2!\n");
  fflush(stdout);
  return NULL;
}

int main() {
  gtthread_init(0);
  gtthread_create( &t1, thr1, NULL);
  gtthread_create( &t2, thr2, NULL);
  gtthread_join(t1, NULL);
  
  return EXIT_SUCCESS;
}
