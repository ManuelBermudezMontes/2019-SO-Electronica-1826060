#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	if(argc!=2){
	 	printf("Porfavor digitar un numero \n");
		exit(-1);
	}
	int memorysize = atoi(argv[1]);
	memorysize = memorysize*1024*1024;
	int *arreglo = (int *) malloc(sizeof(int) * memorysize);

	if(arreglo ==NULL){
		printf("error en la asignacion de  memoria\n");
		exit(-1);
	}
	int i=0;
	for(;i < memorysize; i++){
		arreglo[i]=i;
	}
	sleep(10);
	free(arreglo);
}
