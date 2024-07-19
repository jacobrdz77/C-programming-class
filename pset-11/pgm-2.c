#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    double x;
    double y;
} Point;

float calculateDistance(const Point p[], const int count);

int main()
{
    srand(time(NULL));
    Point points[5];

    for (int i = 0; i < 5; i++)
    {
        points[i].x = 1.0 + ((double)rand() / RAND_MAX) * 9;
        points[i].y = 1.0 + ((double)rand() / RAND_MAX) * 9;
    }

    float totalDistance = calculateDistance(points, 5);
    printf("Total distance: %f", totalDistance);

    return 0;
}

float calculateDistance(const Point p[], const int count)
{

    for (int i = 0; i < count; i++)
    {
        printf("point %d:(%2.2f, %2.2f)\n", i, p[i].x, p[i].y);
    }

    float totalDistance = 0;

    for (int i = 0; i < count - 1; i++)
    {
        totalDistance += sqrt(pow((p[i + 1].x - p[i].x), 2) + pow((p[i + 1].y - p[i].y), 2));
        printf("\tdist: (%2.2f, %2.2f)-->(%2.2f, %2.2f) : ", p[i + 1].x, p[i].x, p[i + 1].y, p[i].y);
        printf("%.3f\n", totalDistance);
    }

    return totalDistance;
}