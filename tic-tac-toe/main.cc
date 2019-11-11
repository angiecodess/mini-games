#include <iostream>
#include "tictactoe.h"
  
int main() {
	TicTacToe Game;
	Game.drawBoard();
	Game.setup();
	do {
		Game.printTurn();
		Game.drawBoard();
	}
	while (!Game.winner() && !Game.fullBoard());
	return 0;
}

