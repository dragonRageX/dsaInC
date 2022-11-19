#include <stdio.h>
#include <stdlib.h>

int main()
{
    int beg, end, mid;
    beg = 0;
    end = n - 1;
    while(end > beg)
    {
        mid = (beg + end) / 2;
        if(array[mid] < value)
        {
            beg = mid + 1;
        }
        else if(array[mid] > value)
        {
            end = mid - 1;
        }
        else if(array[mid] == value)
        {
            printf("The element: %d is present in the array at the position %d", value, mid + 1);
        }
    }
    printf("The element: %d is not present in the array", value);
    return 0;
}
