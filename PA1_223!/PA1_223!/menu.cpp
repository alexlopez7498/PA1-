#include "Data.h"
#include "List.h"
#include "Node.h"
#include "menu.h"

menu::menu()
{

}
menu::~menu()
{

}

void menu::displayMenu()
{
	std::cout << "1. Game Rules" << std::endl;
	std::cout << "2. Play Game" << std::endl;
	std::cout << "3. Load Previous Game" << std::endl;
	std::cout << "4. Add Command" << std::endl;
	std::cout << "5. Remove Command" << std::endl;
	std::cout << "6. Exit" << std::endl;
}

void menu::gameRules()
{
	std::cout << "The objective of the game is to match Linux commands to appropriate descriptions of those commands." << std::endl;
	std::cout << "If a command is matched, then the player earns 1 point." << std::endl;
	std::cout << "If the command is not matched, then the player loses a point." << std::endl;
	std::cout << "The player selects the number of match questions at the beginning of the game. " << std::endl;
	std::cout << "he game continue until the number is reached." << std::endl;
}

void menu::run_app()
{
	srand((unsigned)time(NULL));
	string commandtoAdd;
	string commandtoRemove;
	string descprition;
	string line;
	string playerName;
	string newPlayer;
	Profile players[100] = { "",0 };
	int choice = 0;
	int choice2 = 0;
	int check3 = 0;
	int score = 0;
	int x = 0;
	int i = 0;
	int y = 0;
	int arraySize = 0;
	int check2 = 0;
	int check = 0;
	int number = 0;
	int random = 0;
	int random2 = 0;
	int random3 = 0;
	int saveRan = 0;
	int saveRan2 = 0;
	int saveRan3 = 0;
	int arrayCount[41] = {};
	int arrayRan[3] = {};
	std::fstream classList;
	std::fstream commands;
	std::fstream master;
	std::fstream profiles;
	Data h;
	Data saveResult;
	Data saveResult2;
	Data saveResult3;
	List<Data> commandList;
	Node<Data>* pCur = nullptr;
	Node<Data>* pPre = nullptr;
	Node<Data>* pTemp = nullptr;
	while (!commands.eof())
	{
		h.read(commands, h);
		if (h.getName() != "")
		{
			commandList.insertAtFront(h);
			arraySize++;
		}
		x++;
		Data myDataObject = commandList.getHeadPtr()->getData();
		master << myDataObject;
	}
	profiles.open("profiles.csv", std::fstream::in);
	while (std::getline(profiles, line))
	{
		players[i] = tokenizer(line, ',');
		i++;
	}
	profiles.close();
	x = 0;
	do
	{
		std::cout << "Which option would you like to choose?" << std::endl;
		displayMenu();
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			gameRules();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			pCur = commandList.getHeadPtr();
			do
			{
				check3 = 0;
				std::cout << "Enter your name" << std::endl;
				std::cin >> playerName;
				i = 0;
				while (players[i].name != "")
				{
					if (playerName == players[i].name)
					{
						system("cls");
						std::cout << "Name already exist" << std::endl;
						system("pause");
						system("cls");
						check3 = 1;
						break;
					}
					i++;
				}
				if (check3 == 0)
				{
					players[i].name = playerName;
				}
			} while (check3 == 1);

			;

			do
			{
				system("cls");
				std::cout << "How many questions would you like? (5-30)" << std::endl;
				std::cin >> number;
				system("cls");
			} while (number < 5 || number > 30);
			for (int f = 0; f < 41; f++)
			{
				arrayCount[f] = 0;
			}
			while (number != 0)
			{
				pCur = commandList.getHeadPtr();
				while (arrayCount[random] != 1)
				{
					random = 1 + (rand() % arraySize);
					arrayCount[random]++;
					if (arrayCount[random] == 1)
					{
						break;
					}
				}
				saveRan = random;
				while (random != 1)
				{
					random--;
					pCur = pCur->getNextPtr();
				}
				random = 0;
				std::cout << pCur->getData().getName() << std::endl;
				saveResult = pCur->getData();
				saveResult2 = saveResult;
				saveResult3 = saveResult;
				random = rand() % 3;
				if (random == 0)
				{
					std::cout << "1. " << pCur->getData().getDesc() << std::endl;
					do
					{
						random2 = 1 + (rand() % arraySize);
					} while (random2 == saveRan);
					saveRan2 = random2;
					pCur = commandList.getHeadPtr();
					while (random2 != 1)
					{
						random2--;
						pCur = pCur->getNextPtr();
					}
					std::cout << "2. " << pCur->getData().getDesc() << std::endl;
					do
					{
						random3 = 1 + (rand() % arraySize);
					} while (random3 == saveRan || random3 == saveRan2);
					pCur = commandList.getHeadPtr();
					while (random3 != 1)
					{
						random3--;
						pCur = pCur->getNextPtr();
					}
					std::cout << "3. " << pCur->getData().getDesc() << std::endl;
					std::cout << std::endl;
					std::cin >> choice2;
					system("cls");
					if (choice2 == 1)
					{
						score++;
						std::cout << "Correct! " << saveResult.getName() << " - " << saveResult.getDesc() << "  You have been awarded 1 point. Your point total is " << score << "." << std::endl;;
					}
					else
					{
						score--;
						std::cout << "Incorrect! " << saveResult.getName() << " - " << saveResult.getDesc() << " You have lost 1 point. Your point total is " << score << "." << std::endl;
					}
					system("pause");
					system("cls");
				}
				if (random == 1)
				{
					do
					{
						random2 = 1 + (rand() % arraySize);
					} while (random2 == saveRan);
					saveRan2 = random2;
					pCur = commandList.getHeadPtr();
					while (random2 != 1)
					{
						random2--;
						pCur = pCur->getNextPtr();
					}
					std::cout << "1. " << pCur->getData().getDesc() << std::endl;
					/*	pCur->setData(saveResult2);*/
					std::cout << "2. " << saveResult2.getDesc() << std::endl;
					do
					{
						random3 = 1 + (rand() % arraySize);
					} while (random3 == saveRan || random3 == saveRan2);
					pCur = commandList.getHeadPtr();
					while (random3 != 1)
					{
						random3--;
						pCur = pCur->getNextPtr();
					}
					std::cout << "3. " << pCur->getData().getDesc() << std::endl;
					std::cout << std::endl;
					std::cin >> choice2;
					system("cls");
					system("cls");
					if (choice2 == 2)
					{
						score++;
						std::cout << "Correct! " << saveResult2.getName() << " - " << saveResult2.getDesc() << "  You have been awarded 1 point. Your point total is " << score << "." << std::endl;;
					}
					else
					{
						score--;
						std::cout << "Incorrect! " << saveResult2.getName() << " - " << saveResult2.getDesc() << " You have lost 1 point. Your point total is " << score << "." << std::endl;
					}
					system("pause");
					system("cls");
				}
				if (random == 2)
				{
					do
					{
						random2 = 1 + (rand() % arraySize);
					} while (random2 == saveRan);
					saveRan2 = random2;
					pCur = commandList.getHeadPtr();
					while (random2 != 1)
					{
						random2--;
						pCur = pCur->getNextPtr();
					}
					std::cout << "1. " << pCur->getData().getDesc() << std::endl;
					do
					{
						random3 = 1 + (rand() % arraySize);
					} while (random3 == saveRan || random3 == saveRan2);
					pCur = commandList.getHeadPtr();
					while (random3 != 1)
					{
						random3--;
						pCur = pCur->getNextPtr();
					}
					std::cout << "2. " << pCur->getData().getDesc() << std::endl;
					//pCur->setData(saveResult3);
					std::cout << "3. " << saveResult3.getDesc() << std::endl;
					std::cout << std::endl;
					std::cin >> choice2;
					system("cls");
					system("cls");
					if (choice2 == 3)
					{
						score++;
						std::cout << "Correct! " << saveResult3.getName() << " - " << saveResult3.getDesc() << "  You have been awarded 1 point. Your point total is " << score << "." << std::endl;;
					}
					else
					{
						score--;
						std::cout << "Incorrect! " << saveResult3.getName() << " - " << saveResult3.getDesc() << " You have lost 1 point. Your point total is " << score << "." << std::endl;
					}
					system("pause");
					system("cls");
				}
				random2 = 0;
				random3 = 0;
				random = 0;
				saveRan = 0;
				saveRan2 = 0;
				saveRan3 = 0;
				number--;
			}
			players[i].points = score;
			i++;
			score = 0;
			break;
		case 3:
			system("cls");
			std::cout << "Enter an exisitng profile name." << std::endl;
			std::cin >> newPlayer;
			i = 0;
			while (i < 100)
			{
				if (newPlayer == players[i].name)
				{
					score = players[i].points;
					std::cout << "player was found. " << players[i].name << ", " << players[i].points << std::endl;
					system("pause");
					do
					{
						system("cls");
						std::cout << "How many questions would you like? (5-30)" << std::endl;
						std::cin >> number;
					} while (number < 5 || number > 30);

					while (number != 0)
					{
						pCur = commandList.getHeadPtr();
						while (arrayCount[random] != 1)
						{
							random = 1 + (rand() % arraySize);
							arrayCount[random]++;
							if (arrayCount[random] == 1)
							{
								break;
							}
						}
						saveRan = random;
						while (random != 1)
						{
							random--;
							pCur = pCur->getNextPtr();
						}
						random = 0;
						std::cout << pCur->getData().getName() << std::endl;
						saveResult = pCur->getData();
						saveResult2 = saveResult;
						saveResult3 = saveResult;
						random = rand() % 3; //change back
						if (random == 0)
						{
							std::cout << "1. " << pCur->getData().getDesc() << std::endl;
							do
							{
								random2 = 1 + (rand() % arraySize);
							} while (random2 == saveRan);
							saveRan2 = random2;
							pCur = commandList.getHeadPtr();
							while (random2 != 1)
							{
								random2--;
								pCur = pCur->getNextPtr();
							}
							std::cout << "2. " << pCur->getData().getDesc() << std::endl;
							do
							{
								random3 = 1 + (rand() % arraySize);
							} while (random3 == saveRan || random3 == saveRan2);
							pCur = commandList.getHeadPtr();
							while (random3 != 1)
							{
								random3--;
								pCur = pCur->getNextPtr();
							}
							std::cout << "3. " << pCur->getData().getDesc() << std::endl;
							std::cout << std::endl;
							std::cin >> choice2;
							system("cls");
							if (choice2 == 1)
							{
								score++;
								std::cout << "Correct! " << saveResult.getName() << " - " << saveResult.getDesc() << "  You have been awarded 1 point. Your point total is " << score << "." << std::endl;;
							}
							else
							{
								score--;
								std::cout << "Incorrect! " << saveResult.getName() << " - " << saveResult.getDesc() << " You have lost 1 point. Your point total is " << score << "." << std::endl;
							}
							system("pause");
							system("cls");
						}
						if (random == 1)
						{
							do
							{
								random2 = 1 + (rand() % arraySize);
							} while (random2 == saveRan);
							saveRan2 = random2;
							pCur = commandList.getHeadPtr();
							while (random2 != 1)
							{
								random2--;
								pCur = pCur->getNextPtr();
							}
							std::cout << "1. " << pCur->getData().getDesc() << std::endl;

							//pCur->setData(saveResult2);
							std::cout << "2. " << saveResult2.getDesc() << std::endl;
							do
							{
								random3 = 1 + (rand() % arraySize);
							} while (random3 == saveRan || random3 == saveRan2);
							pCur = commandList.getHeadPtr();
							while (random3 != 1)
							{
								random3--;
								pCur = pCur->getNextPtr();
							}
							std::cout << "3. " << pCur->getData().getDesc() << std::endl;
							std::cout << std::endl;
							std::cin >> choice2;
							system("cls");
							system("cls");
							if (choice2 == 2)
							{
								score++;
								std::cout << "Correct! " << saveResult2.getName() << " - " << saveResult2.getDesc() << "  You have been awarded 1 point. Your point total is " << score << "." << std::endl;;
							}
							else
							{
								score--;
								std::cout << "Incorrect! " << saveResult2.getName() << " - " << saveResult2.getDesc() << " You have lost 1 point. Your point total is " << score << "." << std::endl;
							}
							system("pause");
							system("cls");
						}
						if (random == 2)
						{
							do
							{
								random2 = 1 + (rand() % arraySize);
							} while (random2 == saveRan);
							saveRan2 = random2;
							pCur = commandList.getHeadPtr();
							while (random2 != 1)
							{
								random2--;
								pCur = pCur->getNextPtr();
							}
							std::cout << "1. " << pCur->getData().getDesc() << std::endl;
							do
							{
								random3 = 1 + (rand() % arraySize);
							} while (random3 == saveRan || random3 == saveRan2);
							pCur = commandList.getHeadPtr();
							while (random3 != 1)
							{
								random3--;
								pCur = pCur->getNextPtr();
							}
							std::cout << "2. " << pCur->getData().getDesc() << std::endl;
							//pCur->setData(saveResult3);
							std::cout << "3. " << saveResult3.getDesc() << std::endl;
							std::cout << std::endl;
							std::cin >> choice2;
							system("cls");
							system("cls");
							if (choice2 == 3)
							{
								score++;
								std::cout << "Correct! " << saveResult3.getName() << " - " << saveResult3.getDesc() << "  You have been awarded 1 point. Your point total is " << score << "." << std::endl;;
							}
							else
							{
								score--;
								std::cout << "Incorrect! " << saveResult3.getName() << " - " << saveResult3.getDesc() << " You have lost 1 point. Your point total is " << score << "." << std::endl;
							}
							system("pause");
							system("cls");
						}

						random = 0;
						number--;
					}
					players[i].points = score;
					i++;
					score = 0;
				}
				else
				{
					i++;
				}

			}
			break;
		case 4:
			system("cls");
			std::cout << "What command would you like to add?" << std::endl;
			std::cin >> commandtoAdd;
			pCur = commandList.getHeadPtr();
			while (pCur->getNextPtr() != nullptr)
			{
				if (pCur->getData().getName() == commandtoAdd)
				{
					system("cls");
					std::cout << "Command is already in the list" << std::endl;
					system("pause");
					system("cls");
					break;
				}
				pPre = pCur;
				pCur = pCur->getNextPtr();

			}
			if (pCur->getData().getName() != commandtoAdd)
			{
				h.setName(commandtoAdd);
				std::cin.ignore();
				std::cout << "Please add a description: ";
				std::getline(std::cin, descprition);
				h.setDesc(descprition);
				commandList.insertAtFront(h);
				arraySize++;
				system("cls");
				std::cout << "Command has been added." << std::endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
			system("cls");
			std::cout << "What command would you like to remove?" << std::endl;
			std::cin >> commandtoRemove;
			pCur = commandList.getHeadPtr();
			while (pCur != nullptr)
			{

				if (pCur->getData().getName() == commandtoRemove)
				{
					if (commandtoRemove == commandList.getHeadPtr()->getData().getName())
					{
						pTemp = pCur;
						pCur = pCur->getNextPtr();
						system("cls");
						std::cout << "Command has been deleted" << std::endl;
						commandList.removeNode(pTemp);
						arraySize--;
						system("pause");
						system("cls");
						y++;
						check2++;

					}
					if (pCur->getNextPtr() == nullptr)
					{
						pPre->setNextPtr(nullptr);
						pTemp = pCur;
						pCur = pPre;
						system("cls");
						std::cout << "Command has been deleted" << std::endl;
						commandList.removeNode(pTemp);
						system("pause");
						system("cls");
						y++;
					}
					if (check2 == 0)
					{
						pTemp = pCur;
						pCur = pCur->getNextPtr();
						pPre->setNextPtr(pCur);
						system("cls");
						std::cout << "Command has been deleted" << std::endl;
						commandList.removeNode(pTemp);
						system("pause");
						system("cls");
						y++;
					}
					if (check == 0)
					{

					}
					break;
				}
				else
				{
					check++;
					pPre = pCur;
					pCur = pCur->getNextPtr();
				}

			}
			if (y == 0)
			{
				system("cls");
				std::cout << "No command in the list with that name" << std::endl;
				system("pause");
				system("cls");
			}
			break;
		case 6:
			system("cls");
			commands.open("commands.csv", std::fstream::out);
			pCur = commandList.getHeadPtr();
			while (pCur != nullptr)
			{
				commands << pCur->getData().getName() << "," << pCur->getData().getDesc() << std::endl;
				pCur = pCur->getNextPtr();
			}
			commands.close();
			profiles.open("profiles.csv", std::fstream::out);
			i = 0;
			for (; i < 100; i++)
			{
				profiles << players[i].name << "," << players[i].points << std::endl;
			}
			profiles.close();
			std::cout << "Exiting" << std::endl;
			system("pause");
			break;
			break;
		}
	} while (choice != 6);
}

Profile tokenizer(string s, char del)
{
	std::stringstream ss(s);
	string word;
	Profile data;
	int x = 0;
	while (getline(ss, word, del))
	{
		if (word == "NONE")
		{
			word = "";
		}

		switch (x)
		{
		case 0:
			data.name = word;
			break;
		case 1:
			data.points = stoi(word);
			break;
		}
		x++;
	}

	return data;
}
