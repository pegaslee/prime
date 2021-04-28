#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 *  https://web.archive.org/web/20120306040058/http://medialab.freaknet.org/martin/src/sqrt/sqrt.c
 *	Square root by abacus algorithm, Martin Guy @ UKC, June 1985.
 *	From a book on programming abaci by Mr C. Woo.
 *	Argument is a positive integer, as is result.
 *
 *	I have formally proved that on exit:
 *		   2		   2		   2
 *		res  <= x < (res+1)	and	res  + op == x
 *
 *	This is also nine times faster than the library routine (-lm).
 */
unsigned long isqrt(unsigned long x)
{
  register unsigned long op, res, one;
  op = x;
  res = 0;
  /* "one" starts at the highest power of four <= than the argument. */
  one = 1 << 30; /* second-to-top bit set */
  while (one > op)
    one >>= 2;
  while (one != 0)
  {
    if (op >= res + one)
    {
      op -= res + one;
      res += one << 1; // <-- faster than 2 * one
    }
    res >>= 1;
    one >>= 2;
  }
  return res;
}

int main(void)
{

  unsigned long p, k, a, b;

  printf("Enter a positive integer: ");
  scanf("%lu", &p);

  if (p == 1)
  {
    printf("1 is prime!\n");
    return 0;
  }
  if (p % 2 == 0)
  {
    printf("%lu is even!\n", p);
    return 0;
  }

  k = isqrt(p);

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

  while (a > 1)
  {
    if (a * b == p)
    {
      break;
    }
    if (a * b > p)
    {
      a = a - 2;
    }
    else
    {
      b = b + 2;
    }
  }

  if (a * b == p)
    printf("%lu = %lu x %lu\n", p, a, b);
  else if (a == 1)
    printf("%lu is prime!\n", p);
  else
    printf("OOPS!\n");

  return 0;
}
