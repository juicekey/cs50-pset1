#include <stdio.h>
#include <cs50.h>
#include <math.h>

void numcoins(float cents);
int main(void)
{
    int cents = round(100 * get_float("Enter a dollar amount:"));
    //convert user input to int
    while (cents < 0)
    {
        cents = get_float("Enter a dollar amount:");
        //continue to prompt for input if negative number
    }
    numcoins(cents);
    //call coin counting function
}

void numcoins(float cents)
{
    int num = 0;
    //initialize number of coins
    
    float q, d, n, p;

    q = 25;
    d = 10;
    n = 5;
    p = 1;
    //declare coin values
    
    while (cents >= q)
    {
        cents = cents - q;
        num ++;
        //check for quarters
    }
    while (cents >= d)
    {
        cents = cents - d;
        num ++;
        //dimes
    }
    while (cents >= n)
    {
        cents = cents - n;
        num ++;
        //nickels
    }
    while (cents >= p)
    {
        cents = cents - p;
        num ++;
        //pennies
    }
    printf("%i\n", num);
    //print the result
}