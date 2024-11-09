#include<stdio.h>

int main () {
	const char* testing[] = {"does", "this", "even", "work", "?", NULL};
	printf("Hello World!\n");
	char **c = testing; 
	while (*c != NULL) {
		printf("%s\n", *c);
		++c;
	}
	return 0;
}
