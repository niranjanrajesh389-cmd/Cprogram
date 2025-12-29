#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50];
    int result;

    printf("Enter first string: ");
    scanf(" %[^\n]",str1);

    printf("Enter second string: ");
     scanf(" %[^\n]",str2);


    result = strcmp(str1, str2);

    if(result == 0)
        printf("Both strings are equal");
    else
        printf("Strings are not equal");

    return 0;
}