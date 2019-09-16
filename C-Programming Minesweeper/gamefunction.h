#include <stdbool.h>

#define DIM 4
#define UNKNOWN -1
#define BOMB

struct locations {

    int x;
    int y;
    bool found;

};

void display(int knownLocationInfo [][DIM], int size);

void updateKnown( int row, int col, int bombInfo [][DIM], int known[][DIM]);

void checkFound (int row, int col, struct locations BOMB[], int size, bool* found);

void start_game(struct locations *   bombs, int bomb_location_info[][DIM],int moves,
                int size_of_grid, int players_info[][DIM], int no_of_bombs);

void function();
