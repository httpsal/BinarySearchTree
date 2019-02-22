#include <stdio.h>
#include <stdlib.h>
#include "../header/Integer.h"

int compareInt(void *a, void *b) {

	int *intA = (int *) a;
	int *intB = (int *) b;

	if (*intA < *intB) {
		return -1;
	} else if (*intA > *intB) {
		return 1;
	} else {
		return 0;
	}
}

void printInt(void *key) {
	int *keyInt = (int *) key;
	printf("%d", *keyInt);
}

void *getInt(void) {

	char buffer[SIZE];

	int *input = (int *) malloc(sizeof(int));
	if (input) {

		if (fgets(buffer, SIZE, stdin)) {
			sscanf(buffer, "%d", input);
			return (void *) input;
		}
	}

	return NULL;
}

void deleteInt(void *key) {
	if (key != NULL) {
		free(key);
	}
	key = NULL;
}

