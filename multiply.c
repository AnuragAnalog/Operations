#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS ********/
#define MAX        32

/********* FUNCTION DECLARATION *********/
void multiply(int m[], int q[], int len1, int len2);
int ripple(int m[], int a[], int ind);
int fulladd(int x, int y, int z, int a[], int ind);
void reverse(int str[], int len);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        i = 0, len1, len2;
   int        m[MAX], q[MAX];
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
      str1++;
      i++;
   }
   i = 0;

   while (*str2 != '\0')
   {
      q[i] = (int)(*str2 - '0');
      str2++;
      i++;
   }

   multiply(m, q, len1, len2);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void multiply(int m[], int q[], int len1, int len2)
{
   int       i = 0, j = 0, k, l, n = 0, flen;
   int       a[MAX], ac[MAX];
 
   reverse(m, len1);
   reverse(q, len2);

   if (len1 < len2)
   {
      for (j = len1; j < len2; j++)
      {
         m[j] = 0;
      }
      len1 = len2;
   }
   else if (len2 < len1)
   {
      for (j = len2; j < len1; j++)
      {
         q[j] = 0;
      }
      len2 = len1;
   }

   for (j = 0; j < len1+len2; j++)
   {
      a[j] = 0;
   }

   while (i < len2)
   {
      for (j = 0; j < n; j++)
      {
         ac[j] = 0;
      }

      for (k = j,l = 0; k < j+len2; k++,l++)
      {
         ac[k] = m[l];
      }

      if (q[i] == 1)
      {
         flen = ripple(ac, a, k);
      }

      n++;
      i++;
   }

   for (i = flen; i >= 0; i--)
   {
      printf("%d", a[i]);
   }
   printf(" is the resultant value.\n");

   return ;
}

int ripple(int m[], int a[], int ind)
{
   int        i = 0, x1, x2, carry = 0;

   while (i < ind)
   {
      x1 = m[i];
      x2 = a[i];

      carry = fulladd(x1, x2, carry, a, i);
      i++;
   }

   if (carry == 1)
   {
      a[i] = carry;
   }
   else
   {
      i = i - 1;
   }

   return i;
}

int fulladd(int x, int y, int z, int a[], int ind)
{
   int        sum, carry;

   sum = (x ^ y ^ z);
   carry = ((x & y) | (y & z) | (x & z));

   a[ind] = sum;
   return carry;
}

void reverse(int str[], int len)
{
   int       c, i, j;

   for (i = 0, j = (len-1); i < j; i++, j--)
   {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
   }
   return ;
}
