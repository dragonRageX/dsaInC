#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char text[] = "abccdda";
char pattern[] = "cdd";

//                              1233441             344
void rabinKarpComparison(int textToNumber[], int patternToNumber[], int m, int n)
{
    int hashValueOfPattern = 0;
    int hashValueOfTextWindow = 0;
    int spuriousHits = 0;
    int j;
    for(int i = 0; i < n; i++)
    {
        hashValueOfPattern = hashValueOfPattern + (patternToNumber[i] * pow(10, n - 1 - i));
        hashValueOfTextWindow = hashValueOfTextWindow + (textToNumber[i] * pow(10, n - 1 - i));
    }
    //compare text windows to pattern
    for(int i = 0; i <= m - n; i++)
    {
        if(hashValueOfTextWindow == hashValueOfPattern)
        {
            //check each individual character of text window and pattern
            for(j = 0; j < n; j++)
            {
                if(text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if(j == n)
            {
                printf("Pattern found at index %d of text\n", i);
            }
            else
            {
                spuriousHits++;
                printf("%d \n", spuriousHits);
            }
        }

        if(i < m - n)
        {
            hashValueOfTextWindow = (hashValueOfTextWindow - textToNumber[i] * pow(10, n - 1)) * 10 + textToNumber[i + n];
            printf("%d \n", hashValueOfPattern);
        }
    }

}

int main()
{
    int m = strlen(text);
    int n = strlen(pattern);
    int textToNumber[m], patternToNumber[n];
    for(int i = 0; i < m; i++)
    {
        if(text[i] == 'a')
        {
            textToNumber[i] = 1;
        }
        else if(text[i] == 'b')
        {
            textToNumber[i] = 2;
        }
        else if(text[i] == 'c')
        {
            textToNumber[i] = 3;
        }
        else if(text[i] == 'd')
        {
            textToNumber[i] = 4;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(pattern[i] == 'a')
        {
            patternToNumber[i] = 1;
        }
        else if(pattern[i] == 'b')
        {
            patternToNumber[i] = 2;
        }
        else if(pattern[i] == 'c')
        {
            patternToNumber[i] = 3;
        }
        else if(pattern[i] == 'd')
        {
            patternToNumber[i] = 4;
        }
    }
    rabinKarpComparison(textToNumber, patternToNumber, m, n);

    return 0;
}
