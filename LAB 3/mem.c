#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	handle = &ptr;
	*ptr = num;
	ptr = &num;
	handle = (int **)malloc(1 * sizeof(int *));
	
	printf("The address of num is: %p\n", &num);
	printf("The address of ptr is: %p\n", &ptr);
	printf("The address of handle is: %p\n", &handle);

	return 0;
} 

