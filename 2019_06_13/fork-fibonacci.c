#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int guardarEntero(char *fn, int n)
{
	FILE *fp;
	fp = fopen(fn, "w");
	fprintf(fp, "%d", n);
	fclose(fp);
	return 0;
}
int leerEntero(char *fn)
{
	FILE *fp;
	int n;
	fp = fopen(fn, "r");
	fscanf(fp, "%d", &n);
	fclose(fp);
	return n;
}
int fibonacci(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main (int argc, char** argv)
{
	pid_t pid;
	int status;

	int fibonacciACalcular = atoi(argv[1]);
	int fibonacciCalculado;
	int fibonacciPorCien;

	printf("Fibonacci \n\n");
	pid = fork();

	if(pid != 0)//padre
	{
		wait(&status);
		fibonacciCalculado = leerEntero("hola.txt");
		fibonacciPorCien = fibonacciCalculado*100;
		printf("Fibonacci multiplicado por 100 =  %d \n", fibonacciPorCien);
	}
	else//hijo
	{
		fibonacciCalculado = fibonacci(fibonacciACalcular);
		printf("Fibonacci: %d \n", fibonacciCalculado);
		guardarEntero("hola.txt", fibonacciCalculado);
	}
	return 0;
}
