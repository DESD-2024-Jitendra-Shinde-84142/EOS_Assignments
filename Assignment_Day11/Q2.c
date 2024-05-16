#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int arr1[2], arr2[2], ret, ret1, ret2, num1, num2, res=0, s;

	ret = pipe(arr1);
	if(ret < 0) {
		perror("pipe1() failed");
		_exit(1);
	}
	ret = pipe(arr2);
	if(ret < 0) {
		perror("pipe2() failed");
		_exit(1);
	}
	ret = fork();
	if(ret == 0) {
		close(arr1[0]);
		close(arr2[1]);
		printf("Enter two numbers: ");
		scanf("%d %d", &num1, &num2);
		ret1 = write(arr1[1],&num1,sizeof(num1));
		ret2 = write(arr1[1],&num2,sizeof(num2));
		printf("child: num1 written in pipe: %d byte\n",ret1);
		printf("child: num2 written in pipe: %d byte\n",ret2);
		
		read(arr2[0],&res,sizeof(res));
		printf("Result: %d\n",res);

		close(arr2[0]);
		close(arr1[1]);
	}
	else {
		close(arr1[1]);
		close(arr2[0]);
		
		ret1 = read(arr1[0], &num1, sizeof(n1));
		ret2 = read(arr1[0], &num2, sizeof(n2));

		printf("Parent: num1 read in pipe: %d byte\n",ret1);
		printf("Paretn: num2 read in pipe: %d byte\n",ret2);
		res = num1 + num2;

		write(arr2[1], &res, sizeof(res));
		

		close(arr2[1]);
		close(arr1[0]);
		waitpid(-1,&s,0);
	}
	return 0;
}
