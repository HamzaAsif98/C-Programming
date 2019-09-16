#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gamefunction.h"


int main(int argc,int argv[])
{


    int _of_bombs = 2;
    struct locations * bombs = (struct locations *) malloc(sizeof(struct locations)*2);

    bombs[0].x = 1;
    bombs[0].y = 1;
    bombs[0].found = false;

    bombs[1].x = 2;
    bombs[1].y = 3;
    bombs[1].found = false;

    int bombLocations [4][4] = {1, 1, 1, 0,
                                1, 0, 2, 1,
                                1, 1, 2, 0,
                                0, 0, 1, 1};

    int knownLocations [4][4];

        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                knownLocations[i][j] = UNKNOWN;
            }
        }
      if (argc == 2) {
        printf("Please provide the command line arguments");
    }
    int i;
    for (i=0;i<argc;i++) {
        printf("\n%s ", argv[i]);
    }
    printf("\nNumber of bombs %d", _of_bombs);
    int compare = strcmp(argv[1], "clues");
    int compare1 = strcmp(argv[1], "noclues");



    if (compare ==0 ) {
        printf("\nCLUES\n");
        knownLocations[1][3] = bombLocations[1][3];
        knownLocations[3][1] = bombLocations[3][1];
        bombs[0].x = 1;
        bombs[0].y  = 1;
        bombs[0].found = false;

        bombs[1].x = 2;
        bombs[1].y  = 3;
        bombs[1].found = false;

        int size = DIM;

        start_game(bombs, bombLocations,2,DIM, knownLocations, _of_bombs);
    }
    else if (compare1 == 0) {
        printf("\nNOCLUES\n");
        bombs[0].x = 1;
        bombs[0].y  = 1;
        bombs[0].found = false;

        bombs[1].x = 2;
        bombs[1].y  = 3;
        bombs[1].found = false;

        int size = DIM;

        start_game(bombs, bombLocations,0, DIM, knownLocations, _of_bombs);
    }

    //bool foundBomb = false;

  // start_game(bombs, bombLocations,DIM, knownLocations,_of_bombs);
    /*//printf("Main Found: %d", foundBomb);
    display(knownLocations, DIM);
    checkFound(1,1,bombs,_of_bombs,&foundBomb);
    //printf("%d\n", foundBomb);
    updateKnown( 1, 1, bombLocations, knownLocations);
    checkFound(1,1,bombs,_of_bombs,&foundBomb);
    display(knownLocations, DIM);*/



   // free(bombs);
}
