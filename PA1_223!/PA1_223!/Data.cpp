#include "Data.h"

Data::Data(string name, string desc)
{
	setName(name);
	setDesc(desc);
}

string Data::getName()
{
	return mName;
}

string Data::getDesc()
{
	return mDesc;
}

void Data::setName(string newName)
{
	mName = newName;
}

void Data::setDesc(string newDesc)
{
	mDesc = newDesc;
}

void Data::read(std::fstream& infile, Data& data)
{

	infile.open("commands.csv", std::fstream::in);
	infile >> data;
	infile.close();
}

void Data::readMaster(std::fstream& infile, Data& data)
{
	infile.open("master.csv", std::fstream::in);
	infile >> data;
	infile.close();
}

Data Data::adv_tokenizer(string s, char del)
{
	std::stringstream ss(s);
	string word;
	Data data;
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
			data.setName(word);
			break;
		case 1:
			data.setDesc(word);
			break;
		}
		x++;
	}

	return data;
}


std::fstream& operator>> (std::fstream& inStream, Data& data)
{
	static int x = 0;
	int y = 0;
	static int z = 0;
	string name = "";
	string line = "";
	static int l = 0;
	char del = ',';

	if (z != 40)
	{
		std::getline(inStream, name);
		z++;
	}

	if (inStream.is_open())
	{
		while (y < x)
		{
			std::getline(inStream, name);
			y++;
		}
		//std::getline(inStream, name);
		data = data.adv_tokenizer(name, del);
		x++;
	}
	else
	{
		printf("him");
	}
	if (x == 40)
	{
		x = 0;
		z = 0;
		l = 1;
	}
	return inStream;
}

std::fstream& operator<< (std::fstream& inStream, Data& data)
{
	inStream << data.getName() << "," << data.getDesc();
	inStream << std::endl;

	return inStream;
}