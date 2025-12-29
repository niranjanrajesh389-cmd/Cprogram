#include <stdio.h>

int main()
{
    char text[50], pattern[20];
    int i, j;

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    printf("Enter pattern: ");
    scanf(" %[^\n]", pattern);

    for (i = 0; text[i] != '\0'; i++)
    {
        for (j = 0; pattern[j] != '\0'; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (pattern[j] == '\0')
        {
            printf("Pattern found at position %d", i + 1);
            return 0;
        }
    }

    printf("Pattern not found");
}