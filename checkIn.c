#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

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
char availableRooms[7];
char BType;
char newspaper;
int totalGuests;
int adultGuests;
int minorGuests;
int lengthOfStay;
int desiredRoom = 0;

// these variable(s) arent important to me right now
// but theyre going to be used for checking out
// seems easier and better to just get them now
int oldestAge;

int main(void) {
    // local variable(s)
    char number;
    //
    setbuf(stdout, NULL);
    // sets the seed for generating a random number for the BiD
    // if you are touching my code dont do this again and just leave this
    srand(time(NULL));
    // massive block of data entry from user

    printf("Enter your first name:");
    fflush(stdin);
    scanf("%s", fname);
    printf("Enter your second name:");
    fflush(stdin);
    scanf("%s", sname);
    printf("How many guests are staying, including you?");
    fflush(stdin);
    scanf("%d", &totalGuests);
    if(totalGuests > 4 || totalGuests < 1) {
        printf("You have too many guests with you or have input an invalid number. This booking will be cancelled and you will be returned to the main menu.");
        // add the subroutine to go back to the menu here, someone will code it later
    }
    printf("How many of those guests are adults?");
    fflush(stdin);
    scanf("%d", &adultGuests);
    if(adultGuests < 1) {
        printf("There are no adults and therefore you cannot book. The program will exit to the menu.");
        Sleep(400);
        abort();
    }
    minorGuests = totalGuests - adultGuests;
    printf("For how many days are you staying?");
    fflush(stdin);
    scanf("%d", &lengthOfStay);
    printf("What type of board are you booking?\n");
    printf("Prices are per person, per day.\n");
    printf("F - Full Board - 20 \nH - Half Board - 15\nB - Bed & Breakfast - 5\n");
    fflush(stdin);
    scanf("%c", &BType);
    printf("Would you like a daily newspaper? Y/N");
    fflush(stdin);
    scanf("%c", &newspaper);

    // end of massive block of data entry, any other inputs relating to this go
    // above this line!!!

    FILE* roomFilePointer2 = fopen("rooms.txt", "r");
        if (roomFilePointer2 == NULL) {
            FILE* roomFilePointer2 = fopen("rooms.txt", "w");
            fputs("123456", roomFilePointer2);
            fclose(roomFilePointer2);
        }
        FILE* roomFilePointer = fopen("rooms.txt", "r");
        fgets(availableRooms, 7, roomFilePointer);
        fclose(roomFilePointer);
        availableRooms[7] = 0;
        printf("Our currently vacant rooms are: \n");
        for(int counter = 0; counter < 6; counter++) {
            if(availableRooms[counter] != 88) {
                switch(availableRooms[counter]){
                    case 49:
                        printf("%c : 100 per day.\n", availableRooms[counter]);
                    break;
                    case 50:
                        printf("%c : 100 per day.\n",availableRooms[counter]);
                    break;
                    case 51:
                        printf("%c : 85 per day.\n",availableRooms[counter]);
                    break;
                    case 52:
                        printf("%c : 75 per day.\n",availableRooms[counter]);
                    break;
                    case 53:
                        printf("%c : 75 per day.\n",availableRooms[counter]);
                    break;
                    case 54:
                        printf("%c : 50 per day.\n",availableRooms[counter]);
                    break;
                    default:
                        printf("Something has gone wrong.");
                    break;
                }
            }
        }
    printf("What room would you like to book?");
    scanf("%d", &desiredRoom);
        for(int counter = 0; counter < 6; counter++) {
            int placeholder = availableRooms[counter];
            if(desiredRoom == placeholder - 48) {
                printf("Your booking of room %d was a success.", desiredRoom);
                availableRooms[counter] = 88;
                FILE* temp = fopen("rooms.txt", "w");
                fprintf(temp, availableRooms);
                fclose(temp);
                break;
            }
            else{
                printf("You have tried to book an invalid room. The program will now return you to the menu.");
                Sleep(400);
                abort();
            }

        }
    strcpy(BiD, sname);
    for(int i = strlen(sname); i < strlen(sname) + 5; i++) {
        number = rand() % 9;
        BiD[i] = number + '0';
        Sleep(50);
    }

    BiD[strlen(sname) + 5] = toupper(BType);
    BiD[strlen(sname) + 6] = totalGuests + '0';
    BiD[strlen(sname) + 7] = 0;

    FILE* BiDFilePointer = fopen("bookingids.txt", "a");
    fprintf(BiDFilePointer, BiD);
    fprintf(BiDFilePointer, "\n");
    fclose(BiDFilePointer);
    printf("\nYour booking iD is: %s. Please do not lose this as you will not be able to book tables or check out.", BiD);

    FILE* bookingDataPointer = fopen("bookingdata.csv", "a");
    fprintf(bookingDataPointer, BiD);


    return 0;
}