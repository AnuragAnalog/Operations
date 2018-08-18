#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS **********/
#define   MAX         32

/********* FUNCTION DECLARATION *********/
void addbi(char *bi1, char *bi2);
void reverse(char *str);

/********* MAIN STARTS HERE **********/
int main(int argc, char **argv)
{
   char       *bi1, *bi2;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <binary-value 1> <binary-value 2>\n", argv[0]);
      exit(1);
   }

   bi1 = argv[1];
   bi2 = argv[2];

   if (strlen(bi1) != strlen(bi2))
   {
      printf("The binary values should contain equal no. of digits.\n");
      exit(2);
   }
   else if (strlen(bi1) > 32 || strlen(bi2) > 32)
   {
      printf("The length of the binary value should be <= 32 digits.\n");
      exit(3);
   }

   addbi(bi1, bi2);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void addbi(char *bi1, char *bi2)
{
   int        i = 0, x1, x2, carry = 0, num, j;
   int        sum[MAX];

   reverse(bi1);
   reverse(bi2);

   while ((*bi1 != '\0' && *bi2 != '\0'))
   {
      x1 = (int)(*bi1 - '0');
      x2 = (int)(*bi2 - '0');

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
   printf(" is the resultant string.\n");

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

