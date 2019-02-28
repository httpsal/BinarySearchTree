#include <stdio.h>
#include <stdlib.h>
#include "../header/Bst.h"

void printMenu();
int selectFunction(Tree **T, struct op *operation);

int main() {
	Tree *T = NULL;
	struct op * operation = initOperations(integer);

	while (1) {
		printMenu();
		if (selectFunction(&T, operation) < 0) {
			break;
		}
	}

	T = deleteTree(T, operation);
	freeOperations(operation);
	printf("\n");
	system("pause");
	return 0;
}

/**
 *
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
			" [9] Exit\n"
			"(0 - 9) to select the operation.\n"
			"========================================\n\n");
}

/**
 *
 */
int selectFunction(Tree **T, struct op *operation) {
	int choose = 0, *n;
	Tree *newTree = NULL;
	void *keyToDelete = NULL;

	do {
		printf("> ");
		scanf("%d", &choose);
		fflush(stdin);
	} while (choose < 0 || choose > 9);

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
		default:
			printf("Exiting...\n");
			choose = -1;
			break;
	}

	return choose;
}







