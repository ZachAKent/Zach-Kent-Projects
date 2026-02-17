#ifndef _ENCOUNTER_H_
#define _ENCOUNTER_H_
#pragma once

#include <string>
#include <iostream>
#include <sstream>			//For istringstream
#include <algorithm>
#include <list>
#include <vector>
#include "Dice.h"

using namespace std;

enum Time {Dawn, Noon, Dusk, Night, Last};

inline std::ostream& operator<<(ostream& out, const Time value) {
	return out << invoke([value] {
#define PROCESS_VAL(p) case(p): return #p;
		switch (value) {
			PROCESS_VAL(Dawn);
			PROCESS_VAL(Noon);
			PROCESS_VAL(Dusk);
			PROCESS_VAL(Night);
		}
#undef PROCESS_VAL
	});
}

struct Monster
{
	int lowerChance, upperChance;
	string name, amount;

	Monster(int lower, int upper, string nm, string amnt)
	{
		lowerChance = lower;
		upperChance = upper;
		replace(nm.begin(), nm.end(), '_', ' ');
		name = nm;
		amount = amnt;
	}

	Monster(string nm)
	{
		upperChance = 0;
		lowerChance = 0;
		name = nm;
		amount = "1";
	}

	Monster()
	{
		upperChance = 0;
		lowerChance = 0;
		name = "--";
		amount = "1";
	}
};

struct Result
{
	int percentResult = 0;
	int dayOccured = 0;
	Monster monsterOccured;
	Time whenOccured;

	Result(int percent, int day, Monster monster, Time when)
	{
		percentResult = percent;
		dayOccured = day;
		monsterOccured = monster;
		whenOccured = when;
	}
};

class Encounter
{
private:
	vector<Result> encounters;
	vector<Monster> monsters;
	int days = 1;
	int percentChance = 10;
	Time time = Dawn;

	string EnumToString(Time time);
	Monster WhichMonster(int);
	void ResetTable();

public:
	void AddMonsters(vector<string>);
	void GenerateEncounter();
	void PrintMonsterTable();

	void SetDayCount(int);
	int GetDays();

	void SetPercentChance(int);
	int GetPercent();

	list<string> GetResults();
};

#endif