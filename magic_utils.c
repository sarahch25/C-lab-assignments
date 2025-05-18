#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "magic_utils.h"

/**
 * @brief Terminates program with error message
 * @param message Error message to display
 */
void exitWithError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

/**
 * @brief Displays program instructions and usage
 */
void printWelcomeMessage(void) {
    printf("\nMagic Square Checker (%dx%d)\n", N, N);
    printf("---------------------------\n");
    printf("Enter %d integers between %d and %d.\n", 
           N * N, MIN_VALUE, MAX_VALUE);
    printf("Note: Duplicate numbers are allowed.\n");
    printf("Separate numbers with spaces/tabs/newlines.\n");
    printf("Input options:\n");
    printf("- Type directly (end with Ctrl+D/Ctrl+Z)\n");
    printf("- Or specify input file as argument\n\n");
}

/**
 * @brief Prints formatted NxN matrix
 * @param matrix The NxN matrix to print
 */
void printMatrix(int matrix[N][N]) {
    int i, j;
    /* Print matrix with fixed-width formatting */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]); /* 3-digit spacing */
        }
        printf("\n"); /* Newline after each row */
    }
}

/**
 * @brief Reads and validates input numbers
 * @param matrix Destination matrix for numbers
 * @param file Input file stream (stdin or file)
 * @note Validates: number format, value range, count
 */
void readAndValidateInput(int matrix[N][N], FILE *file) {
    char line[MAX_LINE_LENGTH];
    int count = 0;
    char *token, *endptr;
    long value;

    /* Read until matrix filled or EOF */
    while (count < N*N && fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, " \t\r\n"); /* Tokenize by whitespace */
        while (token != NULL && count < N*N) {
            /* Skip empty tokens */
            if (strlen(token) == 0) {
                token = strtok(NULL, " \t\r\n");
                continue;
            }

            /* Convert to number with validation */
            value = strtol(token, &endptr, 10);

            /* Check for non-numeric characters */
            if (*endptr != '\0' && !isspace(*endptr)) {
                exitWithError("Invalid input - non-numeric characters found");
            }

            /* Validate number range */
            if (value < MIN_VALUE || value > MAX_VALUE) {
                fprintf(stderr, "Invalid value: %ld (must be %d-%d)\n", 
                        value, MIN_VALUE, MAX_VALUE);
                exitWithError("Value out of range");
            }

            /* Store in matrix (row-major order) */
            matrix[count / N][count % N] = (int)value;
            count++;

            token = strtok(NULL, " \t\r\n"); /* Next token */
        }
    }

    /* Verify complete matrix */
    if (count < N * N) {
        fprintf(stderr, "Error: Expected %d numbers, but only got %d\n", N * N, count);
        exitWithError("Insufficient numbers provided");
    }
}

/**
 * @brief Calculates magic square target sum
 * @return Magic constant value
 * @note Formula: N*(N²+1)/2
 */
int calculateMagicConstant(void) {
    return N * (N * N + 1) / 2;
}

/**
 * @brief Validates magic square properties
 * @param matrix The NxN matrix to check
 * @return 1 if magic square, 0 otherwise
 * @note Checks: all rows, columns, and diagonals sum to magic constant
 */
int isMagicSquare(int matrix[N][N]) {
    int targetSum = calculateMagicConstant();
    int diag1 = 0, diag2 = 0; /* Diagonal sums */
    int i, j;

    /* Check each row and column */
    for (i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        
        for (j = 0; j < N; j++) {
            rowSum += matrix[i][j]; /* Sum current row */
            colSum += matrix[j][i]; /* Sum current column */
        }
        
        /* Early exit if any row/column fails */
        if (rowSum != targetSum || colSum != targetSum) {
            return 0;
        }
        
        /* Sum main and anti-diagonals */
        diag1 += matrix[i][i];
        diag2 += matrix[i][N - 1 - i];
    }

    /* Verify both diagonals */
    return diag1 == targetSum && diag2 == targetSum;
}
