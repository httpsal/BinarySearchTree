#include <stdio.h>
#include <stdlib.h>
#include "../header/Bst.h"



int main() {


	struct tree *T = NULL;
	struct op * operation = initOperations(integer);
	void **array;

	int i;

	T = insertMultipleElements(T, operation, 5);
	printf("InOrder 1  \n");
	inOrder(T, operation);
	printf("\n");
	//T = deleteNode(T, "cane", operation);
	printf("Numero nodi = %d\n", countNodes(T));

	//printf("InOrder 2  \n");
	//inOrder(T, operation);
	printf("\n");


	array = treeToArray(T, operation);

	for (i = 0; i < 5; i++) {
		operation->print(array[i]);
		printf(" ");
	}

	T = deleteTree(T, operation);
	for (i = 0; i < 5; i++) {
		operation->print(array[i]);
		printf(" ");
	}
	freeOperations(operation);
	printf("\n");
	system("pause");
	return 0;
}
