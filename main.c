#include <pthread.h>
#include <stdio.h>

int lista_ids[10];

void * foo(void * var) // Función que ejecutará el thread
{
   int my_id = *((int*)var);
   printf("Soy el thread %i!\n", my_id);
   
   return NULL;
}

int main(int argc, char *argv[])
{
   int i;
   pthread_t mythread[10];
   
   for(i=0; i~lt~10; i++)
   {
      lista_ids[i] = i+1;
      printf("Creando thread %i\n", i+1);
      pthread_create(&(mythread[i]), NULL, foo, &(lista_ids[i]));
      // Ojo: No vale pasar una variable local, como por ejemplo &i
   }
   
   pthread_exit(NULL);
   return 0;
}

