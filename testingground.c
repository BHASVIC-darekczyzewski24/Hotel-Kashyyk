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
    FILE* roomFilePointer2 = fopen("rooms.txt", "r");
    if (roomFilePointer2 == NULL) {
        roomFilePointer2 = fopen("rooms.txt", "w");
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
            }
        }
    }
    scanf("%d", &desiredRoom);
    for(int counter = 0; counter < 6; counter++) {
        int placeholder = availableRooms[counter];
        if(desiredRoom == placeholder - 48) {
            printf("Your booking of room %d was a success.", desiredRoom);
            availableRooms[counter] = 88;
            printf("\n %s", availableRooms);
            FILE* temp = fopen("rooms.txt", "w");
            fprintf(temp, availableRooms);
            break;
        }

    }

    return 0;
}