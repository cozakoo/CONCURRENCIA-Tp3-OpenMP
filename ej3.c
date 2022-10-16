#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

double resultado1, resultado2;


void funcion_tiempo_1(){

    double inicio, fin; 

    #pragma omp sections
    {
        #pragma omp section
        {    
            inicio = omp_get_wtime();
            usleep(1000);
            fin = omp_get_wtime();
        }
    }
    resultado1 = fin - inicio;
}



void funcion_tiempo_2(){

    double inicio, fin; 

    #pragma omp sections
    {
        #pragma omp section
        {         
            inicio = omp_get_wtime();
            usleep(1000);
            fin = omp_get_wtime();
        }
    }
    resultado2 = fin - inicio;
}


int main(int argc, char *argv[])
{
    #pragma omp parallel
    {
        funcion_tiempo_1();
        funcion_tiempo_2();
    }

    printf("El tiempo de ejecucion de la funcion 1 fue de %f \n", resultado1);
    printf("El tiempo de ejecucion de la funcion 2 fue de %f \n", resultado2);
}