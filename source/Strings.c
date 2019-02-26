#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Strings.h"

/**
 *
 */
int compareStrings(void *a, void *b) {
	char *stringA = (char *) a;
	char *stringB = (char *) b;

	return strcmp(stringA, stringB);
}

/**
 *
 */
void printString(void *key) {
	char *keyString = (char *) key;
	printf("%s", keyString);
}

/**
 *
 */
void *getString(void) {

	char buffer[SIZE], *input = NULL;
	int dim = 0;

	if (fgets(buffer, SIZE, stdin)) {

		dim = getStringDimension(buffer);

		if (dim > 0) {
			input = (char *) malloc(sizeof(char) * (dim + 1));

			if (input != NULL) {
				sscanf(buffer, "%s", input);
				input[dim] = '\0';
				return input;
			}
		}
	}

	return NULL;
}

/**
 *
 */
int getStringDimension(char *string) {
	int dim = 0;
	if (string != NULL) {
		while (string[dim] != EOF && string[dim] != ' ' && string[dim] != '\n'
				&& string[dim] != '\0') {
			dim++;
		}
	}
	return dim;
}

/**
 *
 */
void *getRandomString(void) {

	/* Characters to pick up. */
	const char characters[] = "0123456789"
			"abcdefghilmnopqrstuvz"
			"ABCDEFGHILMNOPQRSTUVZ";

	int dimCharacters = sizeof(characters) - 1;
	int i, dimRandom = 6;

	char *random = (char *) malloc(sizeof(char) * (dimRandom + 1));

	if (random) {
		for (i = 0; i < dimRandom; i++) {
			random[i] = characters[rand() % dimCharacters];
		}
		random[i] = '\0';
		return random;
	}
	return NULL;
}

/**
 *
 */
void deleteString(void *key) {
	if (key) {
		free(key);
	}
	key = NULL;
}

/**
 *
 */
void *copyString(void *from) {
	int dim = strlen(from);
	char *to = NULL;

	if (from != NULL) {
		// Need to add an extra space for '\0'
		to = (char *) malloc(sizeof(char) * (dim + 1));

		if (to != NULL) {
			to = strncpy(to, from, dim);
			to[dim] = '\0';
		}
	}
	return to;
}

