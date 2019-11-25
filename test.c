#include <stdbool.h>
#include <stdlib.h>

char shiftFunc(char newChar, bool isUpper)
{
    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    const int shift = 32;

    int index = 0;

    //get char index in alphabet
    for (int i = 0; i < 25; i++)
    {
        //switch to uppercase for test
        char currentUp = alphabet[i];
        currentUp ^= 32;

        if (newChar == alphabet[i] || newChar == currentUp)
        {
            index = i;
            break;
        }
    }

    if (index + 13 > 25)
    {
        //if shift is longer than alphabet - start from the start again
        newChar = alphabet[index + 13 - 26];
    }
    else
    {
        newChar = alphabet[index + 13];
    }

    //if original letter is upper case
    //- convert new letter to upper
    if (isUpper)
    {
        newChar = newChar & ~shift;
    }

    //printf("Before return: %c\n", newChar);
    return newChar;
}

char* RotThirteen(char* input)
{
    char* returnString = malloc(sizeof(char) * 50);

    int i = 0;
    while (i <= 29)
    {
        //alphibet check
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            //if lower case
            returnString[i] = shiftFunc(input[i], false);
            i++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            //if upper case
            returnString[i] = shiftFunc(input[i], true);
            i++;
        }
        else if (input[i] >= '0' || input[i] <= '9')
        {
            //if number - leave in place
            returnString[i] = input[i];
            i++;
        }
        else
        {
            //special charactor - leave in place
            returnString[i] = input[i];
            i++;
        }
    }
    return returnString;
}

int main(void)
{
    char* input = "Hello world";
    input = RotThirteen(input);
    printf("Output1: %s\n", input);

    input = "Goodbye World";
    input = RotThirteen(input);
    printf("Output2: %s\n", input);

    input = "";
    input = RotThirteen(input);
    printf("Output3: %s\n", input);
}
