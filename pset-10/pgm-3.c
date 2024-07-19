#include <stdio.h>
#include <math.h>
#include <float.h>

long long fibonacci(const int seq);
void calculatGoldenRatio(double *const phi, int *const N);

int main()
{
    int iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);
    double goldenRatio;

    calculatGoldenRatio(&goldenRatio, &iterations);

    return 0;
}

long long fibonacci(const int seq)
{
    // Must be recursive
    if (seq == 0)
    {
        return 0;
    }
    if (seq == 1)
    {
        return 1;
    }

    return fibonacci(seq - 1) + fibonacci(seq - 2);
}
void calculatGoldenRatio(double *const phi, int *const N)
{
    double prevRatio = 0.0;
    long long numerator = 0;
    long long denominator = 0;

    for (int i = 1; i <= *N; i++)
    {
        // N + 1
        numerator = fibonacci(i + 1);
        denominator = fibonacci(i);

        // N
        *phi = (double)numerator / (double)denominator;

        if (fabs(*phi - prevRatio) < DBL_EPSILON)
        {
            printf("The golden ratio has converged after %d iterations.\n", *phi, i);
            break;
        }

        printf("fib(%02d)=%10lld    fib(%02d)=%10lld \t    ratio:%.10f\n", i + 1, numerator, i, denominator, *phi);
        prevRatio = *phi;
    }

    printf("\nGolden ratio computed as: %.10f after %d iterations", *phi, *N);
}