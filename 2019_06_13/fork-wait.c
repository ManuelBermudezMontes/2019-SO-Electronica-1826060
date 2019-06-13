#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main (int argc, char** argv)
{
	pid_t pid, pid2;
	int status;

	printf("holaa\n");
	pid = fork();
	printf("pid2: %d desde el proceso %d\n", pid2, getpid());
	if(pid != 0)
	{
		pid2 = wait(&status);
		printf("Soy el padre mi id es %d y el de mi hijo es %d \n",getpid(),pid);
	}
	else
	{
		sleep(3);
		printf("Soy el hijo con id %d y mi variable pid es %d \n", getpid(),pid);
	}
	printf("Mi identificador de proceso es%d \n", pid);
	return 0;
}

