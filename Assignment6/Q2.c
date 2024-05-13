#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int retA, retB, retC, retD, s1, s2, s3, s4, i, s;
	retA = fork();
	if(retA == 0) 
	{
		retB = fork();
		if(retB == 0)
		{
			retC = fork();
			if(retC == 0)
			{
				retD = fork();
				if(retD == 0)
				{	
					printf(".");
					sleep(1);
					_exit(0);
				}
				printf(".");
				waitpid(retD, &s4, 0);
				sleep(1);
				_exit(0);
			}
			printf(".");
			waitpid(retC, &s3, 0);
			sleep(1);
			_exit(0);
		}
		printf(".");
		waitpid(retB, &s2, 0);
		sleep(1);
		_exit(0);
	}
	printf(".");
	waitpid(retA, &s1, 0);
	sleep(1);
}
