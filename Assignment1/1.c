#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char str[], int length) // checks if the given string is a valid identifier
{

    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))

        return false; // checks if the first character is valid

    int i;

    for (i = 1; i < length; i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))

            return false; // checks if the rest of the characters are valid
    }

    return true; // if all the characters are valid then returns true
}

int main()
{
    char str[31];
    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    if (isValid(str, length))
        printf("The string is a valid identifier\n");
    else
        printf("The string is not a valid identifier\n");

    return 0;
}
