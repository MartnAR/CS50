// load libraries 
#include <cs50.h>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

// initiate main 
int main(void)
{
    // initiate long 
    long n; 

    // initiate ints
    int nDigits, first_digits, even_numbers, left_behind, final_sum, check_sum; 
    n = get_long("Number: "); 
    
    // get length of n 
    nDigits = floor(log10(n)) + 1;

    // get first two digits of card
    first_digits = n / pow(10, nDigits - 2);

    // initiate odd_numbers and left_behind to 0
    even_numbers = 0;
    left_behind = 0;
    
    // loop through every digit of the credit card number
    for (int i = 0; i < nDigits; i++)
    {
        // get the last digit of the credit card number
        int y = n % 10 ;

        // check whether i is odd or even
        // if even 
        if (i % 2 != 0)
        {
            // multiplies the current digit by 2
            int z = y * 2;

            // calculate length of the digits
            int zDigits = floor(log10(z)) + 1;

            // if the length of zDigits is greater than 1, sum each part together...
            if (zDigits > 1)
            {
                int d = z % 10 + (z / 10) % 10;
                even_numbers += d;
            }
            // ...else sum the digit
            else 
            {
                even_numbers += z;
            }
        }
        // if the current digit is even, then add it to left_behind
        else
        {
            left_behind += y;
        }
        // divide the current digits by 10 to drop the last number
        n /= 10;
    }
    // add the results of even_numbers and left_behind; check if the last number is 0
    final_sum = even_numbers + left_behind; 
    check_sum = final_sum % 10; 
//    printf("%i\n", first_digits);

    // if the last number is not 0, then the card is invalid...
    if (check_sum != 0)
    {
        printf("INVALID\n"); 
    }
    // ...else check if it belongs to MasterCard, Visa, or AMEX
    else
    {
        if (first_digits == 37)
        {
            printf("AMEX\n");
        }
        else if (first_digits >= 51 && first_digits <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((first_digits >= 40 && first_digits <= 49) && (nDigits == 13 || nDigits == 16))
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
}
