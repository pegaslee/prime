## Primality Testing Approach

This project implements a primality testing algorithm that determines if a number is prime by searching for two odd factors, \( a \) and \( b \), such that \( a \times b = n \). If no such factors are found, the number is determined to be prime.

### How It Works

1. The algorithm first checks for simple cases, such as:
   - If the number is 1 (which is considered prime in this implementation).
   - If the number is even or divisible by small primes (e.g., 2 and 3).
   
2. It calculates the integer square root of the number (`isqrt`), which serves as the largest possible candidate for one of the factors.

3. A trial-and-error search is performed where the values of \( a \) and \( b \) are adjusted:
   - \( b \) is incremented, and \( a \) is decremented, keeping both values odd.
   - If a pair \( a \times b = n \) is found, the number is composite. If no such pair exists, the number is prime.

4. The algorithm uses bitwise operations to efficiently compute the integer square root, reducing the search space for potential factors.

### Characteristics

- **Deterministic:** The algorithm provides a definite result for whether a number is prime.
- **Optimized:** It skips even numbers and unnecessary computations to improve efficiency.
- **Best Suited For:** Small to medium-sized numbers where simplicity and clarity are prioritized.

This method is simple and easy to understand, making it a good educational tool and a functional solution for primality testing in less performance-critical scenarios.