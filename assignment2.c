/*
Program Description: a program that will play a lotto game. The program allows the user to enter 6 selected numbers
                    and give them a set of 6 options using functions, each performing a specific task such as asking the
                    user to select 6 numbers, to display the selected 6 numbers, to sort them, to compare selected numbers
                    to winning numbers, display the frequency of the selected numbers and to end the program.
Auhtor: Ian Rainier Hipolito
Date: 04/03/22
*/

#include <stdio.h>

// Array size
#define SelectNum 6
#define LottoNum 6
#define SIZE 42

// Declare Function signatures/prototypes
void Select(int *, int *);
void Display(int *);
void Sort(int *);
void Compare(int *, int *);
void DisplayFreq(int *);

int main()
{
    // declaring variables used in the main function
    int options;
    int option2 = 0;
    int option3 = 0;
    int option4 = 0;
    int option5 = 0;
    int option6 = 0;
    int nums[SelectNum];
    int winlottonum[] = {1, 3, 5, 7, 9, 11};
    int freq[SIZE] = {0};

    // Do while loop does not check the condition for the first loop but checks the other loops after
    // We need to get user input before we check if it's invalid otherwise we'd be checking 0 since that's what we initialised it to
    do
    {
        // Displaying the main menu
        printf("\n<------Welcome to the Lottery Game!------> \n");
        printf("<------The Rules of the game are as follows:------> \n");
        printf("<------You will be asked to choose an option between 1 to 6.------> \n");
        printf("<------Option 1: Enter any SIX numbers between(1-42). ------> \n");
        printf("<------Option 2: Display your lotto numbers.------> \n");
        printf("<------Option 3: Sort your lotto numbers in increasing order.------> \n");
        printf("<------Option 4: Compare your lotto numbers to the winning numbers.------> \n");
        printf("<------Option 5: Display the frequency of the numbers you have used.------> \n");
        printf("<------Option 6: Exit the Lottery Game. ------> \n");

        printf("\n Please proceed by picking an option mentioned above: \n");
        scanf("%d", &options);

        // Error checking to ensure valid input for the options
        if (options != 1 && options != 2 && options != 3 && options != 4 && options != 5 && options != 6)
        {
            printf("ERROR!! That is not an option! Please make sure to pick a valid option!");
        } // end else if

        // Error checking if user input is a letter or symbol
        // Reads and discards unwanted characters 
        while (getchar() != '\n');

        // if user inputs or picks option 1 code in this if statement will be executed
        if (options == 1)
        {
            // nums array is used to input the users selected numbers
            // calling the function
            Select(nums, freq);

            // options 2 to 5 will equal to 1 when option 1 is executed to be able to execute the other options
            // option 1 first and only after option 1 has been chosen the user will be able to chose the next option.
            option2 = 1;
            option3 = 1;
            option4 = 1;
            option5 = 1;
        } // end if

        // if user inputs or picks option 2 the code in this else if statement will be executed
        else if (options == 2)
        {
            // if option 2 is greater than 0 the if statement code will execute
            if (option2 > 0)
            {
                // calling the function
                Display(nums);
            } // end if

            // Stops the user from picking option 2 before picking option 1
            else
            {
                printf("ERROR! You must pick option 1 before proceeding to option 2");
            } // end else
        }     // end else if

        // if user inputs or picks option 3 the code in this else if statement will be executed
        else if (options == 3)
        {
            // if option 3 is greater than 0 the if statement code will execute
            if (option3 > 0)
            {
                // calling the function
                Sort(nums);
            } // end if

            // Stops the user from picking option 3 before picking option 1
            else
            {
                printf("ERROR!!\n");
                printf("You have to begin by picking option 1!");
            } // end else
        }     // end else if

        // if user inputs or picks option 4 the code in this else if statement will be executed
        else if (options == 4)
        {
            // if option 4 is greater than 0 the if statement code will execute
            if (option4 > 0)
            {
                // calling the function
                Compare(winlottonum, nums);
            } // end if

            // Stops the user from picking option 4 before picking option 1
            else
            {
                printf("ERROR!!\n");
                printf("You have to begin by picking option 1!");
            } // end else
        }     // end else if

        // if user inputs or picks option 5 the code in this else if statement will be executed
        else if (options == 5)
        {
            // if option 5 is greater than 0 the if statement code will execute
            if (option5 > 0)
            {
                // in order for option 2 to be executed "freq" variable must be incremented after option 4 has been executed
                //  calling the function
                DisplayFreq(freq);
            } // end if

            // Stops the user from picking option 5 before picking option 1
            else
            {
                printf("ERROR!!\n");
                printf("You have to begin by picking option 1!");
            } // end else
        }

        // When the user enters the number 6 the program will end gracefully
    } while (options != 6);

    return 0;
}

