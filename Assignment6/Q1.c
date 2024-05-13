#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int ret, i, j, s;
	for(i=1; i<=5; i++) {
		ret = fork();
		if(ret == 0) {
			for(j=1; j<=5; j++) {
				printf("Child%d: PID: %d count: %d\n",i,getpid(),j);
				sleep(1);
			}
			_exit(0);
		}
		else {
			if(i == 5) {
				for(j=1; j<=5; j++) {
				wait(&s);
				printf("child exit: %d\n",WEXITSTATUS(s));
				}
			}
		}
	}
	printf("program completed..\n");
	return 0;
}

