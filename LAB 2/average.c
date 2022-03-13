#include <stdio.h>

int main() {
  int values=0,input=0;	
  double sum=0;
  printf("Enter input values (enter 0 to finish):\n");
  scanf("%d",&input);
  while(input != 0) {
    values++;
    sum += input;
    scanf("%d",&input);
  }
  printf("Average: %g\n",sum/values);
  return 0;
}

