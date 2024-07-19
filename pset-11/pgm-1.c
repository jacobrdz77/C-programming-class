#include <stdio.h>
#include <string.h>

typedef struct
{
    int number;
    char name[15];
    char symbol[4];
    char class[50];
    double weight;
    int shells[7];

} Element_t;

void scan_element(Element_t *const element);
void print_element(const Element_t *const element);
int main()
{
    Element_t userElement;
    scan_element(&userElement);
    print_element(&userElement);
}

void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void scan_element(Element_t *const userElement)
{
    printf("Enter atomic #: ");
    scanf("%d", &userElement->number);
    getchar();

    printf("        name: ");
    fgets(userElement->name, sizeof(userElement->name), stdin);
    remove_newline(userElement->name);

    printf("        symbol: ");
    fgets(userElement->symbol, sizeof(userElement->name), stdin);
    remove_newline(userElement->symbol);

    printf("        class: ");
    fgets(userElement->class, sizeof(userElement->name), stdin);
    remove_newline(userElement->class);

    printf("         weight: ");
    scanf("%f", &userElement->weight);

    printf("         shells, enter 7 values: ");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &userElement->shells[i]);
    }
}
void print_element(const Element_t *const userElement)
{
    printf("Output:\n");
    printf("#%d %s\n", userElement->number, userElement->name);
    printf("  wt: %.2f, symbol: %s, class:%s\n", userElement->weight, userElement->symbol, userElement->class);
    printf("  shells: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d", userElement->shells[i]);
    }
    printf("\n");
}
