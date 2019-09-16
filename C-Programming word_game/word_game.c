#include <stdio.h >
#include <stdbool.h>


void display_game_state(char* pCurrent_letters,char* pTarget_letters,const int NUMBER_OF_LETTERS, const int cursor_position, const int number_of_letter_changes)
{

    /*  	printf("---Game State ---\n");
    *  	printf ("\n%p", pCurrent_letters);
    *  	printf ("\n%c", *pCurrent_letters);
    *  	pCurrent_letters = pCurrent_letters + 1;
    *     printf ("\n%c\n", *pCurrent_letters);
    *     pCurrent_letters = pCurrent_letters - 1;
    *     for(int loop = 0; loop < sizeof(pCurrent_letters); loop++)
    *           printf("%c", pCurrent_letters[loop]);
    *           printf("\n%p",cursor_position);
    *
    *     const char DASH = '-';
    *     const char SPACE =' ' ;
    *
    *     printf ("\n%c", SPACE);
    *     printf ("\n%c\n", DASH);
    *      for(int i = 0; i< cursor_position; i++){
    *           printf("%c",SPACE);
    *     }
    *         printf("%c",DASH);
    */

        int loop;
        printf("\n\n--------Changes---------\n\n");
        printf("Target : ");
   for (loop=0;loop < (sizeof (pTarget_letters)) ;loop++) {
      printf("%c%",pTarget_letters[loop]);

  }
  printf("\n\n---------\n\n");
   for (loop=0;loop < (sizeof (pCurrent_letters));loop++) {
      printf("%c%",pCurrent_letters[loop]);
      if(pCurrent_letters[loop]!=pTarget_letters[loop]){
      number_of_letter_changes==0;
 }
  else number_of_letter_changes;
  }
  printf("\nChanges : %d%",number_of_letter_changes);


}
void move_cursor_right(int* pPosition_of_cursor, const int max)
{ if(*pPosition_of_cursor<max){
    *pPosition_of_cursor=*pPosition_of_cursor+1;
}
}
void move_cursor_left(int* pPosition_of_cursor, const int max)
{   if(*pPosition_of_cursor<max){
    *pPosition_of_cursor=*pPosition_of_cursor-1;
}
}
void change_letter(char* pLetters, int position, char new_letter, int max)
{
char* plocation_of_letter_to_change = pLetters + position;
*plocation_of_letter_to_change=new_letter;
}
bool compare_letters(char* pStart_letters, char* pTarget_letters, int size_of_array)
{
	printf("\nCompare Letters \n");

    int i=0;
while(i<size_of_array){

    printf("%c%",pStart_letters[i]);
    printf("%c%\n",pTarget_letters[i]);
    i++;}
    i=3;
        if(pStart_letters[i]==pTarget_letters[i]){
    return true;
}else
    return false;

    return true;
}

char get_user_char() {
    //1. We create the output variable with the value the user has input by keyboard
    char res = getchar();

    //2. We discard any extra character the user has input by keyboard
    bool finish = false;
    char dummy_char = ' ';

    while (finish == false) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = true;
    }

    //3. We return the output variable
    return res;
}


void start_game(char *pCurrent_letters,char* Target_letters,const int size_of_word){
    int position_of_cursor = 0;
    bool game_finished = false;
    int number_of_letter_changes = 0;
    int correctcount;

    display_game_state (pCurrent_letters,Target_letters, size_of_word, position_of_cursor,number_of_letter_changes);
  int tries=1;
  char h;
do{

    printf("\n\nEnter Command : ");
    h=get_user_char();
    tries++;
    if (h=='<'){
            move_cursor_left(&position_of_cursor, size_of_word);
            display_game_state(pCurrent_letters, Target_letters, size_of_word, position_of_cursor, number_of_letter_changes);

        }else if (h == '>'){
            move_cursor_right(&position_of_cursor, size_of_word);
            display_game_state(pCurrent_letters, Target_letters, size_of_word, position_of_cursor, number_of_letter_changes);

        }else if (h >= 'a' && h <= 'z'){
            change_letter(pCurrent_letters, position_of_cursor, h, size_of_word);
            position_of_cursor++;
            compare_letters(pCurrent_letters,Target_letters,size_of_word);
            number_of_letter_changes++;
            display_game_state(pCurrent_letters, Target_letters, size_of_word, position_of_cursor, number_of_letter_changes);
             if(h==Target_letters[0]||h==Target_letters[1]||h==Target_letters[2]||h==Target_letters[3]){correctcount++;}
             }
        else{
            printf("\n< OR > || a-z\n");
        }
        if (compare_letters(pCurrent_letters,Target_letters,size_of_word)!=false){
        printf("Congratulation you won you guessed all words");
        printf("\nCorrect Character You Guessed are %d ",correctcount);
        tries<size_of_word*2;
        }
        if(tries>=size_of_word*2){
        printf("Oh Sorry you are out of tries .");
    }

}while(tries<=size_of_word*2 && compare_letters(pCurrent_letters,Target_letters,size_of_word)!=true);

    }





