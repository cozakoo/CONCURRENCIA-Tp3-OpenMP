#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long num_steps = 1000000; //Factor de precisión
double step; //cantidad de triangulos

int main(int argc, char *argv[])
{
    long i; 
    double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;

    #pragma omp parallel for num_threads(4) reduction(+:sum)
    for (i=0; i< num_steps; i++)
    {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }
    pi = step * sum;
    
    printf("VALOR DE PI %f \n", pi);
    printf("NUMERO DE STEP %f \n", step);
}