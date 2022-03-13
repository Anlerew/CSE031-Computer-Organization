#include <stdio.h>
int main()
{
	char sentence[] = "C programming language is the best!\n",
		wrongsentence[] = "C programming language is the bet!\n";
	int statements, typo;
	
	printf("Enter the number of lines for the punishment: ");
	scanf("%d", &statements);
	
	if (statements < 0){
		printf("You entered an incorrect value for the number of lines!\n");
		return 0;
	}

	printf("Enter the line for which we want to make a typo: ");
	scanf("%d", &typo);
	
	if (typo < 0 || typo > statements){
		printf("You entered an incorrect value for the line typo!\n");
		return 0;
	}
	
	for (int counter=0; counter < statements; counter++){
		if (typo == (counter+1))
			printf("%s", wrongsentence);
		else
			printf("%s", sentence);
	}
	return 0;
}
