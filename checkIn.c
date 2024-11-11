#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//
// Created by darek.czyzewski24 on 11/6/2024.
//

// all variables will be declared here if used
// will most likely end up writing the list of available rooms
// to a text file, seems easier(?)
// ones that end up being only used here will be moved to local variables
// for now though theyre staying global until i know which ones i can keep
// local or global
char fname[20];
char sname[20];
char BiD[25];
char availableRooms[6];
char BType;
char newspaper;
int totalGuests;
int adultGuests;
int minorGuests;
int lengthOfStay;

// these variable(s) arent important to me right now
// but theyre going to be used for checking out
// seems easier and better to just get them now
int oldestAge;

int main(void) {
    setbuf(stdout, NULL);
    // sets the seed for generating a random number for the BiD
    // if you are touching my code dont do this again and just leave this
    srand(time(NULL));
    // massive block of data entry from user

    printf("Enter your first name: ");
    fflush(stdin);
    scanf("%s", fname);
    printf("Enter your second name: ");
    fflush(stdin);
    scanf("%s", sname);
    printf("How many guests are staying, including you?");
    fflush(stdin);
    scanf("%d", &totalGuests);
    if(totalGuests > 4) {
        printf("You have too many guests with you. This booking will be cancelled and you will be returned to the main menu.");
        // add the subroutine to go back to the menu here, someone will code it later
    }
    printf("How many of those guests are adults?");
    fflush(stdin);
    scanf("%d", &adultGuests);
    minorGuests = totalGuests - adultGuests;
    printf("For how long are you staying?");
    fflush(stdin);
    scanf("%d", &lengthOfStay);
    printf("What type of board are you booking?");
    printf("Prices are per person, per day.");
    printf("F - Full Board - £20 \nH - Half Board - £15\nB - Bed & Breakfast - £5");
    fflush(stdin);
    scanf("%c", &BType);
    printf("Would you like a daily newspaper? Y/N");
    fflush(stdin);
    scanf("%c", &newspaper);

    // end of massive block of data entry, any other inputs relating to this go
    // above this line!!!

    // booking a room
    // im going to do this later when i figure out text files

    // generating a BiD
    


    return 0;
}