all: ej1 ej2 ej3 ej4 ej5

ej1: ej1.c
	gcc ej1.c -o ej1 -fopenmp

ej2: ej2.c
	gcc ej2.c -o ej2 -fopenmp

ej3: ej3.c
	gcc ej3.c -o ej3 -fopenmp

ej4: ej4.c
	gcc ej4.c -o ej4 -fopenmp

ej5: ej5.c
	gcc ej5.c -o ej5 -fopenmp

clean:
	rm ej1 ej2 ej3 ej4 ej5

