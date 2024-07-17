#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];

    printf("Enter a word or phrase: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }

    printf("in caps:\n%s", str);

    return 0;
}
