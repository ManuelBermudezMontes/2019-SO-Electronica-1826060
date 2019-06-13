#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char** argv)
{
	pid_t pid;

	printf("holaa\n");
	pid = fork();
	printf("holita!!\n");
	if(pid != 0)
	{
		printf("Soy el padre mi id es %d y el de mi hijo es %d \n",getpid(),pid);
	}
	else
	{
		printf("Soy el hijo con id %d y mi variable pid es %d \n", getpid(),pid);
	}
	printf("Mi identificador de proceso es%d \n", pid);
	return 0;
}
