//  readability.c

/*
 Implement a program that computes the approximate grade level needed to comprehend some text, per the below.

 $ ./readability
 Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
 
 Grade 3
*/

#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<string.h>

float letters(string s);  //"string" from cs50.h
float words(string s);
float sentences(string s);

int main(void)
{
    string text = get_string("Text:");  //"get_string" from cs50.h

    float L = (letters(text)/words(text))*100;
    float S = (sentences(text)/words(text))*100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
       switch(index)
    {
        case 2: printf("Grade 2\n");
        break;
        case 3: printf("Grade 3\n");
        break;
        case 4: printf("Grade 4\n");
        break;
        case 5: printf("Grade 5\n");
        break;
        case 6: printf("Grade 6\n");
        break;
        case 7: printf("Grade 7\n");
        break;
        case 8: printf("Grade 8\n");
        break;
        case 9: printf("Grade 9\n");
        break;
        case 10: printf("Grade 10\n");
        break;
        case 11: printf("Grade 11\n");
        break;
        case 12: printf("Grade 12\n");
        break;
        case 13: printf("Grade 13\n");
        break;
        case 14: printf("Grade 14\n");
        break;
        case 15: printf("Grade 15\n");
        break;
    }
    }
}

float letters(string s)
{
    int count = 0;
    for(int i=0; i<strlen(s); i++)
    {
        if((64<s[i] && 91>s[i]) || (96<s[i] && 123>s[i]))
        {
            count++;
        }
    }
    return count;
}

float words(string s)
{
    float count = 1;
    for(int i=0; i<strlen(s); i++) 
    {
        if(s[i] == 32)
        {
            count++;
        }
    }
    return count;
}

float sentences(string s)
{
    float count =0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            count++;
        }
    }
    return count;
}
