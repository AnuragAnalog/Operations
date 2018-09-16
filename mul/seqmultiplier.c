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
int fulladd(int x, int y, int z, int result[], int ind);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    int        i = 0, len1, len2;
    int        c[MAXC], a[MAX], q[MAX], m[MAX];
    char       *str1, *str2;

    if (argc != 3)
    {
       fprintf(stderr, "Usage: %s <Multiplicand> <Multiplier>.\n", argv[0]);
       exit(1);
    }

    str1 = argv[1];
    str2 = argv[2];

    len1 = strlen(str1);
    len2 = strlen(str2);

    while (*str1 != '\0')
    {
       m[i] = (int)(*str1 - '0');
       i++;
       str1++;
    }

    i = 0;
    while (*str2 != '\0')
    {
       q[i] = (int)(*str2 - '0');
       i++;
       str2++;
    }

    seqmultiply(c, a, m, q, len1, len2);
    exit(0);
}

void seqmultiply(int c[], int a[], int  m[], int q[], int len1, int len2)
{
   int        i;

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
      printf("1");
   }
   for (i = len1-1; i >= 0; i--)
   {
      printf("%d", a[i]);
   }
   for (i = len2-1; i >= 0; i--)
   {
      printf("%d", q[i]);
   }
   printf(" is the resultant value.\n");

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
