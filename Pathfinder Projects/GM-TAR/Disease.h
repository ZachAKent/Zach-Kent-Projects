#ifndef _DISEASE_H_
#define _DISEASE_H_
#pragma once

#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

struct Player
{
	string name;
	vector<int> daysSick;
	vector<int> percentAmount;

	Player(string nm)
	{
		name = nm;
	}
};

class Disease
{
private:
	vector<Player> players;
	int days = 1;
	int percentChance = 25;

	void ResetTable();

public:
	void AddPlayer(string);
	void RemovePlayer(string);
	void DisplayPlayers();

	void SetDayCount(int);
	int GetDays();

	void SetPercentChance(int);
	int GetPercent();

	void GenerateDisease();
	list<string> GetResults();
	
};

#endif