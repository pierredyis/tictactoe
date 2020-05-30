#include "TICTACTOE.h"
#include "PLAYERDATA.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <tuple>
#include <Windows.h>


#define TRUE 1






using namespace std;

TICTACTOE::TICTACTOE() {
	for (unsigned int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			Tile[i][j] = '-';

	_numPlayers.reserve(6);
	//_moves.reserve(15);
	memset(arr, 0, size(arr));
}

void TICTACTOE::INTRO(void) {

	system("cls");
	cout << "\n****\t******WELCOME PLAYERS******\t****" << endl;
	cout << "\n\tLet's play TICTACTOE." << endl;
	
}

int TICTACTOE::_getDimensions(string tile, int min, int max) {
	bool choice= TRUE;
	int dimension;
	cout << "\n\tEnter the " << tile << " dimension(min" << min << "x" << min << ",max" << max << "x" << max << "):";
	while (choice) {
		cout << "\n\t" << tile << ": ";
		if (!(cin >> dimension) || dimension < min || dimension > max) {
			cout << "\n\tINVALID DATA!!";
			choice = TRUE;
			cin.ignore(10, '\n');
		}
		else choice = false;
	}

	return dimension;
}

void TICTACTOE::_drawBoard(int x, int y, char sym) {

	system("cls");
	HANDLE hconsole;
	vector<PLAYERDATA> pdata;

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 
	Tile[x][y] = sym;

	cout << "\n\t";
	for (int j = 0; j <=_xtile; j++) {

		if (j == 0) {
			for (int i = 1; i <= _ytile; i++) {
				cout << "   " << i << " ";
				if (i == _ytile) cout << "\n\t";
			}
		}
		for (int i = 0; i < _ytile; i++)
		{
			cout << " ----"; 
			if (_ytile == (i+1)) cout <<"\n\t";
		}
		if (j <_ytile) {
			for (int i = 0; i <_ytile; i++) {
				if (i == 0) cout << j + 1;
				SetConsoleTextAttribute(hconsole, 7); 
				cout << "| ";
						SetConsoleTextAttribute(hconsole, 6);
					cout << Tile[j][i];
				
				SetConsoleTextAttribute(hconsole, 7);
				cout << " |";

			}
		}
		cout <<"\n\t";
	}
}

void TICTACTOE::inputData(int playernum) {
	
	_xtile =_getDimensions("the x/y",3,9);
	_ytile = _xtile;
	//_ytile = _getDimensions('y',3,15);
	_drawBoard(0,0, '-');
	
}


bool TICTACTOE::_checkVictory(int x, int y, char sym) {

	int  a, b, c, d, max = _xtile;
	bool row = false , col=false, l_angle=false, r_angle=false;
	
	if (_xtile < _ytile) max = _ytile;

	if ((x - y) < 0) {
		a = 0; b = y - x; max = y;
	}
	else if ((x - y) > 0) {
		a = x - y; b = 0; max = x;
	}
	else a = b = 0;

	if ((x + y) < (_ytile - 1)) {
		c = 0; d = x + y;
	}
	else if ((x + y) > (_ytile - 1)) {
		c = (x + y) - (_ytile - 1); d = (_ytile - 1);
	}
	else { c = 0; d = (_ytile - 1); }


	
	memset(arr, 0, size(arr));

	// top right to left bottom diagonal checking
	for (unsigned int i = 0; i < max; i++) {

		arr[0][0] = (i + c);		arr[0][1] = d - i;
		arr[1][0] = (i + c + 1);	arr[1][1] = (d - 1 - i);
		arr[2][0] = (i + c + 2);	arr[2][1] = (d - i - 2);

		if (Tile[arr[0][0]][arr[0][1]] ==sym)
			check[0] = TRUE;
		else check[0] = false;

		if (Tile[arr[1][0]][arr[1][1]] ==sym)
			check[1] = TRUE;
		else check[1] = false;

		if (Tile[arr[2][0]][arr[2][1]] ==sym)
			check[2] = TRUE;
		else check[2] = false;

		if ((check[0] + check[1] + check[2]) == 2) {
			for (unsigned int loop = 0; loop < 3; loop++) {
				if (!check[loop] && Tile[arr[loop][0]][arr[loop][1]] == '-')
					_moves.emplace_back(arr[loop][0], arr[loop][1], sym);
			}
		}
		//cout << "\n\tRDIAG  " << x << " " << y << "\t" << arr[0][0] <<" " << arr[0][1] << ": " << Tile[arr[0][0]][arr[0][1]]  << "\t" << arr[1][0] << " " << arr[1][1] <<": " << Tile[arr[1][0]][arr[1][1]]<<"\t" << arr[2][0] << " " << arr[2][1] << ": " << Tile[arr[2][0]][arr[2][1]] << endl;

		//Sleep(3000);

		if (check[0] && check[1] && check[2]) {
			r_angle = TRUE; 
			cout << "rdiag TRUE" << endl;// break;
		}
		//else r_angle = false;
	}
	
	memset(arr, 0, size(arr));

	for (unsigned int i = 0; i < max; i++) {
		arr[0][0] = (i + a);		arr[0][1] = (i + b);
		arr[1][0] = (i + a + 1);	arr[1][1] = (i + b + 1);
		arr[2][0] = (i + a + 2);	arr[2][1] = (i + b + 2);

		if (Tile[arr[0][0]][arr[0][1]] == sym)
			check[0] = TRUE;
		else check[0] = false;

		if (Tile[arr[1][0]][arr[1][1]] == sym)
			check[1] = TRUE;
		else check[1] = false;

		if (Tile[arr[2][0]][arr[2][1]] == sym)
			check[2] = TRUE;
		else check[2] = false;

		if ((check[0] + check[1] + check[2]) == 2) {
			for (unsigned int loop = 0; loop < 3; loop++) {
				if (!check[loop] && Tile[arr[loop][0]][arr[loop][1]] == '-')
					_moves.emplace_back(arr[loop][0], arr[loop][1], sym);
			}
		}
		//cout << "\n\tLDIAG  " << x << " " << y << "\t" << arr[0][0] << " " << arr[0][1] << ": " << Tile[arr[0][0]][arr[0][1]] << "\t" << arr[1][0] << " " << arr[1][1] << ": " << Tile[arr[1][0]][arr[1][1]] << "\t" << arr[2][0] << " " << arr[2][1] << ": " << Tile[arr[2][0]][arr[2][1]] << endl;

		//Sleep(3000);

		if (check[0] && check[1] && check[2]) {
			l_angle = TRUE;
			cout << "ldiag TRUE" << endl;// break;
		}
		//else l_angle = false;
	}
	
	memset(arr, 0, size(arr));

	for (unsigned int i = 0; i < _ytile; i++) {

		arr[0][0] = (x);		arr[0][1] = (i);
		arr[1][0] = (x);		arr[1][1] = (i + 1);
		arr[2][0] = (x);		arr[2][1] = (i + 2);

		if (Tile[arr[0][0]][arr[0][1]] ==sym)
			check[0] = TRUE;
		else check[0] = false;

		if (Tile[arr[1][0]][arr[1][1]] ==sym)
			check[1] = TRUE;
		else check[1] = false;

		if (Tile[arr[2][0]][arr[2][1]] ==sym)
			check[2] = TRUE;
		else check[2] = false;
		
		if ((check[0] + check[1] + check[2]) == 2) {
			for (unsigned int loop = 0; loop < 3; loop++)
				if (!check[loop] && Tile[arr[loop][0]][arr[loop][1]] == '-')
					_moves.emplace_back(arr[loop][0], arr[loop][1], sym);
			
		}
	//	cout << "\n\tROWDIAG  " << x << " " << y << "\t" << arr[0][0] << " " << arr[0][1] << ": " << Tile[arr[0][0]][arr[0][1]] << "\t" << arr[1][0] << " " << arr[1][1] << ": " << Tile[arr[1][0]][arr[1][1]] << "\t" << arr[2][0] << " " << arr[2][1] << ": " << Tile[arr[2][0]][arr[2][1]] << endl;

		//Sleep(3000);
	//	cout << "\n\t" << check[0] << "\t" << check[1] << "\t" << check[2] << endl;
		if (check[0] && check[1] && check[2]) {
			row = TRUE; 
			cout << "rrow TRUE" << endl;// break;
		}
		//else row = false;
	}
	
	memset(arr, 0, size(arr));
	for (unsigned int i = 0; i < _xtile; i++) {

		arr[0][0] = (i);			arr[0][1] = (y);
		arr[1][0] = (i + 1);		arr[1][1] = (y);
		arr[2][0] = (i + 2);		arr[2][1] = (y);

		if (Tile[arr[0][0]][arr[0][1]] ==sym)
			check[0] = TRUE;
		else check[0] = false;

		if (Tile[arr[1][0]][arr[1][1]] ==sym)
			check[1] = TRUE;
		else check[1] = false;

		if (Tile[arr[2][0]][arr[2][1]] ==sym)
			check[2] = TRUE;
		else check[2] = false;

		if ((check[0] + check[1] + check[2]) == 2) {

			for (unsigned int loop = 0; loop < 3; loop++) {
				if (!check[loop]&& Tile[arr[loop][0]][arr[loop][1]]=='-')
					_moves.emplace_back(arr[loop][0], arr[loop][1], sym);
			}
		}
		//cout << "\n\tCOLDIAG  " << x << " " << y << "\t" << arr[0][0] << " " << arr[0][1] << ": " << Tile[arr[0][0]][arr[0][1]] << "\t" << arr[1][0] << " " << arr[1][1] << ": " << Tile[arr[1][0]][arr[1][1]] << "\t" << arr[2][0] << " " << arr[2][1] << ": " << Tile[arr[2][0]][arr[2][1]] << endl;

		//Sleep(3000);
			if (check[0] && check[1] && check[2]) {
				col = TRUE;
				cout << "col TRUE" << endl;// break;
			}
			//else col = false;
		}

	if (col == TRUE || row == TRUE || l_angle == TRUE || r_angle == TRUE) 
			return TRUE;
		else return false;	
}


bool TICTACTOE::_playermoves(int &xd, int &yd, char sym) {

	bool found = false;
	
	int size = _moves.size();
	if (size != 0) {
		for (unsigned int i = 0; i < size; i++) {

			if (get<2>(_moves[i]) == sym) {
				xd = get<0>(_moves[i]) + 1;
				yd = get<1>(_moves[i]) + 1;

				_moves.erase(_moves.begin() + i);
				i--;
				found = true;
				break;
			}
			else found = false;

		}
	}
	return found;
}

	

void TICTACTOE::Play(vector<PLAYERDATA>& players) {

	bool isDone = false, isEqual = TRUE, found = false;
	int turn = 0;
	int x, y, ctr = 0;

	static default_random_engine generator(time(NULL));
	uniform_int_distribution<int>randomdimension(1,_xtile);
		
	for (int i = 0; i < players[0].getnumplayers(); i++)
		_numPlayers.push_back(i);//vector storage copy
		
	//shuffle the stored turns
	shuffle(_numPlayers.begin(), _numPlayers.end(), generator);
		
	cout << "\n\t"<<players[_numPlayers[turn]].getname() << "!! You go first!" <<endl;

	
	while (!isDone) {

		while (isEqual) {

			if (players[_numPlayers[turn]].getname() == "AI") {
				
				x = randomdimension(generator);
				y = randomdimension(generator);
				//cout << "\n\tBFORE PLAY x " << x << " y: " << y << "\tsize: "<<_moves.size()<<endl;
				//system("PAUSE");
				found = _playermoves(x, y, players[_numPlayers[turn]].getsymbol());
				//cout << "\n\tAFTERPLAY x " << x << " y: " << y << "\tsize: " << _moves.size() << endl;
				//system("PAUSE");
				if ((!found) && (!_moves.empty())) {
					x = (get<0>(_moves.back()))+1;
					y = (get<1>(_moves.back()))+1;
					_moves.pop_back();
					//cout << "\n\tENEMY\t" << x << "\t" << y<<"\tsize: " << _moves.size() << endl;
					//system("PAUSE");
					
				}
				
			}else {
				x = _getDimensions("x", 1, _ytile);
				y = _getDimensions("y", 1, _ytile);
			}
			
			if (Tile[x-1][y-1] != '-') {
				cout << "\n\tOCCUPIED" << endl;
				isEqual = TRUE;
			}
			else isEqual = false;
			
		}
		Sleep(1000);
		//marking the board
		_drawBoard(x-1, y-1, players[_numPlayers[turn]].getsymbol());

		//checking the board
		isDone = _checkVictory(x-1, y-1,players[_numPlayers[turn]].getsymbol());
		
		
		if (isDone) cout << "\n\t" << players[_numPlayers[turn]].getname() <<"(symbol: "<<players[_numPlayers[turn]].getsymbol()<<")wins!!!" << endl;
		
		for (unsigned int i = 0; i < _xtile; i++)
			for (int j = 0; j < _xtile; j++) 
				if (Tile[i][j] == '-') break;
				else if (i ==( _xtile-1) && j == (_xtile-1)) {
					isDone = TRUE;
					cout << "\n\tNO WINNER!!" << endl;
				}
			

				
		if (turn == (players[0].getnumplayers())-1) turn = 0;
		else turn++;

		isEqual = TRUE;
	}
	   
}