#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S1[20] = "ACADB";
char S2[20] = "CBDA";
int m, n;
int LCSTable[20][20];

void lcsAlgo()
{
    m = strlen(S1);
    n = strlen(S2);
    for(int i = 0; i < m + 1; i++)
    {
        LCSTable[i][0] = 0;
    }
    for(int j = 0; j < n + 1; j++)
    {
        LCSTable[0][j] = 0;
    }
    //filling up the LCS table with values
    for(int i = 1; i < m + 1; i++)
    {
        for(int j = 1; j < n + 1; j++)
        {
            if(S1[i - 1] == S2[j - 1])
            {
                LCSTable[i][j] = LCSTable[i - 1][j - 1] + 1;
                //printf("indexes: %d, %d \n", i, j);
            }
            else if(LCSTable[i - 1][j] >= LCSTable[i][j - 1])   //we point upwards for equal values on the left and top
            {
                LCSTable[i][j] = LCSTable[i - 1][j];
            }
            else if(LCSTable[i][j - 1] > LCSTable[i - 1][j])   //left > top
            {
                LCSTable[i][j] = LCSTable[i][j - 1];
            }
        }
    }
    //now we backtrack and follow the arrowheads
    int lengthOfLCS = LCSTable[m][n];
    char lcs[lengthOfLCS + 1];
    lcs[lengthOfLCS] = '\0';   //last element of lcs array set to a null value
    while(m > 0 && n > 0)
    {
        if(S1[m - 1] == S2[n - 1])
        {
            lcs[lengthOfLCS - 1] = S1[m - 1];
            m--;
            n--;
            lengthOfLCS = lengthOfLCS - 1;
        }
        else if(LCSTable[m - 1][n] >= LCSTable[m][n - 1])   //top >= left
        {
            m--;
        }
        else if(LCSTable[m][n - 1] > LCSTable[m - 1][n])   //left > top
        {
            n--;
        }
    }
    // Printing the sub sequences
    printf("S1: %s \n", S1);
    printf("S2: %s \n", S2);
    printf("LCS: %s \n", lcs);
}

int main()
{
    lcsAlgo();
    printf("\n");

    return 0;
}
