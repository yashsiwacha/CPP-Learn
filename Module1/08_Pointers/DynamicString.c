// Dynamic string copy with memory allocation
#include <stdio.h>
#include <stdlib.h>

int StringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

char *StringCopy(const char *source)
{
    if (source == NULL)
    {
        printf("Error: NULL source\n");
        return NULL;
    }

    int length = StringLength(source);
    char *destination = (char *)malloc((length + 1) * sizeof(char));

    if (destination == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i <= length; i++)
        destination[i] = source[i];

    return destination;
}

int main()
{
    const char *str1 = "Hello";
    char *copy1 = StringCopy(str1);
    if (copy1 != NULL)
    {
        printf("Original: \"%s\"\n", str1);
        printf("Copy: \"%s\"\n\n", copy1);
        free(copy1);
    }

    const char *str2 = "Dynamic Memory Allocation";
    char *copy2 = StringCopy(str2);
    if (copy2 != NULL)
    {
        printf("Copied: \"%s\"\n\n", copy2);
        free(copy2);
    }

    char *copy3 = StringCopy(NULL);
    printf("NULL test: %s\n", copy3 == NULL ? "Pass" : "Fail");

    return 0;
}
