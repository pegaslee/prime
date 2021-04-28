import math

n = int(input())

k = math.isqrt(n)

if k % 2 != 0:
    a = k
    b = k
else:
    a = k - 1
    b = k + 1

while a > 1:
    print(a, b, a * b)
    if a * b == n:
        break
    elif a * b < n:
        b = b + 2
    elif a * b > n:
        a = a - 2

if a == 1:
    print(f"{n} is prime")
else:
    print(f"{n} = {a} x {b}")
