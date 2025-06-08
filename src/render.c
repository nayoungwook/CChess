#include "render.h"

void render_board(Piece *board[BOARD_WIDTH][BOARD_HEIGHT]){
  int i, j;

  printf("\n");
  
  for(i=BOARD_HEIGHT; i>0; i--){
    printf("\n%d", i);

    for(j=1; j<=BOARD_WIDTH; j++){
      Piece *piece = board[j][i];
      
      if(piece == NULL){
	if((i + j) % 2 == 0){
	  printf("■");
	}else{
	  printf("□");
	}
	
      }else{
	if(piece->team == Black){
	  if(piece->type == Pawn){
	     printf("♟");
	  }
	  if(piece->type == Rock){
	    printf("♜");
	  }
	  if(piece->type == Bishop){
	    printf("♝");
	  }
	  if(piece->type == Knight){
	    printf("♞");
	  }
	  if(piece->type == Queen){
	    printf("♛");
	  }
	  if(piece->type == King){
	    printf("♚");
	  }
	}

	if(piece->team == White){
	  if(piece->type == Pawn){
	     printf("♙");
	  }
	  if(piece->type == Rock){
	    printf("♖");
	  }
	  if(piece->type == Bishop){
	    printf("♗");
	  }
	  if(piece->type == Knight){
	    printf("♘");
	  }
	  if(piece->type == Queen){
	    printf("♕");
	  }
	  if(piece->type == King){
	    printf("♔");
	  }
	}
      }

      printf(" ");
    }
  }
  
  printf("\n ");
  for(i=1; i<=BOARD_WIDTH; i++){
    printf("%c ", i + 96);
  }

}
