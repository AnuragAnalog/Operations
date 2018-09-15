#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void menu(int format[]);
void reverse(char *str);
void addition(char *bi1, char *bi2, int format[], int len1, int len2, int b);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        len1, len2, b;
   int        format[MAX];
   char       bi1[MAX], bi2[MAX];

   menu(format);

   printf("Enter the first value:- ");
   scanf("%s", bi1);

   printf("Enter the first value:- ");
   scanf("%s", bi2);

   printf("Enter the base:- ");
   scanf("%d", &b);

   if (b <= 1 || b > 10)
   {
      printf("The base value should be between 2 and 10\n");
      exit(2);
   }

   len1 = strlen(bi1);
   len2 = strlen(bi2);

   if (strlen(bi1) != strlen(bi2))
   {
      printf("The binary values should contain equal no. of digits.\n");
      exit(1);
   }
   else if (len1 > 32 || len2 > 32 )
   {
      printf("The no. of digits of the binary values should be <= 32.\n");
      exit(2);
   }

   addition(bi1, bi2, format, len1, len2, b);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void menu(int format[])
{
   int        opt;

   printf("In which type of notation should I take the first value?\n");
   printf("     1) Big Endian\n");
   printf("     2) Little Endian\n");

   printf("Your option please: ");
   scanf("%d", &opt);

   if (opt < 1 || opt > 2)
   {
      printf("Select the options which are given above\n");
      exit(1);
   }

   format[0] = opt;

   printf("In which type of notation should I take the second value?\n");
   printf("     1) Big Endian\n");
   printf("     2) Little Endian\n");

   printf("Your option please: ");
   scanf("%d", &opt);

   if (opt < 1 || opt > 2)
   {
      printf("Select the options which are given above\n");
      exit(1);
   }

   format[1] = opt;

   printf("In which type of notation should I represent the sum?\n");
   printf("     1) Big Endian\n");
   printf("     2) Little Endian\n");

   printf("Your option please: ");
   scanf("%d", &opt);

   if (opt < 1 || opt > 2)
   {
      printf("Select the options which are given above\n");
      exit(1);
   }

   format[2] = opt;
   system("clear");

   return ;
}

void addition(char *bi1, char *bi2, int format[], int len1, int len2, int b)
{
   int        i = 0, x1, x2, carry = 0, j, base;
   int        sum[MAX];

   base = b + 48;

   if (format[0] == 2)
   {
      reverse(bi1);
   }

   if (format[1] == 2)
   {
      reverse(bi2);
   }

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

   if (format[2] == 1)
   {
      for (j = 0; j < i+1; j++)
      {
         printf("%d", sum[j]);
      }
      printf(" is the resultant string in BIG ENDIAN Notation.\n");
   }
   else if (format[2] == 2)
   {
      for (j = i; j >= 0; j--)
      {
         printf("%d", sum[j]);
      }
      printf(" is the resultant string in LITTLE ENDIAN Notation.\n");
   }

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
