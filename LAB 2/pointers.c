#include <stdio.h>

int main(){
	int x, y, *px, *py;
	int arr[10];
	
	x = 0;
	px = &x;
	y = 0;
	py = &y;
	arr[0] = 0;
	

	printf("x is %d\n", x);
	printf("x address is %p\n\n", &x);
	
	printf("*px is %d\n", *px);
	printf("*px address is %p\n\n", &px);
	
	printf("y is %d\n", y);
	printf("y address is %p\n\n", &y);
	
	printf("*py is %d\n", *py);
	printf("*py address is %p\n\n", &py);

	printf("arr[0] is %d\n\n", arr[0]);
	
	for(int i = 0; i < 10; i++){
	void IncrementPtr(int **inc){
		*inc = *inc + i;
	}
	
	int *q = arr;
	IncrementPtr(&q);
	printf("arr[%d] is %d\n", i, *q);
	printf("address is %p\n", q);
	}
	return 0;
}