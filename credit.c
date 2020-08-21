#include <stdio.h>
#include <cs50.h>
#include <math.h>

void amex(long number);
void mastercard(long number);
void visa13(long number);
void visa16(long number);
//one function for each type of card

int main(void)
{
    long number = get_long("Enter a credit card number: ");
    //prompt for card number
    if ((number >= 34E13 && number < 35E13) || (number >= 37E13 && number < 38E13))
    {
        amex(number);
    }
    else if (number >= 51E14 && number < 56E14)
    {
        mastercard(number);
    }
    else if (number >= 4E12 && number < 5E12)
    {
        visa13(number);
    }
    else if (number >= 4E15 && number < 5E15)
    {
        visa16(number);
    }
    //decide which card company
    else
    {
        printf("INVALID\n");
        //filter out obvious invalids
    }
}

void amex(long number)
//decide if number within amex range is valid
{
    int total = 0;
    //initialize total from adding up digits
    int digits = 15;
    //number of digits for card type
    
    for (int i = 1; i <= digits; i++)
    {
        int rem = number%10;
        //get first digit
        if (i % 2 != 0)
        //if odd
        {
            total = total + rem;
        }
        else
        //if even
        {
            int rem2 = 2 * rem;
            //double remainder
            if (rem2 < 10)
            {
                total = total + 2 * rem;
                //immediately add single digit remainders to total
            }
            else
            {
                int rem3 = rem2%10;
                total = total + rem3 + 1;
                //add digits of double digit remainders
            }
        }
        number = (number - rem) / 10;
        //remove original remainder and divide by 10
        
    }
    if (total % 10 == 0)
    //if valid
    {
        printf("AMEX\n");
    }
    else
    //if invalid
    {
        printf("INVALID\n");
    }
}

void mastercard(long number)
//same as amex
{
    int total = 0;
    int digits = 16;
    
    for (int i = 1; i <= digits; i++)
    {
        int rem = number%10;
        if (i % 2 != 0)
        {
            total = total + rem;
        }
        else
        {
            int rem2 = 2 * rem;
            if (rem2 < 10)
            {
                total = total + 2 * rem;
            }
            else
            {
                int rem3 = rem2%10;
                total = total + rem3 + 1;
            }
        }
        number = (number - rem) / 10;
        
    }
    if (total % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

void visa13(long number)
//same as amex
{
    int total = 0;
    int digits = 13;
    
    for (int i = 1; i <= digits; i++)
    {
        int rem = number%10;
        if (i % 2 != 0)
        {
            total = total + rem;
        }
        else
        {
            int rem2 = 2 * rem;
            if (rem2 < 10)
            {
                total = total + 2 * rem;
            }
            else
            {
                int rem3 = rem2%10;
                total = total + rem3 + 1;
            }
        }
        number = (number - rem) / 10;
        
    }
    if (total%10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

void visa16(long number)
//same as amex
{
    int total = 0;
    int digits = 16;
    
    for (int i = 1; i <= digits; i++)
    {
        int rem = number%10;
        if (i%2 != 0)
        {
            total = total + rem;
        }
        else
        {
            int rem2 = 2 * rem;
            if (rem2 < 10)
            {
                total = total + 2 * rem;
            }
            else
            {
                int rem3 = rem2%10;
                total = total + rem3 + 1;
            }
        }
        number = (number - rem) / 10;
        
    }
    if (total%10 == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

