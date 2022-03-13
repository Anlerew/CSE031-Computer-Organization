#include <stdio.h>
#include <string.h>

char* append (char s1[ ], char s2[ ]) {
	strcat(s1, s2);
    return s1;
}

int main ( ) {
    char str1[10];
    char str2[10];
    while (1) {
        printf ("str1 = ");
        if (!gets (str1)) {
            return 0;
        };
        printf ("str2 = ");
        if (!gets (str2)) {
            return 0;
        };
        printf ("The result of appending str2 to str1 is %s.\n", 
            append (str1, str2));
    }
    return 0;
}