// Option 1 function: This function allows the user to input 6 numbers of there chosing between the rane of 1-42
void Select(int *nums, int *freq)
{
    int i;
    int j;
    int temp;

    printf("Enter any SIX numbers between(1-42):\n");

    // loops 6 times to check if the numbers selected are valid
    for (i = 0; i < SelectNum; i++)
    {
        scanf("%d", &*(nums + i));

        // if statement ensures and checks that the user does not pick a number outside the range 1-42
        if (*(nums + i) >= 1 && *(nums + i) <= 42)
        {
            // this for loop is used to check and ensure that the user does not enter the same number in the array twice
            for (j = 0; j < i; j++)
            {
                if (*(nums + i) == *(nums + j))
                {
                    printf("ERROR!! You cannot enter the same number twice!");
                    // we use a return in this if statement if the user enters the same number twice in order to return to the main menu
                    return;
                } // end inner if
            }     // end inner for
        }         // end outer if

        // else statement will be execute if the user has entered a number outside the range of 1-42
        else
        {
            printf("You must enter numbers between 1-42\n");
            return;
        } // end else

        // temp variable is equal to the numbers selected + i in order to put the numbers inputted into an array
        // assign temp the current selected number entered
        temp = *(nums + i);

        // this is incremented to allow the program to count how many times a user has entered/used a number when playing the lottery game
        // Increment the corresponding index of freq with the numbers entered by the user contained in nums
        *(freq + temp) = *(freq + temp) + 1;
    } // end outer for
} // end Select Function

// Option 2 function: This function allows the user to display the inputted numbers selected
void Display(int *display)
{
    int i;

    // if for loop condition is met is iterates the statements several times causing the program to display all the numbers inputted by the user
    for (i = 0; i < SelectNum; i++)
    {
        printf("You have selected: %d\n", *(display + i));
    } // end for
} // end display function

// Option 3 function: This function allows the user to sort the numbers inputted in descending order and display them using the bubble sort algorithm
void Sort(int *sortnum)
{
    // temporary variable for swapping
    int temp = 0;
    int i;
    int j;

    printf("Numbers are being sorted...\n\n");

    // Bubble sort is an algorithm for arranging a string of numbers in the correct order.
    //loop to access each array element
    for (i = 0; i < SelectNum - 1; i++)
    {   
        //loop to compare array elements
        for (j = 0; j < SelectNum - i - 1; j++)
        {
            //compare the two adjacent elements
            //the > sorts it in increasing order
            if (*(sortnum + j) > *(sortnum + (j + 1)))
            {
                temp = *(sortnum + j);
                *(sortnum + j) = *(sortnum + j + 1);
                *(sortnum + j + 1) = temp;

            } // end if
        }     // end inner for
    }         // end outer for

    printf("\nThe numbers you have selected have been sorted\n\n");
    // Once the numbers inputted have been sorted for loop condition is met and prints the numbers out in increasing order
    for (i = 0; i < SelectNum; i++)
    {
        printf("Sorted Numbers: %d\n", *(sortnum + i));
    }
} // end bubble sort function

// Option 4 function: This function allows the user to compare their inputted numbers to the winning lottery numbers and checks if they got any matches and won any prize
void Compare(int *compareNums, int *nums)
{
    int i;
    int j;
    // SelectNumLottoNum_Same intialised to 0 as if not it can be any random number
    int SelectNumLottoNum_Same = 0;

    // looping through selected numbers
    for (i = 0; i < LottoNum; i++)
    {
        // comparing current selected number to the winning lotto numbers
        for (j = 0; j < LottoNum; j++)
        {
            if (*(nums + i) == *(compareNums + j))
            {
                printf("Same Numbers: Winning Number: %d | Number You Selected: %d \n\n", *(compareNums + j), *(nums + i));
                SelectNumLottoNum_Same++;
            } // end if
        }     // end inner for
    }         // end outer for

    // if the user inputs 0 numbers that are the same as the winning lotto numbers
    if (SelectNumLottoNum_Same == 0)
    {
        printf("Unfortunatly You Did Not Win Anything (0 matching numbers). Try again for a chance to win a prize\n");
    } // end else if

    // if the user inputs 1 number that is the same as the the winning lotto numbers
    else if (SelectNumLottoNum_Same == 1)
    {
        printf("Unfortunatly You Did Not Win Anything (only 1 matching number). Try again for a chance to win a prize\n");
    } // end else if

    // if the user inputs 2 numbers that are the same as the winning lotto numbers
    else if (SelectNumLottoNum_Same == 2)
    {
        printf("Unfortunatly You Did Not Win Anything (only 2 matching numbers). Try again for a chance to win a prize\n");
    } // end else if

    // if the user inputs 3 numbers that are the same as the winning lotto numbers
    else if (SelectNumLottoNum_Same == 3)
    {
        printf("Congratulations you WON a CINEMA PASS!!!!!!\n");
    } // end else if

    // if the user inputs 4 numbers that are the same as the winning lotto numbers
    else if (SelectNumLottoNum_Same == 4)
    {
        printf("Congratulations you WON a WEEKEND AWAY!!!!!!\n");
    } // end else if

    // if the user inputs 5 numbers that are the same as the winning lotto numbers
    else if (SelectNumLottoNum_Same == 5)
    {
        printf("Congratulations you WON a BRAND NEW CAR!!!!!!\n");
    } // end else if

    // if the user inputs 6 numbers that are the same as the winning lotto numbers
    else if (SelectNumLottoNum_Same == 6)
    {
        printf("Congratulations you WON the JACKPOT!!!!!!\n");
    } // end if

} // end compare function

// Option 5 function: This function allows the user to
void DisplayFreq(int *freq)
{
    int i;

    // loops through all the numbers in the array
    for (i = 0; i < SIZE; i++)
    {
        // if the user selects a number more atleast once throughout the game it will print the frequency of that number
        if (*(freq + i) != 0)
        {
            printf("Number %d was selected| %d times\n\n", i, *(freq + i));
        } // end if
    }     // end for
} // end display frequency function
