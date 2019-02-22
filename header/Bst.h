#ifndef HEADER_BST_H_
#define HEADER_BST_H_

#include "../header/Strings.h"
#include "../header/Integer.h"

struct tree {
	void *key;
	struct tree *right;
	struct tree *left;
};

/**
 * Operations available for the "void *key" of a tree.
 */
struct op {

	void (*print)(void *key);
	int (*compare)(void *a, void *b);
	void (*delete)(void *key);
	void *(*getInput)(void);
};

typedef enum {
	integer, strings
} op_type;

struct tree * insertMultipleElements(struct tree *T, struct op *operation,
		int n);
struct op *initOperations(op_type type);
struct tree *newNode(void *key);
struct tree *insert(struct tree *T, void *key, struct op *operation);
void inOrder(struct tree *T, struct op *operation);
struct tree *deleteAll(struct tree *T, struct op *operation);
void deleteNode(struct tree *T, struct op *operation);

#endif /* HEADER_BST_H_ */
