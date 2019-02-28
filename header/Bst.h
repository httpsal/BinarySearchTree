#ifndef HEADER_BST_H_
#define HEADER_BST_H_

#include "Operations.h"

typedef struct tree {
	void *key;
	struct tree *right;
	struct tree *left;
} Tree;


/**
 * New node
 */
Tree *newNode(void *key);
Tree *insertNode(Tree *T, void *key, struct op *operation);

/**
 * Tree visit
 */
void inOrder(Tree *T, struct op *operation);
void postOrder(Tree *T, struct op *operation);
void preOrder(Tree *T, struct op *operation);

/**
 * Delete node/tree
 */
Tree *deleteTree(Tree *T, struct op *operation);

Tree *deleteNode(Tree *T, void *key, struct op *operation);
Tree *freeNode(Tree *T, struct op *operation);
Tree *extractMinimum(Tree *T, Tree *P);

/**
 * Various
 */
int countNodes(Tree *T);

Tree *insertMultipleElements(Tree *T, struct op *operation, int n);

Tree *insertRandomElements(Tree *T, struct op *operation, int n);

/**
 * Tree to array
 */
void **treeToArray(Tree *T, struct op *operation, int dim);
int addToArray(Tree *T, void **arr, int i, struct op *operation);

/**
 * Balanced Tree
 */
Tree *buildBalancedTree(void **arr, int start, int end);
Tree *balancedTree(Tree *T, struct op *operation);

#endif /* HEADER_BST_H_ */
