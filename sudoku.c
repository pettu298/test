/*
 * Sudoku Solver.
 */

#include <stdio.h>

 //Indices representing rows in array, columns are represented with numbers
 #define A 0
 #define B 1
 #define C 2
 #define D 3
 #define E 4
 #define F 5
 #define G 6
 #define H 7
 #define J 8

 //Values in array are 1-9 with -1 as unknown.

typedef struct board board;
struct board{
	int array[9][9];
};

board* create_empty_board(){
	board* the_board;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			the_board->array[i][j] = -1;
		}
	}
	return the_board;
}

void print_board(board* the_board){
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			printf("%i ", the_board->array[i][j]);
		}
	}
}


 int main(){
 	board* the_board = create_empty_board();
 	print_board(the_board);
 	return 0;
 }