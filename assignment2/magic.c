#include <stdio.h>
#include "magic_utils.h"

/* Main program entry point */
int main(int argc, char *argv[]) {
    int matrix[N][N];       /* NxN matrix storage */
    FILE *input = stdin;    /* Default to standard input */

    /* Handle command line arguments */
    if (argc == 2) {
        /* Try opening specified file */
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Failed to open file: %s\n", argv[1]);
            return 1;  /* Return error code for file open failure */
        }
    } 
    else if (argc > 2) {
        exitWithError("Too many arguments - specify only one input file");
    }

    /* Display program instructions */
    printWelcomeMessage();
    
    /* Process input (either from file or stdin) */
    readAndValidateInput(matrix, input);
    
    /* Display the entered matrix */
    printMatrix(matrix);

    /* Verify and report magic square status */
    if (isMagicSquare(matrix)) {
        printf("\nThis is a valid magic square (sum = %d)\n", 
               calculateMagicConstant());
    } 
    else {
        printf("\nThis is NOT a magic square\n");
    }

    /* Cleanup - close file if not stdin */
    if (input != stdin) {
        fclose(input);
    }

    return 0;  /* Successful execution */
}