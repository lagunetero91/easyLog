#include "pch.h"
#include "easyLog.h"


	easyLog::easyLog(string logDir)
	{
		log = logDir;
	}

	easyLog::easyLog()
	{
		log = "log\\";
	}

	bool easyLog::addLogRow(string namelog, string newLogRow)
	{
		// Se comprueba si existe ya un fichero con ese nombre.
		if (easyLog::logs.count(namelog + ".txt")==0)
		{
			addNewLogFile(namelog);
		}
		set<string>::iterator iter = logs.find(namelog + ".txt");
		if (easyLog::addLogInfo(newLogRow, *iter)) return true;
		return false;
	}

	bool easyLog::closeLog(string namelog)
	{
		return false;
	}


	//Hora actual del sistema.
	string easyLog::getTime()
	{
		char buffer[32];
		__time32_t clock;
		struct tm newtime;
		_time32(&clock);
		_localtime32_s(&newtime, &clock);
		asctime_s(buffer, 32, &newtime);		
		return string(buffer).substr(0, sizeof(buffer) - 8);
	}

	// Añadimos un nuevo log a la lista de logs que se están usando en la ejecución actual.
	void easyLog::addNewLogFile(string namelog)
	{
		logs.insert(namelog + ".txt");
	}

	// Se añade una nueva línea de al final del fichero de log especificado.
	bool easyLog::addLogInfo(string info, string patch)
	{
		FILE* fp;
		int err = fopen_s(&fp, (log+ patch).c_str(), "a");
		if (err != 0)
		{
			return false;
		}
		fputs((getTime() + ": " + info + "\n").c_str(), fp);
		fclose(fp);
		return true;
	}


