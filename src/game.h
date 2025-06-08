#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

enum PieceType {
  Pawn = 1, Knight = 2, Bishop = 3, Rock = 4, Queen = 5, King = 6
};

enum Team {
  White, Black,
};

typedef struct {
  enum PieceType type;
  int col, row;
  enum Team team;
} Piece;

Piece *board[BOARD_WIDTH][BOARD_HEIGHT];

Piece* get_piece(int file, int rank);
void check_piece_movement(char* command);
void initialize_board();
int char_to_int(const char c);
int file_to_int(const char f);
  
#endif
