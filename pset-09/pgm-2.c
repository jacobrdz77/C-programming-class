#include <stdio.h>
#include <string.h>

void pluralizeStr(char noun[])
{
    int length = strlen(noun);
    if (noun[length - 1] == 'y')
    {
        noun[length - 1] = 'i';
        strcat(noun, "es");
    }
    else if (noun[length - 1] == 's' || noun[length - 1] == 'x' || (noun[length - 2] == 'c' && noun[length - 1] == 'h') || (noun[length - 2] == 's' && noun[length - 1] == 'h'))
    {
        strcat(noun, "es");
    }
    else
    {
        strcat(noun, "s");
    }
}

int main()
{
    char nouns[][20] = {
        "chair",
        "dairy",
        "box",
        "circus",
        "fly",
        "dog",
        "church",
        "mass",
        "marsh",
        "path"};
    int numNouns = sizeof(nouns) / sizeof(nouns[0]);

    for (int i = 0; i < numNouns; i++)
    {
        char plural[30];
        strcpy(plural, nouns[i]);
        pluralizeStr(plural);
        printf("singular: %10s -- plural: %10s\n", nouns[i], plural);
    }

    return 0;
}