#include <stdio.h>
#include <stdlib.h>

#include "../header/Bst.h"

/**
 *
 */
Tree *insertNode(Tree *T, void *key, struct op *operation) {

	if (T == NULL) {
		T = newNode(key);
	} else if (operation->compare(T->key, key) > 0) {
		T->left = insertNode(T->left, key, operation);
	} else if (operation->compare(T->key, key) < 0) {
		T->right = insertNode(T->right, key, operation);
	} else {
		printf("The element \"");
		operation->print(key);
		printf("\" is already inside the tree.\n");
	}
	return T;
}

/**
 *
 */
Tree *newNode(void *key) {

	if (key != NULL) {
		struct tree *node = (struct tree *) malloc(sizeof(Tree));
		if (node != NULL) {
			node->key = key;
			node->left = node->right = NULL;
			return node;
		}
	}
	return NULL;
}

/**
 *
 */
void inOrder(Tree *T, struct op *operation) {
	if (T != NULL) {
		inOrder(T->left, operation);
		operation->print(T->key);
		printf(" ");
		inOrder(T->right, operation);
	}
}

/**
 *
 */
void postOrder(Tree *T, struct op *operation) {
	if (T != NULL) {
		postOrder(T->left, operation);
		postOrder(T->right, operation);
		operation->print(T->key);
		printf(" ");
	}
}

/**
 *
 */
void preOrder(Tree *T, struct op *operation) {
	if (T != NULL) {
		operation->print(T->key);
		printf(" ");
		preOrder(T->left, operation);
		preOrder(T->right, operation);
	}
}

/**
 *
 */
Tree *deleteTree(Tree *T, struct op *operation) {
	/* Deleting each node through post order visit. */
	if (T != NULL) {
		deleteTree(T->left, operation);
		deleteTree(T->right, operation);

		operation->delete(T->key);
		free(T);
	}
	return NULL;
}

/**
 *
 */
Tree *deleteNode(Tree *T, void *key, struct op *operation) {
	if (T != NULL) {
		if (operation->compare(T->key, key) > 0) {
			T->left = deleteNode(T->left, key, operation);
		} else if (operation->compare(T->key, key) < 0) {
			T->right = deleteNode(T->right, key, operation);
		} else {
			T = freeNode(T, operation);
		}
	} else {
		printf("Element \"");
		operation->print(key);
		printf("\" not found.\n");
	}
	return T;
}

/**
 *
 */
Tree *freeNode(Tree *T, struct op *operation) {
	Tree *temp = NULL;
	operation->delete(T->key);

	if ((T->left == NULL) || (T->right == NULL)) {
		temp = T;
		if (T->left) {
			T = T->left;
		} else {
			T = T->right;
		}
	} else {
		temp = extractMinimum(T->right, T);
		T->key = temp->key;
	}

	free(temp);
	return T;
}

/**
 *
 */
Tree *extractMinimum(Tree *T, Tree *P) {
	if (T->left) {
		T = extractMinimum(T->left, T);
	} else {
		if (P->right == T) {
			P->right = T->right;
		} else {
			P->left = T->right;
		}
	}
	return T;
}

/**
 *
 */
int countNodes(Tree *T) {
	if (T == NULL) {
		return 0;
	} else {
		return 1 + countNodes(T->left) + countNodes(T->right);
	}
}

/**
 *
 */
Tree *insertMultipleElements(Tree *T, struct op *operation, int n) {
	int i;
	void *key = NULL;
	printf("Insert inputs:\n");
	for (i = 0; i < n; i++) {
		printf("[%d]: ", i + 1);
		key = operation->getInput();
		T = insertNode(T, key, operation);
	}
	return T;
}

/**
 * Use srand() function to obtain different input.
 */
Tree *insertRandomElements(Tree *T, struct op *operation, int n) {
	int i;
	void *key = NULL;
	for (i = 0; i < n; i++) {
		key = operation->getRandom();
		T = insertNode(T, key, operation);
	}
	return T;
}

void **treeToArray(Tree *T, struct op *operation) {

	void **array = NULL;
	int dim = countNodes(T);

	if (dim > 0) {
		array = (void **) malloc(sizeof(void *) * dim);
		if (array != NULL) {

			addToArray(T, array, 0, operation);
		}
	}
	return array;
}

/**
 *
 */
int addToArray(Tree *T, void **arr, int i, struct op *operation) {
	/* Add each nodes through an inOrder visit. */
	if (T == NULL) {
		return i;
	}

	if (T->left != NULL) {
		i = addToArray(T->left, arr, i, operation);
	}

	//arr[i++] = T->key;
	arr[i++] = operation->copy(T->key);

	if (T->right != NULL) {
		i = addToArray(T->right, arr, i, operation);
	}
	return i;
}

