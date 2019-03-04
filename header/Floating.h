#ifndef HEADER_FLOATING_H_
#define HEADER_FLOATING_H_
#define PRECISION 4
#define SIZE 256


int compareFloat(void *a, void *b);

float newPrecision(float number, float decimal);

void printFloat(void *key);

void *getFloat(void);

void *getRandomFloat(void);

void deleteFloat(void *key);

void *copyFloat(void *from);

int isEvenFloat(void *key);

#endif /* HEADER_FLOATING_H_ */
