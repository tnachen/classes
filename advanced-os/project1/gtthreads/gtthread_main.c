#include <stdio.h>
#include <stdlib.h>
#include "gtthread.h"

static gtthread_t t1;
static gtthread_t t2;
static gtthread_mutex_t a;


/* Tests creation.
   Should print "Hello World!" */

void *thr1(void *in) {
  gtthread_mutex_lock(&a); 
  printf("Hello World!\n");
  fflush(stdout);
  gtthread_mutex_unlock(&a);
  return NULL;
}

void *thr2(void *in) {
  gtthread_mutex_lock(&a); 
  printf("Hello World 2!\n");
  fflush(stdout);
  gtthread_mutex_unlock(&a);
  return NULL;
}

int main() {
  gtthread_init(0);
  gtthread_create( &t1, thr1, NULL);
  gtthread_create( &t2, thr2, NULL);
  gtthread_mutex_init(&a);
  gtthread_join(t1, NULL);
  gtthread_join(t2, NULL);
  gtthread_mutex_destroy(&a);
  printf("Hello World 3!\n");
  fflush(stdout);
  
  return EXIT_SUCCESS;
}
