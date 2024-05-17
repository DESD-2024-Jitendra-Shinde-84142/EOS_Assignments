#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


int main() {
	int fd1, fd2, count;
	int arr[3];
	fd1 = open("/home/jitendra/Desktop/assign_p1_fifo", O_RDONLY);
	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for numbers...\n ");
	count = read(fd1, arr, sizeof(arr));
	printf("read from fifo: %d bytes -- %d  %d\n",count, arr[0],arr[1]);
	
	arr[2] = arr[0] + arr[1];
	

	fd2 = open("/home/jitendra/Desktop/assign_p2_fifo", O_WRONLY);
	if(fd2 < 0) {
		perror("open() failed");
		_exit(1);
	}
	
	count = write(fd2, arr, sizeof(arr));
	printf("Sum is sent to P1...\n");
	
	close(fd1);
	close(fd2);
	return 0;
}
