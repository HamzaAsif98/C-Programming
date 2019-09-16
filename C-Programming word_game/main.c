#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "word_game.h"
int main()
{
char  current_letters[] = {'b','e','l','l'};
char target_letters[] = {'c', 'o', 'a', 't'};

int position_of_cursor = 0;
const int NUMBER_OF_LETTERS = 4;
bool game_finished = false;
int number_of_letter_changes = 0;
int*pPosition_of_cursor=&position_of_cursor;
char*pLetters=&current_letters[0];
int position = position_of_cursor;
char*pStart_letters=&current_letters;
char*pCurrent_letters=&current_letters;
char*pTarget_letters=&target_letters;
int size_of_array=NUMBER_OF_LETTERS;
const int size_of_word=NUMBER_OF_LETTERS;
char new_letter;
int max;

//display_game_state (current_letters,target_letters, NUMBER_OF_LETTERS, position_of_cursor ,number_of_letter_changes);
//move_cursor_right(pPosition_of_cursor,max);
//move_cursor_left(pPosition_of_cursor,max);
//change_letter(pLetters,position,new_letter,max);
//compare_letters(pStart_letters,pTarget_letters,size_of_array);
start_game(pCurrent_letters,pTarget_letters,size_of_word);


}
