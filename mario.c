#include <stdio.h>
#include <cs50.h>

void print_pyramid(int height);

int main(void)
{
    int height = get_int("How tall should the pyramid be?\nEnter an integer between 1 and 8: ");
    //prompt for pyramid height
    while (height < 1 || height > 8 || height%1 !=0)
    {
        
        height = get_int("Enter an integer between 1 and 8: ");
        //while incorrect entries entered, prompt user
    }
    print_pyramid(height);
    //once correct entry received, execute pyramid printing function
}

void print_pyramid(int height)
//pyramid printing function
{
    for (int i = 0; i<height; i++)
        {
            int width = height - i-2;
            for (int k = 0; k<=width; k++)
            {
                printf(" ");
            }
            //print spaces
            for (int j = 0; j<=i; j++)
            {
                
                printf("#");
            }
            //print hashes
            printf("  ");
            //print middle spaces
            for (int l = 0; l<=i; l++)
            {
                
                printf("#");
                //print hashes on the other side
            }
            printf("\n");
        }
}