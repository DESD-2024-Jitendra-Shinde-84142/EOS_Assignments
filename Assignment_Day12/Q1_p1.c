#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
	int fd1, fd2, count;
	int arr[3];
	fd1 = open("/home/jitendra/Desktop/assign_p1_fifo", O_WRONLY);
	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("Enter two numbers : ");
	scanf("%d %d",&arr[0],&arr[1]);

	count = write(fd1, arr, sizeof(arr));
	printf("written in fifo: %d bytes\n",count);
	
	fd2 = open("/home/jitendra/Desktop/assign_p2_fifo", O_RDONLY);
	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}
	
	count = read(fd2, arr, sizeof(arr));
	printf("Sum = %d\n",arr[2]);

	close(fd1);
	close(fd2);
	return 0;
}
