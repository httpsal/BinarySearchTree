#include <stdio.h>
#include <stdlib.h>

#include "../header/Operations.h"

/**
 *
 */
struct op *initOperations(op_type type) {

	struct op *operation = (struct op *) malloc(sizeof(struct op));
	if (operation != NULL) {
		switch (type) {
			case integer:
				operation->compare = compareInt;
				operation->print = printInt;
				operation->delete = deleteInt;
				operation->getInput = getInt;
				operation->getRandom = getRandomInt;
				operation->copy = copyInt;
				break;

			case strings:
			default:
				operation->compare = compareStrings;
				operation->print = printString;
				operation->delete = deleteString;
				operation->getInput = getString;
				operation->getRandom = getRandomString;
				operation->copy = copyString;
				break;
		}

		return operation;
	}
	return NULL;
}

/**
 *
 */
void freeOperations(struct op *operation) {
	if (operation) {
		free(operation);
	}
	operation = NULL;
}

