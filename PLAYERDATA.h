#pragma once
#include <string>
#include <vector>


class PLAYERDATA
{
private:
	
	std::string _name;
	char _symbol;
	unsigned int _numplayers;
	

public:

	PLAYERDATA();
	PLAYERDATA(std::string, char, int);

	//getter
	std::string getname() const { return _name; }
	char getsymbol() const { return _symbol; }
	int getnumplayers() const { return _numplayers;  }
	
};

