#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>


//
// Created by darek.czyzewski24 on 11/19/2024.
//

int main(void){
    char sname[15];
    char BiD[25];
    char number;
    strcpy(BiD, sname);
    for(int i = strlen(sname); i < strlen(sname) + 7; i++) {
        number = rand() % 9;
        BiD[i] = number + '0';
        Sleep(50);
    }
    BiD[strlen(same) + 7] = 0;

    FILE* BiDFilePointer = fopen("bookingids.txt", "a");
    fprintf(BiDFilePointer, BiD);
    fprintf(BiDFilePointer, "\n");
    fclose(BiDFilePointer);
    printf("Your booking iD is: %s. Please do not lose this as you will not be able to book tables or check out.", BiD);

    return 0;

}