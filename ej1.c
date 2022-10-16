#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int cantidadHilos = atoi(argv[1]);

    if (cantidadHilos > 2){
        
         omp_set_num_threads(cantidadHilos);
      
        #pragma omp parallel 
            printf("soy el hilo %d y pertenezco al primer bloque \n",omp_get_thread_num()  ) ;

        printf("\n");

        #pragma omp parallel num_threads(cantidadHilos)
            printf("soy el hilo %d y pertenezo al segundo bloque \n", omp_get_thread_num());
    
    }else{
        printf("Tiene que ingresar un valor mayor a 2 \n");
    }
}