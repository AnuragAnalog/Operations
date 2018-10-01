#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAXC         1
#define MAX          32

/********* FUNCTION DECLARATION *********/
void abooth(int mc[], int a[], int  m[], int q[], int len1, int len2, int sign);
void reverse(int str[], int nitems);
void shrb(int a[], int q[], int len1, int len2);
int pow2(int ind);
void comp2(int m[], int mc[], int len1);
void ripple(int a[], int m[], int len1);
int radix4(int q[], int len2);
void bitosi(int str[], int ind);
void bitoi(int str[], int ind);
int uitobi(int num, int str[]);
void printarray(int array[], int nitems);
int fulladd(int x, int y, int z, int result[], int ind);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    int        len1 = 0, len2 = 0, num1, num2, sign = 0;
    int        mc[MAX], a[MAX], q[MAX], m[MAX];

    if (argc != 3)
    {
       fprintf(stderr, "Usage: %s <Multiplicand> <Multiplier>.\n", argv[0]);
       exit(1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    if ((num1 * num2) < 0)
    {
       sign = 1;
    }

    len1 = uitobi(num1, m);
    len2 = uitobi(num2, q);

    abooth(mc, a, m, q, len1, len2, sign);
    exit(0);
}

/********* FUNCTION DEFINITION **********/
void abooth(int mc[], int a[], int  m[], int q[], int len1, int len2, int sign)
{
   int        i, k = 0;
   int        tmp[MAX];

   reverse(m, len1);
   reverse(q, len2);
   len2 = radix4(q, len2);
   comp2(m, mc, len1);

   for (i = 0; i < len1; i++)
   {
      a[i] = 0;
   }

   i = 0;
   while (i < len2)
   {
      if (q[0] == 1)
      {
         ripple(a, m, len1);
      }
      else if (q[0] == -1)
      {
         ripple(a, mc, len1);
      }
      else if (q[0] == 2)
      {
         ripple(a, m, len1);
         ripple(a, m, len1);
      }
      else if (q[0] == -2)
      {
         ripple(a, mc, len1);
         ripple(a, mc, len1);
      }
      shrb(a, q, len1, len2);
      shrb(a, q, len1, len2);
      i += 2;
   }

   for (i = len1-1; i >= 0; i--)
   {
      printf("%d", a[i]);
      tmp[k] = a[i];
      k++;
   }
   for (i = len2-1; i >= 0; i--)
   {
      printf("%d", q[i]);
      tmp[k] = q[i];
      k++;
   }
   printf(" is the resultant value.\n");

   if (sign == 1)
   {
      bitosi(tmp, len1+len2);
   }
   else
   {
      bitoi(tmp, len1+len2);
   }
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

void shrb(int a[], int q[], int len1, int len2)
{
   int        i = 0;

   q[i-1] = q[i];
   for (i = 0; i < len2-1; i++)
   {
      q[i] = q[i+1];
   }
   q[i] = a[0];

   for (i = 0; i < len1-1; i++)
   {
      a[i] = a[i+1];
   }
   a[i] = a[i-1];

   return ;
}

void comp2(int m[], int mc[], int len1)
{
   int        i = 0;
   int        one[MAX];

   one[i] = 1;
   while (i < len1)
   {
      mc[i] = (1 - m[i]);
      one[i+1] = 0;
      i++;
   }
   ripple(mc, one, len1);

   return ;
}

int radix4(int q[], int len2)
{
   int        i, r[MAX];

   q[-1] = 0;

   if (len2%2 == 1)
   {
      q[len2] = q[len2-1];
      len2++;
   }
   for (i = 0; i < len2; i++)
   {
      r[i] = (q[i-1]-q[i]);
   }

   i = 0;
   while (i < len2)
   {
      q[i] = (r[i]*1 + r[i+1]*2);
      q[i+1] = 0;
      i = i + 2;
   }

   return len2;
}

void ripple(int a[], int m[], int len1)
{
   int        i = 0, x1, x2, carry = 0;

   while (i < len1)
   {
      x1 = a[i];
      x2 = m[i];

      carry = fulladd(x1, x2, carry, a, i);
      i++;
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

void printarray(int array[], int nitems)
{
   int        i;

   for (i = 0; i < nitems; i++)
   {
      printf("%d", array[i]);
   }

   return ;
}

int uitobi(int num, int str[])
{
   int        i = 0, rem, bi = 2, sign;

   if (num < 0)
   {
      sign = 1;
      num = -num;
   }
   else
   {
      sign = 0;
   }

   do
   {
      rem = num % bi;
      if ((rem >= 0) && (rem <= 1))
      {
         str[i++] = rem;
      }
   } while ((num /= bi) > 0);

   if (sign == 1)
   {
      comp2(str, str, i);
   }
   str[i++] = sign;
   reverse(str, i);

   return i;
}

void bitosi(int str[], int ind)
{
   int        i = ind-1, x = 0, num = 0, check = 0;

   reverse(str, ind);

   while (i >= 0)
   {
      if ((str[i] == 0) || (str[i] == 1))
      {
         if (str[i] == 1 && check == 0)
         {
            x = pow2(i);
            num = num + (-1*(str[i] * x));
            check = 1;
         }
         else
         {
            x = pow2(i);
            num = num + str[i] * x;
         }
      }
      else
      {
         printf("Given string is not a Binary string\n");
         exit(2);
      }
      i--;
   }

   printf("%d is the resultant value.\n", num);
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
