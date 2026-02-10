#include <stdio.h>
#include <stdlib.h> // Add this for malloc and free

int main()
{
    int *ptr = (int *)malloc(5 * sizeof(int));
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i + 1; // Initialize the array with values 1 to 5
    }
    printf("Value at ptr: %d\n", ptr[0]);
    for (int i = 0; i < 5; i++)
    {
        printf("Value at ptr[%d]: %d\n", i, ptr[i]); // Output: 1, 2, 3, 4, 5
    }
    free(ptr); // Free the allocated memory
    // ptr = NULL; // Set to NULL after freeing to prevent double free
    free(ptr); // Now safe (freeing NULL is well-defined as no-op)
    return 0;
}