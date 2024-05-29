#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
	int ret, fd, fd1;
	struct stat st;
	void *ptr,*ptr1,*ptr2;

	fd = open("/home/jitendra/Downloads/en.st-stm32cubeide_1.15.0_20695_20240315_1429_amd64.deb_bundle.sh.zip", O_RDONLY);
	if(fd < 0){
		perror("Open() failed..\n");
		close(fd);
		_exit(0);
	}

	ret = fstat(fd,&st);
	if(ptr < 0){
		perror("fstat() failed..\n");
		close(fd);
		_exit(0);
	}

	printf("Size of file: %lu\n", st.st_size);

	ptr = mmap(NULL,st.st_size,PROT_READ,MAP_PRIVATE,fd,0);
	if(ptr == (void*)-1){
		perror("mmap() failed..\n");
		close(fd);
		_exit(0);
	}
	
	printf("ptr_address: %p\n",ptr);

	fd1 = open("/home/jitendra/Desktop/EOS/Day20/jitu.sh.zip", O_CREAT | O_TRUNC | O_RDWR, 0600);
	if(fd1 < 0){
		perror("open() failed..\n");
		close(fd1);
		_exit(2);
	}

	ftruncate(fd1, st.st_size);

	ptr1 = mmap(NULL, st.st_size, PROT_WRITE , MAP_SHARED, fd1, 0);
	if(ptr1 == (void*)-1){
		perror("mmap() failed..\n");
		close(fd1);
		_exit(1);
	}
	
	printf("ptr1_address: %p\n",ptr1);

	ptr2 = memcpy(ptr1, ptr, st.st_size);
	if(ptr2 == (void*)-1){
		perror("memcpy() failed..\n");
		close(fd);
		close(fd1);
		_exit(2);
	}

	printf("ptr2_address: %p\n",ptr2);
	
	close(fd);
	close(fd1);

	return 0;
}
