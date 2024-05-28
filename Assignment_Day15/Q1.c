#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

int arr[10];

void* select_sort(void* param){
	int *arr = (int*)param;
	int i, j, *res, min_idx, temp, n = 10;

	for(i=0; i<n-1 ; i++){
		min_idx = i;
		for(j=i+1 ; j<n ; j++){
			if(arr[j] < arr[min_idx]){
				min_idx = j;
			}}
           	
            	temp = arr[min_idx];
				arr[min_idx] = arr[i];
				arr[i] = temp;
			}

	res = (int*)malloc(sizeof(arr));
	res = arr;
	pthread_exit(res);
	return NULL;
}

int main(){
	int ret, *result;
	pthread_t a1;
	int arr[] = {22, 11, 33, 55, 77, 44, 100, 66, 99, 88};

	ret = pthread_create(&a1,NULL,select_sort,arr);
	if(ret < 0 ){
		perror("pthread_create() failed!");
		_exit(1);
	}
	
	printf("Main thread is waiting for a1 thread....\n");
	pthread_join(a1, (void**)&result);

	printf("The sorted array is :\n");

	int i,n=10;
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	return 0;







}
