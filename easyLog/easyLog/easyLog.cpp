#include "pch.h"
#include "easyLog.h"
#define GetCurrentDir
bool easyLog::addLogRow(string namelog, string newLogRow)
{
	if (logs.count(namelog) > 0)
	{
		
	}
	else 
	{

	}
	return false;
}

string easyLog::getTime()
{
	time_t rawtime;
	struct tm* stime;
	time(&rawtime);
	stime = localtime(&rawtime);
	return asctime(stime);
}

string easyLog::getPatch()
{
	wchar_t buffer[1024];
	GetModuleFileName(NULL,buffer,1024);
	wstring ws(buffer);
	string patch(ws.begin(), ws.end());
	return patch;
}
