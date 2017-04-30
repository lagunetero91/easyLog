﻿#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <unordered_map>

using namespace std;

class easyLog
{
	bool addLogRow(string namelog, string newLogRow);
	bool closeLog(string namelog);

private:
	unordered_map<string, string> logs;
	string getTime();
	string getPatch();
	void addNewLogFile(string namelog);
	void addLogInfo(string info, string patch);
};