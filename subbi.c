#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS **********/
#define   MAX         32

/********* FUNCTION DECLARATION *********/
void onecom(char *bi1, char *bi2, int sum[]);
void twocom(int sum[], int len, char *bi1, char *bi2);
void reverse(char *str);

/********* MAIN STARTS HERE **********/
int main(int argc, char **argv)
{
   int        len;
   int        sum[MAX];
   char       *bi1, *bi2;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <binary-value 1> <binary-value 2>\n", argv[0]);
      exit(1);
   }

   bi1 = argv[1];
   bi2 = argv[2];

   len = strlen(bi1);
   if (strlen(bi1) != strlen(bi2))
   {
      printf("The binary values should contain equal no. of digits.\n");
      exit(2);
   }
   else if (strlen(bi1) > 31 || strlen(bi2) > 31)
   {
      printf("The length of the binary value should be <= 31 digits.\n");
      exit(3);
   }

   onecom(bi1, bi2, sum);
   twocom(sum, len, bi1, bi2);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void onecom(char *bi1, char *bi2, int sum[])
{
   int        i = 0, x1, x2, carry = 0, num;

   reverse(bi1);
   reverse(bi2);

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

void twocom(int sum[], int len, char *bi1, char *bi2)
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

   for (j = len-1; j >= 0; j--)
   {
      printf("%d", diff[j]);
   }
   if (atoi(bi2) > atoi(bi1))
   {
      printf(" is the resultant binary value, and its a signed integer.\n");
   }
   else
   {
      printf(" is the resultant binary value, and its a unsigned integer.\n");
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

