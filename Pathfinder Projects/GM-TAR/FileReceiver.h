#ifndef _FILERECEIVER_H_
#define _FILERECEIVER_H_
#pragma once

#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum FileResult {Both, MonsterOnly, PlayerOnly, None};

class FileReceiver
{
private:
	FileResult result = None;
	ifstream monsterFile, playerFile;
	string monsterName, playerName;
	public: const string FILEBASE = "../Resources/";

public:
	bool LoadMonsterFile(string);
	bool LoadPlayerFile(string);
	vector<string> MonsterTable();
	vector<string> PartyTable();
	void InitialStartup(string, string);
	FileResult GetResult();
};

#endif