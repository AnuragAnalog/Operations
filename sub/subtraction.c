#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void menu(int format[]);
void reverse(char *str);
void onecom(char *bi1, char *bi2, int format[], int len1, int len2, int sum[]);
void twocom(int sum[], int len, int format[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        len1, len2;
   int        format[MAX], sum[MAX];
   char       bi1[MAX], bi2[MAX];

   menu(format);

   printf("Enter the first binary value:- ");
   scanf("%s", bi1);

   printf("Enter the second binary value:- ");
   scanf("%s", bi2);

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

   onecom(bi1, bi2, format, len1, len2, sum);
   twocom(sum, len1, format);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void menu(int format[])
{
   int        opt;

   printf("In which type of notation should I take the first binary value?\n");
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

   printf("In which type of notation should I take the second binary value?\n");
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

void onecom(char *bi1, char *bi2, int format[], int len1, int len2, int sum[])
{
   int        i = 0, x1, x2, carry = 0, num;

   if (format[0] == 2)
   {
      reverse(bi1);
   }

   if (format[1] == 2)
   {
      reverse(bi2);
   }

   while ((*bi1 != '\0' && *bi2 != '\0'))
   {
      x1 = (int)(*bi1 - '0');
      x2 = 1 - (int)(*bi2 - '0');

      num = 0;
      num = (((num | (x1 << 2)) | (x2 << 1)) | carry);

      switch (num)
      {
         case 1:
               sum[i] = 1;
               carry = 0;
               break;
         case 2:
               sum[i] = 1;
               carry = 0;
               break;
         case 3:
               sum[i] = 0;
               carry = 1;
               break;
         case 4:
               sum[i] = 1;
               carry = 0;
               break;
         case 5:
               sum[i] = 0;
               carry = 1;
               break;
         case 6:
               sum[i] = 0;
               carry = 1;
               break;
         case 7:
               sum[i] = 1;
               carry = 1;
               break;
         case 0:
               sum[i] = 0;
               carry = 0;
               break;
         default:
               printf("Given strings are not in binary.\n");
               exit(2);
      }
      i++;
      bi1++;
      bi2++;
   }

   return ;
}

void twocom(int sum[], int len, int format[])
{
   int        i = 0, x1, x2, carry = 0, num, j;
   int        one[MAX], diff[MAX];

   one[i] = 1;
   for (i = 1; i < len; i++)
   {
      one[i] = 0;
   }

   i = 0;
   while (i < len)
   {
      x1 = sum[i];
      x2 = one[i];

      printf("%d %d %d\n", x1, x2, carry);
      num = 0;
      num = (((num | (x1 << 2)) | (x2 << 1)) | carry);

      switch (num)
      {
         case 1:
               diff[i] = 1;
               carry = 0;
               break;
         case 2:
               diff[i] = 1;
               carry = 0;
               break;
         case 3:
               diff[i] = 0;
               carry = 1;
               break;
         case 4:
               diff[i] = 1;
               carry = 0;
               break;
         case 5:
               diff[i] = 0;
               carry = 1;
               break;
         case 6:
               diff[i] = 0;
               carry = 1;
               break;
         case 7:
               diff[i] = 1;
               carry = 1;
               break;
         case 0:
               diff[i] = 0;
               carry = 0;
               break;
      }
      i++;
   }

   if (format[2] == 1)
   {
      if (carry == 1)
      {
         printf("1");
         printf("it is an unsigned value");
      }
      for (j = 0; j < i; j++)
      {
         printf("%d", diff[j]);
      }
      printf(" is the resultant string in BIG ENDIAN Notation.\n");
   }
   else if (format[2] == 2)
   {
      if (carry == 1)
      {
         diff[i] = 1;
      }
      else
      {
         i = i - 1;
      }
      for (j = i; j >= 0; j--)
      {
         printf("%d", diff[j]);
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

