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
	if (keyInt != NULL) {
		printf("%d", *keyInt);
	}
}

/**
 *
 */
void *getInt(void) {

	char buffer[SIZE];
	int *input = (int *) malloc(sizeof(int));

	if (input != NULL) {

		if (fgets(buffer, SIZE, stdin) != NULL) {
			if (buffer[0] != '\n') {
				sscanf(buffer, "%d", input);
				return (void *) input;
			} else {
				free(input);
			}
		}
	} else {
		printf("Abort: getInt\n");
		abort();
	}
	return NULL;
}

/**
 *
 */
void *getRandomInt(void) {
	int *random = (int *) malloc(sizeof(int));
	if (random != NULL) {
		*random = (rand() % 100) + 1;	// Random number between 1 and 100
		return (void *) random;
	} else {
		printf("Abort: getRandomInt\n");
		abort();
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
		} else {
			printf("Abort: copyInt\n");
			abort();
		}
	}
	return to;
}

/**
 *
 */
int isEvenInt(void *key) {
	int *intKey = (int *) key;
	if (intKey != NULL) {
		return *intKey % 2;
	}
	return -1;
}

