
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **mul;
	int i, c, d, k, sum = 0;
	mul = (int **)malloc(size *sizeof(int *));
	for(i = 0; i < size; i++){
		mul[i] = (int *)malloc(size * sizeof(int));
	}
	for(c = 0; c < size; c++){
		for(d = 0; d < size; d++){
			for(k = 0; k < size; k++){
				sum = sum + a[c][k] * b[k][d];
			}
			mul[c][d] = sum;
			sum = 0;
		}
	}
	return mul;
}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d\t" , arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n = 3, i, j, count = 0;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	matA = (int **)malloc(n * sizeof(int *));
	for(i = 0; i < n; i++){
		matA[i] = (int *)malloc(n * sizeof(int));
	}
	
	matB = (int **)malloc(n * sizeof(int *));
	for(i = 0; i < n; i++){
		matB[i] = (int *)malloc(n * sizeof(int));
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matA[i][j] = ++count;
		}
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matB[i][j] = ++count;
		}
	}
	
	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printf("\n");
	printArray(matB, n);
	printf("\n");
	
	//(5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}