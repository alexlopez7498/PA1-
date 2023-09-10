#pragma once

#include "Data.h"
#include "Node.h"

#include "menu.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>


class menu
{
public:
	/*************************************************************
	* Function:	menu();
	* Description: The function sets the menu
	* Input parameters: none
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	menu();
	/*************************************************************
	* Function:	~menu();
	* Description: The function destructor destroys the menu when it goes out of scope
	* Input parameters: none
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	~menu();
	/*************************************************************
	* Function:	void run_app();
	* Description: The function runs the app and acts as main to run the code together
	* Input parameters: none
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void run_app();

private:
	/*************************************************************
	* Function:	void displayMenu();
	* Description: The function displays the menu
	* Input parameters: none
	* Returns: none
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void displayMenu();
	void gameRules();
};

struct Profile
{
	std::string name;
	int points;
};

Profile tokenizer(string s, char del);