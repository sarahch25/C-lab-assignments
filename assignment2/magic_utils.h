#ifndef MAGIC_UTILS_H
#define MAGIC_UTILS_H

/* Configuration Constants */
#define N 5                /* Dimension of magic square (N x N) - can change this to test other sizes*/
#define MAX_LINE_LENGTH 1000  /* Maximum input line */
#define MIN_VALUE 1        /* Minimum allowed value in square */
#define MAX_VALUE (N * N)  /* Maximum allowed value in square */

/* Standard I/O inclusion for FILE type */
#include <stdio.h>

/* Function Declarations */

/* Terminates program with error message */
void exitWithError(const char *message);

/* Displays program instructions and usage */
void printWelcomeMessage(void);

/* Prints formatted NxN matrix to stdout */
void printMatrix(int matrix[N][N]);

/* Reads and validates input from specified file stream */
void readAndValidateInput(int matrix[N][N], FILE *file);

/* Calculates the target sum for rows/columns/diagonals */
int calculateMagicConstant(void);

/* Verifies if matrix meets all magic square conditions */
int isMagicSquare(int matrix[N][N]);

#endif /* MAGIC_UTILS_H */