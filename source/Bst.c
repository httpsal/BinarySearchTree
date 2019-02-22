#include <stdio.h>
#include <stdlib.h>

#include "../header/Bst.h"


struct op *initOperations(op_type type) {

	struct op *operation = (struct op *) malloc(sizeof(struct op));
	if (operation != NULL) {
		switch (type) {
			case integer:
				operation->compare = compareInt;
				operation->print = printInt;
				operation->delete = deleteInt;
				operation->getInput = getInt;
			break;

			case strings:
				operation->compare = compareStrings;
				operation->print = printString;
				operation->delete = deleteString;
				operation->getInput = getString;
			break;
		}

		return operation;
	}
	return NULL;
}



struct tree *insert(struct tree *T, void *key, struct op * operation) {

	if (T == NULL) {
		T = newNode(key);
	} else if (operation->compare(T->key, key) > 0) {
		T->left = insert(T->left, key, operation);
	} else if (operation->compare(T->key, key) < 0) {
		T->right = insert(T->right, key, operation);
	} else {
		printf("The element \"");
		operation->print(key);
		printf("\" is already inside the tree.\n");
	}
	return T;
}


struct tree *newNode(void *key) {

	if (key != NULL) {
		struct tree *node = (struct tree *) malloc(sizeof(struct tree));
		if (node != NULL) {
			node->key = key;
			node->left = node->right = NULL;
			return node;
		}
	}
	return NULL;
}

void inOrder(struct tree *T, struct op *operation) {
	if (T != NULL) {
		inOrder(T->left, operation);
		operation->print(T->key);
		printf(" ");
		inOrder(T->right, operation);
	}
}

struct tree *deleteAll(struct tree *T, struct op *operation) {
	/* Deleting each node through post order visit. */
	if (T != NULL) {
		deleteAll(T->left, operation);
		deleteAll(T->right, operation);
		deleteNode(T, operation);
	}
	return NULL;
}

void deleteNode(struct tree *T, struct op *operation) {
	operation->delete(T->key);
	free(T);
	T = NULL;
}

struct tree *insertMultipleElements(struct tree *T, struct op *operation, int n) {

	int i;
	void *key = NULL;
	printf("Insert inputs:\n");
	for (i = 0; i < n; i++) {
		printf("[%d]: ", i + 1);
		key = operation->getInput();
		T = insert(T, key, operation);

		printf("\n");
	}
	return T;
}
