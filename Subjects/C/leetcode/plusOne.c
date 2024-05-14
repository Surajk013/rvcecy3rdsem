#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Allocate memory for the return array
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    int carry = 1; // Start with carry as 1
    
    // Traverse the digits array from right to left
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1 ] = sum % 10; // Update the current digit in the result array

        carry = sum / 10; // Update the carry
    }
    
    // If there's still a carry after processing all digits
    if (carry == 1) {
        result[0] = 1; // Set the most significant digit as 1
        *returnSize = digitsSize + 1; // Update the size of the result array
    } else {
        // No carry, copy the result array from the second position
        for (int i = 0; i < digitsSize; i++) {
            result[i] = result[i + 1];
        }
        *returnSize = digitsSize; // Update the size of the result array
    }
    
    return result;
}

int main() {
    // Test cases
    int digits1[] = {1, 2, 3};
    int returnSize;
    int* result1 = plusOne(digits1, 3, &returnSize);
    printf("Output 1: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1); // Free the memory allocated for result1

    int digits2[] = {4, 3, 2, 1};
    int* result2 = plusOne(digits2, 4, &returnSize);
    printf("Output 2: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2); // Free the memory allocated for result2

    int digits3[] = {9};
    int* result3 = plusOne(digits3, 1, &returnSize);
    printf("Output 3: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");
    free(result3); // Free the memory allocated for result3

    return 0;
}
 