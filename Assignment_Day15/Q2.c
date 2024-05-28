#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 6

struct array{
	int *arr;
	int size;
};

void* bubble_sort(void* param){
	int i, j, temp;

	struct array* ar = (struct array*)param;

	for(i=0; i<ar->size-1; i++)
	{
		for(j=0; j<ar->size-1-i; j++)
		{
			if((ar->arr[j]) > (ar->arr[j+1]))
			{
				temp = ar->arr[j];
				ar->arr[j] = ar->arr[j+1];
				ar->arr[j+1] =temp;
			}

		}
	}

	return NULL;
}

int main(){
	int i, ret;
	int ar[] = {56, 87, 16, 26, 97, 69};
	pthread_t t1;
	struct array a1 = {a1.arr = ar, a1.size = SIZE};
	

	printf("Array before sort: ");
	for(i=0; i<a1.size; i++)
	{
		printf("%d\n", a1.arr[i]);
	}

	ret = pthread_create(&t1, NULL, bubble_sort, &a1);

	pthread_join(t1, NULL);

	printf("Array after sort: ");
	for(i=0; i<a1.size; i++)
	{
		printf("%d\n", a1.arr[i]);
	}
	
	return 0;

}
