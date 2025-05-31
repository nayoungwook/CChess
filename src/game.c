#include "game.h"

void initialize_board(){
  int i, j;

  for(i=1; i<=BOARD_HEIGHT; i++){
    for(j=1; j<=BOARD_WIDTH; j++){
      board[j][i] = NULL;

      if(i == 2 || i == 1){
	board[j][i] = (Piece*) malloc(sizeof(Piece));
	board[j][i]->team = Black;
      }

      if(i == 8 || i == 7){
	board[j][i] = (Piece*) malloc(sizeof(Piece));
	board[j][i]->team = White;
      }
      
      if(i == 2 || i == 7){
	board[j][i]->type = Pawn;
      }

      if(i == 1 || i == 8){
	if(j == 1 || j == 8){
	  board[j][i]->type = Rock;
	}
	if(j == 2 || j == 7){
	  board[j][i]->type = Bishop;
	}
	if(j == 3 || j == 6){
	  board[j][i]->type = Knight;
	}
	
	if((i == 1 && j == 4) || (i == 8 && j == 5)){
	  board[j][i]->type = Queen;
	}
	if((i == 1 && j == 5) || (i == 8 && j == 4)){
	  board[j][i]->type = King;
	}
      }

      if(board[j][i] != NULL){
	board[j][i]->col = j;
	board[j][i]->row = i;
      }
    }
  }
  
}
