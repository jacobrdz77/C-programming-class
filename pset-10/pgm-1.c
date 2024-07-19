#include <stdio.h>
void Hanoi(int n, char source, char destination, char intermediate, int *step);

int main()
{
    printf("How many disks? ");
    int disks;
    scanf("%d", &disks);
    int step = 1;
    Hanoi(disks, 'A', 'C', 'B', &step);
    return 0;
}

void Hanoi(int n, char source, char destination, char intermediate, int *step)
{
    if (n == 0)
        return;

    Hanoi(n - 1, source, intermediate, destination, step);
    printf("Step %02d Move disk %d from peg %c to peg %c\n", (*step)++, n, source, destination);
    Hanoi(n - 1, intermediate, destination, source, step);
}