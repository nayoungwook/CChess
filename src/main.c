#include "main.h"

int main(){
  printf("Welcome to CChess.");

  initialize_board();

  render_board(board);

  char* input = (char*) malloc(sizeof(char)*20);
  printf("\n>>");
  scanf("%s", input);
  
  return 0;
}
