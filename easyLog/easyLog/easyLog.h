#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <hash_map>

using namespace std;

class easyLog
{
	bool addLogRow(string namelog, string newLogRow);
	bool closeLog(string namelog);

private:
	hash_map<string, FILE*> logs;
	string getTime();
	string getPatch();
	void newFileLog(string namelog);
};