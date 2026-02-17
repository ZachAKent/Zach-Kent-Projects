
#include "FileReceiver.h"

bool FileReceiver::LoadMonsterFile(string name)
{
	if (monsterFile)
	{
		monsterFile.close();
	}

	monsterName = FILEBASE + name;
	monsterFile.open(monsterName);

	if (monsterFile.is_open())
	{
		if (result == PlayerOnly)
		{
			result = Both;
		}
		else if (result == None)
		{
			result = MonsterOnly;
		}

		return true;
	}

	return false;
}

bool FileReceiver::LoadPlayerFile(string name)
{
	if (playerFile)
	{
		playerFile.close();
	}

	playerName = FILEBASE + name;
	playerFile.open(playerName);

	if (monsterFile.is_open())
	{
		if (result == MonsterOnly)
		{
			result = Both;
		}
		else if (result == None)
		{
			result = PlayerOnly;
		}

		return true;
	}

	return false;
}

vector<string> FileReceiver::MonsterTable()
{
	vector<string> monsters;
	string line;
	
	while (getline(monsterFile, line))
	{
		monsters.push_back(line);
	}

	monsterFile.seekg(monsterFile.beg);

	return monsters;
}

vector<string> FileReceiver::PartyTable()
{
	vector<string> players;
	string name;

	while (getline(playerFile, name))
	{
		players.push_back(name);
	}

	playerFile.seekg(playerFile.beg);

	return players;
}

void FileReceiver::InitialStartup(string monster, string players)
{

	bool monsterCheck = LoadMonsterFile(monster);//monsterFile.open(FILEBASE + "SmugglersShivTable.txt");
	bool playerCheck = LoadPlayerFile(players);//playerFile.open(FILEBASE + "playerList.txt");

	if (monsterCheck && playerCheck)
	{
		monsterName = FILEBASE + "monsterTable.txt";
		playerName = FILEBASE + "playerList.txt";
		return;
	}
	else if (monsterCheck)
	{
		monsterName = FILEBASE + "SmugglersShivTable.txt";
		return;
	}
	else if (playerCheck)
	{
		playerName = FILEBASE + "playerList.txt";
		return;
	}
}

FileResult FileReceiver::GetResult()
{
	return result;
}
