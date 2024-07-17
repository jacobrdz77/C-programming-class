#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(const char phrase[], const size_t length);

int main()
{
    char input[100];
    printf("Enter a phrase: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input, strlen(input)))
    {
        printf("isPalindrome? YES -- %s\n", input);
    }
    else
    {
        printf("isPalindrome? NO -- %s\n", input);
    }

    return 0;
}

bool isPalindrome(const char phrase[], const size_t length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        while (!isalnum(phrase[start]))
        {
            start++;
        }
        while (!isalnum(phrase[end]))
        {
            end--;
        }

        char charOne = tolower(phrase[start]);
        char charTwo = tolower(phrase[end]);

        if (charOne != charTwo)
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}
