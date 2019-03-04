#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../header/Floating.h"

/**
 *
 */
int compareFloat(void *a, void *b) {

	float floatA = newPrecision(*(float*) a, PRECISION);
	float floatB = newPrecision(*(float*) b, PRECISION);

	if (floatA < floatB) {
		return -1;
	} else if (floatA > floatB) {
		return 1;
	} else {
		return 0;
	}
}

/**
 *
 */
float newPrecision(float number, float decimal) {
	return trunc(pow(10, decimal) * (number)) / pow(10, decimal);
}

/**
 *
 */
void printFloat(void *key) {
	float *keyFloat = (float *) key;
	if (keyFloat != NULL) {
		printf("%.6f", *keyFloat);
	}
}

/**
 *
 */
void *getFloat(void) {

	char buffer[SIZE];
	float *input = (float *) malloc(sizeof(float));

	if (input != NULL) {

		if (fgets(buffer, SIZE, stdin) != NULL) {
			if (buffer[0] != '\n') {
				sscanf(buffer, "%f", input);
				return (void *) input;
			} else {
				free(input);
			}
		}
	} else {
		printf("Abort: getFloat\n");
		abort();
	}
	return NULL;
}

/**
 *
 */
void *getRandomFloat(void) {
	float *random = (float *) malloc(sizeof(float));
	if (random != NULL) {
		// Random number between 0.0 and 1.0
		*random = ((float) rand()) / ((float) RAND_MAX);
		return (void *) random;
	} else {
		printf("Abort: getRandomFloat\n");
		abort();
	}
	return NULL;
}

/**
 *
 */
void deleteFloat(void *key) {
	if (key != NULL) {
		free(key);
	}
	key = NULL;
}

/**
 *
 */
void *copyFloat(void *from) {
	float *to = NULL;
	if (from != NULL) {
		to = (float *) malloc(sizeof(float));
		if (to != NULL) {
			*to = *(float *) from;
		} else {
			printf("Abort: copyFloat\n");
			abort();
		}
	}
	return to;
}

/**
 *
 */
int isEvenFloat(void *key) {
	int *keyInt = (int *) key;
	if (keyInt != NULL) {
		return *keyInt % 2;
	}
	return -1;
}




