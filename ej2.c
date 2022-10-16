#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ITERACIONES 100
#define GRUPOS 15


int main()
{
    #pragma omp parallel for schedule(dynamic,GRUPOS)
        for (int i=0; i < ITERACIONES; i++)
            printf("Numero de hilo %d   Numero de iteracion %d \n", omp_get_thread_num(),i );
        	usleep(1000);
}