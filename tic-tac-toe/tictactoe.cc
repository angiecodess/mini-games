#include "tictactoe.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


TicTacToe::TicTacToe() {
	srand(time(0));
	totalturns = 0;
	for(int i = 0; i < 9; ++i) {
		pos[i] = ' ';
	}
}

void TicTacToe::setup() {
	int x;
	string s;
	cout << "Let's play TicTacToe!" << endl;
	while(true) {
		cout << "1 or 2 players?" << endl;
		cin >> s;
		istringstream ss{s};
		if (ss >> x && (x == 1 || x == 2)) break;
		cout << "Invalid input. Please try again." << endl;
	}
	if (x == 1) {
		computer = true;
	} else {
		computer = false;
	}
}

void TicTacToe::drawBoard() {
	cout << endl;
	cout << " " << pos[0] << " | " << pos[1] << " | " << pos[2] << " " << endl;
	cout <<"___|___|___" << endl;
	cout <<"   |   |   " << endl;
	cout << " " << pos[3] << " | " << pos[4] << " | " << pos[5] << " " << endl;
	cout <<"___|___|___" << endl;
	cout <<"   |   |   " << endl;
	cout << " " << pos[6] << " | " << pos[7] << " | " << pos[8] << " " << endl;
	if(curplayer == 1 && totalturns != 0) {
		cout << endl;
		cout << "-----------------------------------" << endl;
	}
}

void TicTacToe::printTurn() {
	cout << endl;
	cout << "Player " << curplayer << "'s turn." << endl;
	if (curplayer == 1) {
		humanMove();
	} else {
		if(computer == true) {
			computerMove();
		} else {
			humanMove();
		}
	} 
}
	

void TicTacToe::humanMove() {
	int i;
	string s;
	while(true) {
		cout << "Enter your move (1 - 9)." << endl;
		cin >> s;
		istringstream ss{s};
		if (ss >> i && i > 0 && i < 10 && pos[i - 1] == ' ') break;
		cout << "Invalid input. Please try again." << endl;
	} if (curplayer == 1) {
		pos[i - 1] = 'X';
		curplayer = 2; 
	} else {
		pos[i - 1] = 'O';
		curplayer = 1;
	} ++totalturns;
}

void TicTacToe::computerMove() {
	int i;
	do {
		i = rand() % 9;
	}
	while(pos[i] != ' ');
	pos[i] = 'O';
	curplayer = 1;
	++totalturns;
}

bool TicTacToe::winner() {
	int board[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	for (int i = 0; i < 8; ++i) {
		if(pos[board[i][0]] != ' ' && (pos[board[i][0]] == pos[board[i][1]]) &&
			(pos[board[i][1]] == pos[board[i][2]])) {
			if (curplayer == 1) {
				cout << "We have a winner! Player 2 wins!" << endl;
			} else {
				cout << "We have a winner! Player 1 wins!" << endl;
			}
			return true;
		}
	} return false;
}

bool TicTacToe::fullBoard() {
	if (totalturns == 9) {
		cout << "It's a tie! Good Game." << endl;
		return true;
	} return false;
}
