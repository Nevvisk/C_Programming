#include<stdio.h>

int main () {
	const char* testing[] = {"does", "this", "even", "work", "?", NULL};
	const int NUM1 = 3;
	const int NUM2 = 5;
	printf("Hello World!\n");
	char **c = testing; 
	while (*c != NULL) {
		printf("%s\n", *c);
		++c;
	}
	printf("Adding %d and %d\n", NUM1, NUM2);
	int result = NUM1 + NUM2;	
	printf("%d\n", result);
	return 0;
}
