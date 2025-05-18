#include <stdio.h>

/* 
 * Function that counts the number of bits with value 0
 * 
 * This function takes an unsigned integer 'n' and checks each bit in it,
 * counting how many of them are 0. It uses bitwise operations to inspect 
 * each bit of the number.
 * 
 * Parameters:
 *   n - the unsigned integer whose 0 bits are to be counted
 * 
 * Returns:
 *   The number of bits in 'n' that are 0.
 */
int count_zero_bits(unsigned int n) {
    int count = 0;  /* Initialize the count of zero bits */
    int total_bits = sizeof(unsigned int) * 8;  /* Total number of bits in unsigned int (usually 32 or 64 bits) */
    int i;

    /* Iterate through each bit of the integer */
    for (i = 0; i < total_bits; i++) {
        if ((n & 1) == 0) {  /* Check if the current bit is 0 */
            count++;  /* If the bit is 0, increment the count */
        }
        n >>= 1;  /* Shift the bits of 'n' to the right to check the next bit */
    }

    return count;  /* Return the total count of zero bits */
}

/* 
 * Function that prints the binary representation of a number
 * 
 * This function takes an unsigned integer 'n' and prints its binary 
 * representation, grouping every 4 bits for easier reading.
 * 
 * Parameters:
 *   n - the unsigned integer to be printed in binary
 */
void print_binary(unsigned int n) {
    int total_bits = sizeof(unsigned int) * 8;
    int i;

    printf("Binary representation: ");

    /* Loop through each bit, starting from the most significant bit */
    for (i = total_bits - 1; i >= 0; i--) {
        unsigned int bit_checker = 1 << i;  /* Points to the bit we're checking */
        printf("%d", (n & bit_checker) ? 1 : 0);  /* Print 1 or 0 based on the bit value */

        if (i % 4 == 0) {  /* Add a space every 4 bits for readability */
            printf(" ");
        }
    }

    printf("\n");  /* Print a newline at the end */
}

int main() {
    unsigned int number;
    int zeros;

    /* Prompt the user to enter an unsigned integer */
    printf("Enter an integer: ");
    scanf("%u", &number);  /* Read the input from the user */

    print_binary(number);  /* Print the binary representation of the input number */
    zeros = count_zero_bits(number);  /* Count the number of 0 bits in the number */
    printf("Number of zero bits: %d\n", zeros);  /* Display the result */

    return 0;  /* Return 0 to indicate the program finished successfully */
}

