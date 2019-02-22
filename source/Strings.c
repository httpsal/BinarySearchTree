#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Strings.h"


int compareStrings(void *a, void *b) {
	char *stringA = (char *) a;
	char *stringB = (char *) b;

	return strcmp(stringA, stringB);
}

void printString(void *key) {
	char *keyString = (char *) key;
	printf("%s", keyString);
}

void *getString(void) {

	char buffer[SIZE], *input = NULL;
	int dim = 0;

	if (fgets(buffer, SIZE, stdin)) {

		dim = getStringDimension(buffer);

		if (dim > 0) {
			input = (char *) malloc(sizeof(char) * dim);

			if (input != NULL) {
				sscanf(buffer, "%s", input);
				return (void *) input;
			}
		}
	}

	return NULL;
}

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

void deleteString(void *key) {
	if (key) {
		free(key);
	}
	key = NULL;
}

