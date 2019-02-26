#ifndef HEADER_OPERATIONS_H_
#define HEADER_OPERATIONS_H_

#include "../header/Strings.h"
#include "../header/Integer.h"

struct op {
	void (*print)(void *key);
	int (*compare)(void *a, void *b);
	void *(*copy)(void *from);
	void (*delete)(void *key);
	void *(*getInput)(void);
	void *(*getRandom)(void);
};

typedef enum {
	integer, strings
} op_type;


struct op *initOperations(op_type type);

void freeOperations(struct op *operation);


#endif /* HEADER_OPERATIONS_H_ */
