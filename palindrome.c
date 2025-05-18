#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* 
 * Function to check if a string is a palindrome
 * 
 * This function compares characters from both ends of the string, ignoring
 * non-alphanumeric characters, and checks if the string is the same when
 * read forwards and backwards.
 * 
 * Parameters:
 *   s - the string to be checked for palindrome
 * 
 * Returns:
 *   1 if the string is a palindrome, 0 otherwise.
 */
int palindrome(char s[]) {
    int left = 0, right = strlen(s) - 1;  /* Initialize pointers to the start and end of the string */

    /* Loop through the string while the left pointer is less than the right pointer */
    while (left < right) {
        
        /* Skip non-alphanumeric characters from the left side */
        while (left < right && !isalnum(s[left])) left++;
        
        /* Skip non-alphanumeric characters from the right side */
        while (left < right && !isalnum(s[right])) right--;

        /* Check if characters at the left and right pointers are different */
        if (s[left] != s[right]) return 0;  /* Not a palindrome, return 0 */

        left++;  /* Move the left pointer to the right */
        right--;  /* Move the right pointer to the left */
    }

    return 1;  /* The string is a palindrome, return 1 */
}

int main() {
    char str[81];  /* Declare a string of up to 80 characters (plus null terminator) */

    /* Use fgets to read input from stdin (works with redirection) */
    printf("Enter a string for checking:\n");
    fgets(str, sizeof(str), stdin);  /* Reads a line of input from the user */

    /* Remove the newline character if fgets captures it */
    str[strcspn(str, "\n")] = '\0';  /* Find the newline character and replace it with a null terminator */

    /* Check if the string is a palindrome */
    if (palindrome(str)) {
        printf("This is a palindrome! Good job!\n");
    } else {
        printf("Not a palindrome, nice string though :)\n");
    }

    return 0;  /* Return 0 to indicate the program finished successfully */
}

