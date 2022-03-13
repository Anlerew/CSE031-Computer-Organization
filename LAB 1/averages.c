#include <stdio.h>
int main()
{
	int sumPos = 0, sumNeg = 0;
	int counterPos = 0, counterNeg = 0;
	int avgPos = 0, avgNeg = 0;
	int input;
	printf("Please enter an integer: ");
	while(scanf("%d", &input) == 1  && input != 0){
		printf("Please enter an integer: ");
		if (input < 0){
			sumNeg += input;
			counterNeg++;
		}
		else if (input > 0){
			sumPos += input;
			counterPos++;
		}
	}

	if (sumNeg != 0){
		avgNeg = (sumNeg/counterNeg);
		printf("Negative average: %d \n", avgNeg);
	}
	if (sumPos != 0){
		avgPos = (sumPos/counterPos);
		printf("Positive average: %d \n", avgPos);
	}
}