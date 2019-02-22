#include <stdio.h>
#include <stdlib.h>
#include "../header/Bst.h"



int main() {


	struct tree *T = NULL;
	struct op * operation = initOperations(strings);




	T = insertMultipleElements(T, operation, 5);


	inOrder(T, operation);

	T = deleteAll(T, operation);
	inOrder(T, operation);

	system("pause");
	return 0;
}
