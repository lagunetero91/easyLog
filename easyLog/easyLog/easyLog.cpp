#include "pch.h"
#include "easyLog.h"

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
	return string();
}
