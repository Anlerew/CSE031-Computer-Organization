// MY PROJECT PARTNER & COLLABORATOR: DAVID NGUYEN
// UC MERCED CSE 031 SPRING 2019
// PROJECT 1


#include <stdio.h>
#include <stdlib.h>
// Declare printSudoku function
void printSudoku(int***);
// Declare solveSudoku function
int solveSudoku(int***);
//Helper functions. You can define any functions that can help your solve the problem
int matCheck(int ***arr, int, int);
int statusCheck(int ***arr, int*, int*, int*);
int checkX(int ***arr, int, int, int);
int checkY(int ***arr, int, int, int);
int matCheck(int ***arr, int mat, int num){
	int x, value;
	for (x = 0; x < 3; x++){	
		for (value = 0; value < 3; value++){
			if (*(*(*(arr + mat)+ x)+ value) == num){
				return 1;
			}
		}
	}
	return 0;
}
int statusCheck(int ***arr, int *mat, int *x, int *value){
	int i, j, k;
	for (i = 0; i < 9; i++){								//Number of matricies
		for (j = 0; j < 3; j++){							//Number of rows
			for (k = 0; k < 3; k++){						//Values of 1 though 3 in given row
				if (*(*(*(arr + i) + j) + k) == 0) {
					*(mat) = i;
					*(x) = j;
					*(value) = k;
					return 1; 								//If present
				}

			}
		}
	}
	return 0;												//If not present
}
int checkX(int ***arr, int mat, int y, int num){ // 1 is true - 0 is false
	int x;
	if (mat < 3){ 											// Matrix 1 through 3
		x = 0; 												// Rows 1 through 3
	}
	else if (mat < 6){ 										//Matrix 4 through 6
		x = 3; 												// Rows 4 though 6
	}
	else													//Matrix 7 though 9
		x = 6;												//Rows 7 though 9
	int stop = x + 3;										//When matrix is 0, the matrix will be 1 and can check from rows 1 through 3
	for (x; x < stop; x++){									//Rows go from 1 through 3
		for (int value = 0; value < 3; value++){			//Matrix 1, checks the values of 1 through 3 of the given matrix row
			if (num == (*(*(*(arr + x) + y) + value))){		//Must move right on the columns in order to check the rows
				return 1;
			}
		}
	}
	return 0;
} 															//In order to check columns, you must check the values from left to right (must use int j)														
int checkY(int ***arr, int mat, int x, int num){
	int y;
	if (mat == 0 || mat == 3 | mat == 6){					//Matrix 1 - 4 - 7
		y = 0;												//Column 1 - 4 - 7
	}
	else if (mat == 1 || mat == 4 || mat == 7){				//Matrix 2 - 5 - 8
		y = 1;												//Column 2 - 5 - 8
	}
	else													//Matrix 3 - 6 - 9
		y = 2;												//Column 3 - 6 - 9
	int stop = y + 7;										//When matrix is 0,  the matrix will be 1, 4, 7 and can check from columns 1, 4, 7
	int value;
	for (y; y < stop; y = y + 3){ 							//Columns go from 1 to 4 to 7
		for (value = 0; value < 3; value++){				//Matrix 1, checks the values of 1 through 3 of the given matrix column
			if (num == (*(*(*(arr + y) + value) + x))){		// Must move down the rows in order to check the columns
				return 1;
			}
		}
	}
	return 0;
}															//In order to check the matrix, you must check if the value in the row is equal to num
/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNCTION!!!
*/
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    int ***blocks = (int***)malloc(9 * sizeof(int**));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open File!\n");
        return 0;
    }

	// Read 9x9 blocks into 2D arrays
    for(i=0; i<9; i++)
    {
        *(blocks+i) = (int**)malloc(3 * sizeof(int*));
        printf("Reading numbers in block %d... \n", i+1);
        for(j=0; j<3; j++)
        {
            *(*(blocks+i)+j) = (int*)malloc(3 * sizeof(int));

                fscanf(fptr, "%d %d %d", *(*(blocks+i)+j), *(*(blocks+i)+j)+1, *(*(blocks+i)+j)+2);
                printf("%d %d %d\n", *(*(*(blocks+i)+j)), *(*(*(blocks+i)+j)+1), *(*(*(blocks+i)+j)+2));
        }
    }

	// Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);

	// Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    if(solveSudoku(blocks)){
        printf("Sudoku solved!\n");
        printSudoku(blocks);
    }
    else
        printf("This Sudoku cannot be solved!\n");

    return 0;
}
void printSudoku(int*** arr){
	// This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions.

	// Your implementation here
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                printf("%d ", *(*(*(arr + j) + i) + k));	//Prints from matrix 0 through 3
            }
			printf("|");
        }
        printf("\n");
    }
	printf("---------------------");
	printf("\n");
	for (i = 0; i < 3; i++){
        for (j = 3; j < 6; j++){
            for (k = 0; k < 3; k++){
                printf("%d ", *(*(*(arr + j) + i) + k));	//Prints from matrix 3 through 6
            }
			printf("|");
        }
        printf("\n");
    }
	printf("---------------------");
	printf("\n");
    for (i = 0; i < 3; i++){
        for (j = 6; j < 9; j++){
            for (k = 0; k < 3; k++){
                printf("%d ", *(*(*(arr + j) + i) + k));	//Prints from matrix 6 though 9
            }
			printf("|");
        }
        printf("\n");
    }
	printf("---------------------");
	printf("\n");
}
int solveSudoku(int*** blocks){
	// This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
	// YOU MUST NOT USE ANY ARRAY NOTATION ([])!

	//Your implementation here
	int mat, x, value;
	int num = 1;
	if (statusCheck(blocks, &mat, &x, &value) == 0) {
		return 1;
	}
	else {
		for (num = 1; num < 10; num++) { 					//Checks values with num ranging from 1 though 9
			if(checkY(blocks, mat, value, num) == 0
				&& checkX(blocks, mat, x, num) == 0
				&& matCheck(blocks, mat, num) == 0
				&& *(*(*(blocks + mat) + x)+ value) == 0) {	//Combines all if statements to check each row, column, and matrix
					*(*(*(blocks + mat) + x)+ value) = num;
				if (solveSudoku(blocks) == 1){
					return 1;
				}
				else {
					*(*(*(blocks + mat)+ x)+ value) = 0;	//Sets the value back to zero if value is not found
				}
			}
		}
	}
return 0;
}