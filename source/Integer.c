#include <stdio.h>
#include <stdlib.h>
#include "../header/Integer.h"

/**
 *
 */
int compareInt(void *a, void *b) {

	int *intA = (int *) a;
	int *intB = (int *) b;

	return *intA - *intB;
}

/**
 *
 */
void printInt(void *key) {
	int *keyInt = (int *) key;
	printf("%d", *keyInt);
}

/**
 *
 */
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

/**
 *
 */
void *getRandomInt(void) {
	int *random = (int *) malloc(sizeof(int));
	if (random) {
		*random = (rand() % 100) + 1;	// Random number between 1 and 100
		return random;
	}
	return NULL;
}

/**
 *
 */
void deleteInt(void *key) {
	if (key != NULL) {
		free(key);
	}
	key = NULL;
}

/**
 *
 */
void *copyInt(void *from) {
	int *to = NULL;
	if (from != NULL) {
		to = (int *) malloc(sizeof(int));
		if (to != NULL) {
			*to = *(int *) from;
		}
	}
	return to;
}

