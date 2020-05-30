#include <iostream>
#include "TICTACTOE.h"
#include "PLAYERDATA.h"

using namespace std;

void playerform(vector<PLAYERDATA>&);

int main() {

	vector<PLAYERDATA> players;
	players.reserve(6);
	bool isDone = true;
	playerform(players);

	

	while (isDone ) {
		TICTACTOE game;
		game.inputData(players[0].getnumplayers());
		game.Play(players);
		
		
		cin.ignore(10,'\n');
		cout << "\n\n\t PLAY AGAIN? Press 'y' if yes :";
		
		if (toupper(cin.get()) == 'Y')
			isDone = true;
		else isDone = false;
	}
	//system("PAUSE");
	return 0;
}


void playerform(vector<PLAYERDATA>& newplayers) {

	string name; 
	bool choice = true;
	char symbol;
	int numplayers;

	while (choice) {
		cout << "\n\n\tInput number of players(min:2,max:5): ";
		cin >> numplayers;	
		//cin.ignore();

		if ((numplayers < 2 || numplayers>5)&&!cin.good()) {
			cout << "\tInvalid data!!" << endl;
			choice = true;
			cin.clear();
			cin.ignore(10, '\n');
		}
		else choice = false;
	}

	//ENTER NAMES OF PLAYERS
	cout << "\n\tPlease enter players name('AI' for computer random generated): " << endl;
	for (int i = 0; i < numplayers; i++) {
		cout << "\n\tPlayer " << i + 1 << ": ";
		cin >> name;
	//	cin.ignore();
		cout << "\n\tEnter your symbol: ";
		cin >> symbol;
		cin.ignore();
		PLAYERDATA players(name, symbol, numplayers);
		newplayers.push_back(players);
	}
}