#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int columnPositions[4];   //this array has the row positions as the index and column numbers as its elements

void printQueensArray(int n)
{
    printf("Possible Solution Set: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Row: %d", i);
        printf("   Column: %d", columnPositions[i]);
        printf("\n");
    }
}

bool place(int i, int j)
{
    for(int k = 0; k < i; k++)   // we check all the Queens present in all the rows above the current one/preceding rows
    {
        if(j == columnPositions[k] || abs(k - i) == abs(columnPositions[k] - j))   //we check whether the current position of the Queen is violating the same column or the diagonal rule of the above placed Queens
        {
            return false;
        }
    }
    return true;
}

void nQueens(int i, int n)
{
    for(int j = 0; j < n; j++)
    {
        if(place(i, j))
        {
            columnPositions[i] = j;
            if(i == n - 1)   //if 'i' is the last row on the chessboard
            {
                printQueensArray(n);
            }
            else
            {
                nQueens(i + 1, n);
            }
        }
    }
}

int main()
{
    int n = 4;   //4 Queens Problem
    int i = 0;   //we start with the first row
    nQueens(i, n);

    return 0;
}
