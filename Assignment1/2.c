
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int wordLength;
    char ch;
    FILE *file;

    file = fopen("sample.txt", "r");
    printf("THE CONTENTS OF THE FILE ARE : \n");
    printf("------------------------------------------------------\n");

    while ((ch = getc(file)) != EOF)
    {
        if (file)
        {
            char word[100];
            while (fscanf(file, "%s", word) != EOF) // Reads a single word one at a time from file
            {
                printf("%s\t\t\t", word); // Prints each words on a single line

                wordLength = strlen(word);

                if (isValid(word, wordLength) == false)
                {

                    printf("This is not a valid identifier\n");
                }
                else
                    printf("This is a valid identifier\n");
            }
            fclose(file); // Closes the file
        }
        else
        {
            printf("Some error occured while opening the file");
        }
    }

    return 0;
}
