// Dynamic String Copy Implementation
#include <stdio.h>
#include <stdlib.h>

int StringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

char *StringCopy(const char *source)
{
    if (source == NULL)
    {
        printf("Error: NULL source pointer\n");
        return NULL;
    }

    int length = StringLength(source);

    // Allocate memory for destination (+1 for null terminator)
    char *destination = (char *)malloc((length + 1) * sizeof(char));

    if (destination == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    int i;
    for (i = 0; i <= length; i++)
    {
        destination[i] = source[i];
    }

    return destination;
}

int main()
{
    printf("=== Dynamic String Copy Demo ===\n\n");

    // Test Case 1: Short string
    const char *str1 = "Hello";
    char *copy1 = StringCopy(str1);
    if (copy1 != NULL)
    {
        printf("Test 1 - Short String:\n");
        printf("  Original: \"%s\" (Address: %p)\n", str1, (void *)str1);
        printf("  Copy:     \"%s\" (Address: %p)\n", copy1, (void *)copy1);
        printf("  Memory allocated: %d bytes\n\n", StringLength(copy1) + 1);
        free(copy1); // Free allocated memory
    }

    // Test Case 2: Longer string
    const char *str2 = "Dynamic Memory Allocation in C Programming";
    char *copy2 = StringCopy(str2);
    if (copy2 != NULL)
    {
        printf("Test 2 - Longer String:\n");
        printf("  Original: \"%s\"\n", str2);
        printf("  Copy:     \"%s\"\n", copy2);
        printf("  Length: %d characters\n\n", StringLength(copy2));
        free(copy2); // Free allocated memory
    }

    // Test Case 3: Empty string
    const char *str3 = "";
    char *copy3 = StringCopy(str3);
    if (copy3 != NULL)
    {
        printf("Test 3 - Empty String:\n");
        printf("  Original: \"%s\" (length: 0)\n", str3);
        printf("  Copy:     \"%s\" (length: 0)\n", copy3);
        printf("  Memory allocated: 1 byte (null terminator)\n\n");
        free(copy3); // Free allocated memory
    }

    // Test Case 4: String with special characters
    const char *str4 = "Hello, World! 123 @#$%";
    char *copy4 = StringCopy(str4);
    if (copy4 != NULL)
    {
        printf("Test 4 - Special Characters:\n");
        printf("  Original: \"%s\"\n", str4);
        printf("  Copy:     \"%s\"\n\n", copy4);
        free(copy4); // Free allocated memory
    }

    // Test Case 5: NULL pointer handling
    printf("Test 5 - NULL Pointer:\n");
    char *copy5 = StringCopy(NULL);
    printf("  Result: %s\n\n", copy5 == NULL ? "NULL (handled correctly)" : "Unexpected");

    // Demonstration of memory efficiency
    printf("=== Memory Efficiency Demo ===\n");
    const char *efficient = "C";
    char *copy_efficient = StringCopy(efficient);
    if (copy_efficient != NULL)
    {
        printf("For a 1-character string:\n");
        printf("  Only 2 bytes allocated (1 char + null terminator)\n");
        printf("  String: \"%s\"\n", copy_efficient);
        free(copy_efficient);
    }

    printf("\n=== All allocated memory has been freed ===\n");
    printf("No memory leaks!\n");

    return 0;
}
