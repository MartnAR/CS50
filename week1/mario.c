// load libraries 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initiate height input and i, j, and n integers 
    int i, j, n;
    do
    {
        n = get_int("Height: "); 
    }
    while (n <= 0 || n >= 9);
    {
        // iterate through rows 
        for (i = 1; i <= n; i++)
        {
            // print spaces in decresing order   
            for (j = i; j < n; j++)
            {
                printf(" "); 
            }

            // print pound sign in increasing order 
            for (j = 1; j <= i; j++)
            {
                printf("#"); 
            }

            // print spaces between both sides of the pyramid 
            printf("  "); 

            // print decresing pyramid side 
            for (j = n; j > n - i; j--)
            {
                printf("#"); 
            }

            // move to next line 
            printf("\n"); 
        }
    }
}
