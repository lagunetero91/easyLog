#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <unordered_map>

using namespace std;
namespace easyLog {
	class myEasyLog
	{
	public:
		static bool addLogRow(string namelog, string newLogRow);
		static bool closeLog(string namelog);

	private:
		static unordered_map<string, string> logs;
		static string getTime();
		static string getPatch();
		static void addNewLogFile(string namelog);
		static void addLogInfo(string info, string patch);
	};
}