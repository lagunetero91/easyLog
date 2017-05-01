#include "pch.h"
#include "easyLog.h"

namespace easyLog {
	bool myEasyLog::addLogRow(string namelog, string newLogRow)
	{
		// Se comprueba si existe ya un fichero con ese nombre.
	if ( logs.count(namelog + ".txt")==0)
	{
		addNewLogFile(namelog);
	}
	set<string>::iterator iter = logs.find(namelog + ".txt");
	addLogInfo(newLogRow,*iter);
	return true;
	}

	bool myEasyLog::closeLog(string namelog)
	{
		return false;
	}

	//Hora actual del sistema.
	string myEasyLog::getTime()
	{
		char buffer[32];
		__time32_t clock;
		struct tm newtime;
		_time32(&clock);
		_localtime32_s(&newtime, &clock);
		asctime_s(buffer, 32, &newtime);		
		string exit = buffer;
		return exit.substr(0, exit.length() - 1);
	}

	// Añadimos un nuevo log a la lista de logs que se están usando en la ejecución actual.
	void myEasyLog::addNewLogFile(string namelog)
	{
		logs.insert(namelog + ".txt");
	}

	// Se añade una nueva línea de al final del fichero de log especificado.
	void myEasyLog::addLogInfo(string info, string patch)
	{
		FILE* fp;
		int err = fopen_s(&fp, ("log\\" + patch).c_str(), "a");
		fputs((getTime() + ": " + info + "\n").c_str(), fp);
		fclose(fp);
	}
}