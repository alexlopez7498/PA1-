#pragma once


#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Node.h"

using std::string;

class Data
{
public:

	Data() {}

	Data(string name, string desc);
	string getName();
	string getDesc();
	void setName(string newName);
	void setDesc(string newDesc);
	/*************************************************************
* Function:	void read(std::fstream& infile, Data& data);
* Description: The function read from the classList.csv file
* Input parameters: std::fstream& infile, Data& data
* Returns: none
* Preconditions: std::fstream& infile, Data& data
* Postconditions: none
*************************************************************/
	void read(std::fstream& infile, Data& data);
	/*************************************************************
	* Function:	void readMaster(std::fstream& infile, Data& data);
	* Description: The function read from the master.csv file
	* Input parameters: std::fstream& infile, Data& data
	* Returns: none
	* Preconditions: std::fstream& infile, Data& data
	* Postconditions: none
	*************************************************************/
	void readMaster(std::fstream& infile, Data& data);
	/*************************************************************
	* Function:	Data adv_tokenizer(string s, char del);
	* Description: The function splits the line between each comma and stores them into the data
	* Input parameters: string s, char del
	* Returns: Data
	* Preconditions: string s, char del
	* Postconditions: return Data
	*************************************************************/
	Data adv_tokenizer(string s, char del);
private:
	string mName;
	string mDesc;
};

std::fstream& operator<< (std::fstream& inStream, Data& data);
std::fstream& operator>> (std::fstream& inStream, Data& data);