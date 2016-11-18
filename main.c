#include <pthread.h>
#include <stdio.h>

void *PrintHello(void *threadid){
  long tid;
  tid = (long)threadid;
  printf("HelloWorld! It’sme, thread #%ld!\n", tid);
  pthread_exit(NULL);
}
int main (int argc,char* argv[]){
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0; t<NUM_THREADS; t++){
    printf("Inmain:creatingthread%ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void*)t);
    if(rc){
      printf("ERROR; returncode from pthread_create() is %d \n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
