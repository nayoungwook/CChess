#include "game.h"

int get_command_size(char* command){
  int result = 0;

  while(*(command + result) != '\0'){
    result++;
  }
  
  return result;
}

int char_to_int(const char c){
  return c - 48;
}

int file_to_int(const char f){
  return f - 96;
}

Piece* get_piece(int file, int rank){
  if(file < 1 || file > BOARD_WIDTH || rank < 1 || rank > BOARD_HEIGHT)
    return NULL;

  return board[file][rank];
}

void check_piece_movement(char* command){
  int command_size = get_command_size(command);

  Piece* target_position = NULL;
  int piece_file = -1, piece_rank = -1;

  int i;
  
  if(command_size == 2){ // for pawn movement
    int file = file_to_int(command[0]);
    int rank = char_to_int(command[1]);
    
    target_position = get_piece(file, rank);
    
    for(i=0; i<2; i++){
      Piece* p = get_piece(file, rank - (i + 1));
      if(p != NULL){
	if(p->type == Pawn){
	  piece_file = file;
	  piece_rank = rank - (i + 1);
	}
      }
    }

    if(abs(piece_rank - rank) == 2){
      if(!(piece_rank == 7 || piece_rank == 2)){
	printf("You can\'t move pawn two step execept for beginning.\n");
	return;
      }
    }
    
    if(piece_file == -1){
      printf("Unable to move because there are no pawn!\n");
      return;
    }
    
    if(board[piece_file][piece_rank] != NULL){
      if(target_position == NULL){
	board[file][rank] = board[piece_file][piece_rank];
	board[piece_file][piece_rank] = NULL;
      }
    }
  }
}

void initialize_board(){
  int i, j;

  for(i=1; i<=BOARD_HEIGHT; i++){
    for(j=1; j<=BOARD_WIDTH; j++){
      board[j][i] = NULL;

      if(i == 2 || i == 1){
	board[j][i] = (Piece*) malloc(sizeof(Piece));
	board[j][i]->team = White;
      }

      if(i == 8 || i == 7){
	board[j][i] = (Piece*) malloc(sizeof(Piece));
	board[j][i]->team = Black;
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
