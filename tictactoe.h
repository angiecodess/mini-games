#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
	char pos[9];
	int curplayer = 1;
	int totalturns;
	bool computer;
	public:
	TicTacToe();
	void printTurn();
	void humanMove();
	void computerMove();
	bool winner();
	bool fullBoard();
	void setup();
	void drawBoard();
};

#endif


