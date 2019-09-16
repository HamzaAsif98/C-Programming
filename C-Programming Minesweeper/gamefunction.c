#include "gamefunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char get_user_char();
void display(int knownLocationInfo [][DIM], int size){

    printf("\n  A B C D\n");
    char letter = 'A';
    for (int i = 0; i < size; i++){
            printf("%c:",letter);
            letter++;
        for (int j=0; j < size; j++){
            if (knownLocationInfo[i][j] == UNKNOWN){
                printf("* ");
            }
            else

                if (knownLocationInfo[i][j]==66){
                    printf("%c ",knownLocationInfo[i][j]);
                }else

                printf("%d ", knownLocationInfo[i][j]);
        }
        printf("\n");
    }


}

void check_found(int row, int col, struct locations bombs[], int size, bool* found) {
int* x0 = &bombs[0].x;
    int* y0 = &bombs[0].y;

    int* x1 = &bombs[1].x;
    int* y1 = &bombs[1].y;

    if (*x0 == row && *y0 == col) {
        *found = true;
    }
    else if (*x1 == row && *y1 == col) {
        bombs[1].found = true;
        *found = true;
    }

    }
void update_known_info(int row, int col, int bomb_info[][DIM], int known[][DIM]) {
    known[row][col] = bomb_info[row][col];

}

void start_game(struct locations* bombs, int bomb_location_info[][DIM],int moves, int size_of_grid, int players_info[][DIM], int no_of_bombs){
int bombs_found = 0;
    int counter = 1;

    enum game_status  {on, gameover};
    enum game_status status = on;
    bool found;
    display(players_info, size_of_grid);
    while (status == on) {

        int col;
        int row;
        char colinput;
        char rowinput;
do{
         printf("\nEnter Row : ");
         rowinput = get_user_char();
}while(rowinput!='A'&& rowinput!='B' && rowinput!='C'&& rowinput!='D');
      do{  printf("\nEnter Column : ");
        colinput = get_user_char();
      }while(colinput!='A'&& colinput!='B' && colinput!='C'&& colinput!='D');
        row = rowinput - 'A';
        col = colinput - 'A';

        found = false;
        check_found(row, col, bombs, size_of_grid, &found);

        if (found == true) {
            status = gameover;
            display(players_info, size_of_grid);
            printf("\n-----------BOOM-----GAME OVER!");
        }
        update_known_info(row, col, bomb_location_info, players_info);

        counter++;
        moves++;
        printf("\nTries = #%d\n", moves);
        display(players_info, size_of_grid);
        if(moves==5){
            break;
        }
    }
    int loop_counter = 1;
    while (status == on) {
        int col;
        int row;
        char colinput;
        char rowinput;

        printf("\nWelcome to Phase 2\nFind Bomb %d now\n", loop_counter);
         do{
        printf("\nEnter Bomb Row : \n");
       rowinput = get_user_char();
         }while(rowinput!='A'&& rowinput!='B' && rowinput!='C'&& rowinput!='D');
       do{ printf("Enter Bomb Column : \n");
        colinput = get_user_char();
       }while(colinput!='A'&& colinput!='B' && colinput!='C'&& colinput!='D');
        row = rowinput - 'A';
        col = colinput - 'A';

        found = false;
        check_found(row, col, bombs, size_of_grid, &found);

        if (found == true) {
            bombs[loop_counter].found = true;
            if (row == 1 && col == 1) {
                players_info[row][col] = 'B';
            }
            else if (row == 2 && col == 3) {
                players_info[row][col] = 'B';
            }
            display(players_info, size_of_grid);
            bombs_found++;
        }
        else if (found == false){
            printf("\nNo Bomb Here - You Lost\n"
                   "------   Game Over     ------ \n");
            status = gameover;

        }
        loop_counter++;
        if (bombs_found == 2) {
            printf("\n----------\nCongratulations! you found the bombs!\n----------\n");
            status = gameover;
            break;
        }
        else if (loop_counter > 2) {
            printf("You we were not able to find the 2nd bombs");
            status = gameover;
            break;
        }

    }

}

char get_user_char() {
    char letter;
    scanf("%c", &letter);
    getchar();

    return letter;
}
void function(){
static int y = 3;
if(y>0){
    printf("Hello");
    y--;
}
}
