#ifndef HEADER_STRINGS_H_
#define HEADER_STRINGS_H_
#define SIZE 256


int compareStrings(void *a, void *b);

void printString(void *key);

void deleteString(void *key);

void *getString(void);

int getStringDimension(char *string);

void *getRandomString(void);

void *copyString(void *from);

#endif /* HEADER_STRINGS_H_ */
