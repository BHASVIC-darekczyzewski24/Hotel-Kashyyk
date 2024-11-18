#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

//
// Created by darek.czyzewski24 on 11/18/2024.
//


int main(void) {
    setbuf(stdout, NULL);
    char availableRooms[7];
    int desiredRoom = 0;
    FILE* roomFilePointer = fopen("rooms.txt", "r");
    if (roomFilePointer == NULL) {
        roomFilePointer = fopen("rooms.txt", "w");
        fputs("123456", roomFilePointer);
        printf("The list of rooms was not found. The program will now create a list of rooms. Please restart the program to avoid issues");
        Sleep(3000);
        abort();
    }
    fgets(availableRooms, 7, roomFilePointer);
    availableRooms[7] = 0;
    for(int counter = 0; counter < 6; counter++) {
        printf("%c \n", availableRooms[counter]);
    }
    fclose(roomFilePointer);
    scanf("%d", &desiredRoom);
    for(int counter = 0; counter < 6; counter++) {
        int placeholder = availableRooms[counter];
        if(desiredRoom == placeholder - 48) {
            printf("Your booking of room %d was a success.", desiredRoom);
            availableRooms[counter] = 88;
            printf("\n %s", availableRooms);
            fopen("rooms.txt", "w");
                fputs(availableRooms, "rooms.txt");
            break;
        }

    }

    return 0;
}