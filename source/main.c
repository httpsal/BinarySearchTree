#include <stdio.h>
#include <stdlib.h>
#include "../header/Bst.h"

/**
 * Prototype.
 */
void printMenu();
void printMenuOperation();
int selectFunction(Tree **T, struct op *operation);
int selectOperation(struct op **operation);

/**
 * MAIN
 */
int main() {
	Tree *T = NULL;
	struct op * operation = NULL;

	while (selectOperation(&operation) >= 0) {

		printMenu();

		while (selectFunction(&T, operation) >= 0) {
		}
	}
	printf("\nPress any key to continue...\n");
	getchar();
	return 0;
}

/**
 * Print a simple menù for selecting an operation.
 */
void printMenuOperation() {
	printf("\n=========== Select Operation ===========\n"
			" [0] Integer\n"
			" [1] Floating point\n"
			" [2] String\n"
			" [3] Exit\n"
			"========================================\n");
}

/**
 * Get the user's input and make a new struct of operations.
 */
int selectOperation(struct op **operation) {
	int choose = 0;
	printMenuOperation();

	do {
		printf("\n> ");
		scanf("%d", &choose);
		fflush(stdin);
	} while (choose < 0 || choose > 3);

	freeOperations(*operation);

	switch (choose) {
		case 0:
			*operation = initOperations(integer);
			break;
		case 1:
			*operation = initOperations(floating);
			break;
		case 2:
		default:
			*operation = initOperations(strings);
			break;
		case 3:
			choose = -1;
			break;
	}

	return choose;
}

/**
 * Print a simple menù for tree's operations.
 */
void printMenu() {
	printf("\n================= Menu =================\n"
			" [0] Insert new items\n"
			" [1] Insert random items\n"
			" [2] Delete item\n"
			" [3] Delete tree\n"
			" [4] InOrder visit\n"
			" [5] PreOrder visit\n"
			" [6] PostOrder visit\n"
			" [7] Count tree's nodes\n"
			" [8] Balance the tree\n"
			" [9] Print menu'\n"
			" [10] Exit\n"
			"(0 - 10) to select the operation.\n"
			"========================================\n");
}

/**
 * Get the user's input and select the right operation.
 */
int selectFunction(Tree **T, struct op *operation) {
	int choose = 0, *n;
	Tree *newTree = NULL;
	void *keyToDelete = NULL;

	do {
		printf("\n[9 menu']> ");
		scanf("%d", &choose);
		fflush(stdin);
	} while (choose < 0 || choose > 10);

	printf("\n");

	switch (choose) {
		case 0:
			printf("How many items ?\n> ");
			n = getInt();
			*T = insertMultipleElements(*T, operation, *n);
			free(n);
			break;
		case 1:
			printf("How many items ?\n> ");
			n = getInt();
			*T = insertRandomElements(*T, operation, *n);
			free(n);
			break;
		case 2:
			printf("Insert the key you want to delete:\n> ");
			keyToDelete = operation->getInput();
			*T = deleteNode(*T, keyToDelete, operation);
			free(keyToDelete);
			break;
		case 3:
			printf("Deleting tree...\n");
			*T = deleteTree(*T, operation);
			printf("Tree deleted.\n");
			break;
		case 4:
			printf("InOrder: ");
			inOrder(*T, operation);
			printf("\n");
			break;
		case 5:
			printf("PreOrder: ");
			preOrder(*T, operation);
			printf("\n");
			break;
		case 6:
			printf("PostOrder: ");
			postOrder(*T, operation);
			printf("\n");
			break;
		case 7:
			printf("Nodes inside the tree: %d\n", countNodes(*T));
			break;
		case 8:
			newTree = balancedTree(*T, operation);
			if (newTree != NULL) {
				*T = deleteTree(*T, operation);
				*T = newTree;
				newTree = NULL;
			} else {
				printf("The tree has not been balanced.\n");
			}
			break;
		case 9:
			printMenu();
			break;
		case 10:
		default:
			printf("Exiting...\n");
			*T = deleteTree(*T, operation);
			choose = -1;
			break;
	}

	return choose;
}







