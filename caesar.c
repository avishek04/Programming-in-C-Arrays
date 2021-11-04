
//  caesar.c
/*
 Implement a program that encrypts messages using Caesar’s cipher, per the below.

 $ ./caesar 13
 plaintext:  HELLO
 ciphertext: URYYB
*/

#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

bool ValidityCheck(string cmdArg);  //"string" from cs50.h

int main(int argc, string argv[])
{
   if(argc == 2 && ValidityCheck(argv[1]))
   {
      int key = atoi(argv[1]);
      string plainText = get_string("plaintext: ");  //"get_string" from cs50.h

      int wordLength = strlen(plainText);
      string cipherText = malloc(wordLength+1);

      for(int i=0; i<wordLength; i++)
      {
         if((plainText[i] > 64 && plainText[i] < 91) || (plainText[i] > 96 && plainText[i] < 123))
         {
            if(islower(plainText[i]))
            {
               cipherText[i] = (char)((plainText[i] - 97 + key)%26 + 97);
            }
            else
            {
               cipherText[i] = (char)((plainText[i] - 65 + key)%26 + 65);
            }
         }
         else
         {
            cipherText[i] = plainText[i];
         }
      }

      printf("ciphertext: %s\n", cipherText);
   }
   else
   {
      printf("Usage: ./caesar key\n");
      return 1;
   }
}

bool ValidityCheck(string cmdArg)
{
   int isDigit = 0;
   int i = 0;
   while(i < strlen(cmdArg) && isDigit == 0)
   {
      if(cmdArg[i]<48 || cmdArg[i]>57)
      {
         isDigit = 1;
      }
      else
      {
         isDigit = 0;
      }
      i++;
   }

   if(isDigit == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}
