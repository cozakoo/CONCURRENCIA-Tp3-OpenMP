#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    #pragma omp parallel num_threads(4)
    { 
        #pragma omp critical
            printf("Soy el hilo %d\n", omp_get_thread_num());

        #pragma omp barrier
            #pragma omp single
                printf("Todos los hilos terminaron\n");
    }
}