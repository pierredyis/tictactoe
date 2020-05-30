#pragma once
#include <string>
#include <vector>
#include <tuple>
#include "PLAYERDATA.h"

using namespace std;
typedef tuple<int, int, char> move_tuple;

class TICTACTOE {
private:
	
	// NUMBER OF PLAYERS
	vector<int> _numPlayers;
	
	//BOARD DIMENSION
	unsigned int _xtile;
	unsigned int _ytile;

	//AI 

	int arr[3][2];
	bool check[2];
	
vector<move_tuple> _moves;

	//BOARD TILES ARRAY
	char Tile[15][15];
	
	int _getDimensions(string,int,int);
	void _drawBoard(int,int, char);
	bool _checkVictory(int, int, char);
	bool _playermoves( int&, int&, char);

public:
	
	TICTACTOE();
	void INTRO(void);
	void inputData(int);
	void Play(vector<PLAYERDATA>&);
	

};