#include "main.h"

int main(){
  printf("Welcome to CChess.");

  initialize_board();


  while(1){
    render_board(board);

    char* input = (char*) malloc(sizeof(char)*20);
    printf("\n>>");
    scanf("%s", input);

    check_piece_movement(input);

    if(!strcmp(input, "stop")){
      break;
    }
  }
  
  return 0;
}
