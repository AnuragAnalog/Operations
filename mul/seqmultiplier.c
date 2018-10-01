#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAXC         1
#define MAX          32

/********* FUNCTION DECLARATION *********/
void seqmultiply(int c[], int a[], int  m[], int q[], int len1, int len2);
void reverse(int str[], int nitems);
void shr(int c[], int a[], int q[], int len1, int len2);
void ripple(int a[], int m[], int c[], int len1);
void bitoi(int str[], int ind);
int pow2(int ind);
int itobi(int num, int str[]);
int fulladd(int x, int y, int z, int result[], int ind);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        len1, len2, num1, num2;
   int        c[MAXC], a[MAX], q[MAX], m[MAX];

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <Multiplicand> <Multiplier>.\n", argv[0]);
      exit(1);
   }

   num1 = atoi(argv[1]);
   num2 = atoi(argv[2]);

   if (num1 < 0 || num2 < 0)
   {
      fprintf(stderr, "It's only for unsigned integers.\n");
      exit(2);
   }

   len1 = itobi(num1, m);
   len2 = itobi(num2, q);

   seqmultiply(c, a, m, q, len1, len2);
   exit(0);
}

void seqmultiply(int c[], int a[], int  m[], int q[], int len1, int len2)
{
   int        i, tmp[MAX], k = 0;

   reverse(m, len1);
   reverse(q, len2);

   for (i = 0; i < len1; i++)
   {
      a[i] = 0;
   }
   c[0] = 0;

   i = 0;
   while (i < len2)
   {
      if (q[MAXC-1] == 1 )
      {
         ripple(a, m, c, len1);
      }
      shr(c, a, q, len1, len2);
      i++;
   }

   if (c[0] == 1)
   {
      tmp[k] = 1;
      k++;
   }
   for (i = len1-1; i >= 0; i--)
   {
      tmp[k] = a[i];
      k++;
   }
   for (i = len2-1; i >= 0; i--)
   {
      tmp[k] = q[i];
      k++;
   }

   bitoi(tmp, len1+len2);
   return ;
} 

void reverse(int str[], int nitems)
{
   int       c, i, j;

   for (i = 0, j = nitems - 1; i < j; i++, j--)
   {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
   }
   return ;
}

void shr(int c[], int a[], int q[], int len1, int len2)
{
   int        i;

   for (i = 0; i < len2-1; i++)
   {
      q[i] = q[i+1];
   }
   q[i] = a[0];

   for (i = 0; i < len1-1; i++)
   {
      a[i] = a[i+1];
   }
   a[i] = c[0];
   c[0] = 0;

   return ;
}

void bitoi(int str[], int ind)
{
   int        i = 0, x = 0, num = 0;

   reverse(str, ind);

   while (i < ind)
   {
      if ((str[i] == 0) || (str[i] == 1))
      {
         x = pow2(i);
         num = num + str[i] * x;
      }
      else
      {
         printf("Given string is not a Binary string\n");
         exit(2);
      }
      i++;
   }

   printf("%d is the resultant value.\n", num);
   return ;
}

int pow2(int ind)
{
   int        i, base = 1;

   if (ind == 0)
   {
      return base;
   }
   else
   {
      for (i = 0; i < ind; i++)
      {
         base = base * 2;
      }
      return base;
   }
}

void ripple(int a[], int m[], int c[], int len1)
{
   int        i = 0, x1, x2, carry = 0;

   while (i < len1)
   {
      x1 = a[i];
      x2 = m[i];

      carry = fulladd(x1, x2, carry, a, i);
      i++;
   }

   if (carry == 1)
   {
      c[MAXC-1] = carry;
   }
   else
   {
      i = i - 1;
   }

   return ;
}

int fulladd(int x, int y, int z, int result[], int ind)
{
   int        sum, carry;

   sum = (x ^ y ^ z);
   carry = ((x & y) | (y & z) | (x & z));

   result[ind] = sum;
   return carry;
}

int itobi(int num, int str[])
{
   int        i = 0, rem, bi = 2;

   do
   {
      rem = num % bi;
      if ((rem >= 0) && (rem <= 1))
      {
         str[i++] = rem;
      }
   } while ((num /= bi) > 0);
   reverse(str, i);

   return i;
}
