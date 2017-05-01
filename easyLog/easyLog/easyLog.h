#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <set>

using namespace std;
namespace easyLog {
	class myEasyLog
	{
	public:
		static bool addLogRow(string namelog, string newLogRow);
		static bool closeLog(string namelog);

	private:
		static set<string> logs;
		static string getTime();
		static void addNewLogFile(string namelog);
		static bool addLogInfo(string info, string patch);
	};
}