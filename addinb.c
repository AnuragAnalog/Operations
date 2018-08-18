#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS **********/
#define   MAX         32

/********* FUNCTION DECLARATION *********/
void addinb(char *bi1, char *bi2, int b);
void reverse(char *str);

/********* MAIN STARTS HERE **********/
int main(int argc, char **argv)
{
   int        b;
   char       *bi1, *bi2;

   if (argc != 4)
   {
      fprintf(stderr, "Usage: %s <binary-value 1> <binary-value 2> <base>\n", argv[0]);
      exit(1);
   }

   bi1 = argv[1];
   bi2 = argv[2];
   b = atoi(argv[3]);

   if (b <= 1 || b > 10)
   {
      printf("The base value should be between 2 and 10\n");
      exit(2)
   }

   if (strlen(bi1) != strlen(bi2))
   {
      printf("The binary values should contain equal no. of digits.\n");
      exit(3);
   }
   else if (strlen(bi1) > 32 || strlen(bi2) > 32)
   {
      printf("The length of the binary value should be <= 32 digits.\n");
      exit(4);
   }

   addinb(bi1, bi2, b);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void addinb(char *bi1, char *bi2, int b)
{
   int        i = 0, x1, x2, carry = 0, j, base;
   int        sum[MAX];

   base = b + 48;

   reverse(bi1);
   reverse(bi2);

   while (*bi1 != '\0' && *bi2 != '\0')
   {
      if ((*bi1 >= '0' && *bi1 < base) && (*bi2 >= '0' && *bi2 < base))
      {
         x1 = (int)(*bi1 - '0');
         x2 = (int)(*bi2 - '0');

         if (x1 + x2 + carry < b)
         {
            sum[i] = x1 + x2 + carry;
            carry = 0;
         }
         else
         {
            sum[i] = (x1 + x2 + carry)%b;
            carry = 1;
         }
      }
      else
      {
         printf("This is an Invalid string with base %d\n", b);
         exit(5);
      }

      i++;
      bi1++;
      bi2++;
   }

   if (carry == 1)
   {
      sum[i] = 1;
   }
   else
   {
      i = i - 1;
   }

   for (j = i; j >= 0; j--)
   {
      printf("%d", sum[j]);
   }
   printf(" is the resultant value in base %d\n", b);

   return ;
}

void reverse(char *str)
{
   int       c, i, j;

   for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
   {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
   }
   return ;
}

