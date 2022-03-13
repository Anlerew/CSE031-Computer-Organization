
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	head->next = NULL;
	
	printf("The address of head is: %p\n", &head);
	printf("The value of head is: %f\n", head);
	printf("The address of iValue is: %p\n", &head->iValue);
	printf("The address of fValue is: %p\n", &head->fValue);
	printf("The address of next is: %p\n", &head->next);

	return 0;
}