#include <stdio.h>
#include <stdlib.h>

// Efficient integer square root using bit manipulation
unsigned long isqrt(unsigned long x)
{
    register unsigned long op, res, one;
    op = x;
    res = 0;
    /* "one" starts at the highest power of four <= the argument. */
    one = 1 << 30; /* Adjust bit shift for 32-bit or 64-bit as needed */
    while (one > op)
        one >>= 2;
    while (one != 0)
    {
        if (op >= res + one)
        {
            op -= res + one;
            res += one << 1; // Faster than 2 * one
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

// Function to check if a number is prime based on factorization idea
int is_prime(unsigned long n)
{
    // Special cases
    if (n == 1)
    {
        printf("1 is prime!\n");
        return 1;
    }
    if (n == 2 || n == 3)
    {
        return 1; // 2 and 3 are prime numbers
    }
    if (n % 2 == 0)
    {
        printf("%lu is even!\n", n);
        return 0;
    }

    // Start searching for factors
    unsigned long k = isqrt(n);
    unsigned long a, b;

    // Initialize a and b
    if (k % 2 != 0)
    {
        a = k;
        b = k;
    }
    else
    {
        a = k - 1;
        b = k + 1;
    }

    // Factor search loop
    while (a > 1)
    {
        if (a * b == n)
        {
            printf("%lu = %lu x %lu\n", n, a, b);
            return 0; // Found factors, so not prime
        }
        else if (a * b < n)
        {
            b += 2; // Increase b by 2 to check next odd number
        }
        else if (a * b > n)
        {
            a -= 2; // Decrease a by 2 to check smaller odd number
        }
    }

    // If no factors are found, the number is prime
    printf("%lu is prime\n", n);
    return 1;
}

int main()
{
    unsigned long n;
    printf("Enter a number: ");
    scanf("%lu", &n);

    // Check if the number is prime
    is_prime(n);

    return 0;
}