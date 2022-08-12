#include <math.h>
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

int getHashValue(char str[], int length)
{
	int x = 10; // Multiplier
	int i;
	int hashValue = 0;
	int sizeOfHash = 97;

	for(i = 0; i < length; i++)
	{
		int currentValue = (int) x*pow(str[i],i);
		hashValue = (hashValue%sizeOfHash + currentValue%sizeOfHash)%sizeOfHash;
	}

	return hashValue;
}
int main()
{
    int wordLength;
    char ch;
    FILE *file;
	
    char  hashTable[100][100];
    int i;
    bool flag = false;
    
    for (i=0; i < 100; i++)
	strcpy(hashTable[i],"");

    file = fopen("checkIdentifiers.txt", "r");
    printf("THE CONTENTS OF THE FILE ARE : \n");
    printf("------------------------------------------------------\n");

        if (file)
        {
            char word[100];
            while (fscanf(file, "%s", word) != EOF) // Reads a single word one at a time from file
            {
		if(strcmp(word,"%%")==0)
			flag = true;

		if(flag == false)
		{

                printf("%s\t\t\t", word); // Prints each words on a single line

                wordLength = strlen(word);

                if (isValid(word, wordLength) == true)
                    printf("This is a valid identifier\t\t\t");
                else
                    printf("This is not a valid identifier\n");
                
		if (isValid(word, wordLength) == true)
		{
                	int wordHashValue = getHashValue(word,wordLength); // Gets the Hash Value
			strcpy(hashTable[wordHashValue],word);		   // Puts the identifier in the corrent position
			printf("The HASH VALUE of the identifier is : %d\n",wordHashValue);
		}

		}

		else
		{
		        if(strcmp(word,"%%")!=0)
			{

			wordLength = strlen(word);
			int wordHashValue = getHashValue(word,wordLength);
			if(strcmp(hashTable[wordHashValue],word)==0)
			printf("The identifier %s has been delcared previously\n",word);
			else
			printf("The identifier %s has not been declared previously\n",word);
			
			}
		}
            }
            fclose(file); // Closes the file
        }
        else
        {
            printf("Some error occured while opening the file");
        }


    return 0;
}
