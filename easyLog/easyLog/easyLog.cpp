#include "pch.h"
#include "easyLog.h"

namespace easyLog {
	bool myEasyLog::addLogRow(string namelog, string newLogRow)
	{
		// Se comprueba si existe ya un fichero con ese nombre.
		if (logs.count(namelog) == 0)
		{
			myEasyLog::addNewLogFile(namelog);
		}
		myEasyLog::addLogInfo(newLogRow, logs.at(namelog));

	}

	bool myEasyLog::closeLog(string namelog)
	{
		return false;
	}

	//Hora actual del sistema.
	string myEasyLog::getTime()
	{
		time_t rawtime;
		struct tm* stime;
		time(&rawtime);
		stime = localtime(&rawtime);
		return asctime(stime);
	}

	// Función que devuelve el directorio actual del proyecto
	string myEasyLog::getPatch()
	{
		wchar_t buffer[1024];
		GetModuleFileName(NULL, buffer, 1024);
		wstring ws(buffer);
		string patch(ws.begin(), ws.end());
		return patch;
	}

	// Añadimos un nuevo log a la lista de logs que se están usando en la ejecución actual.
	void myEasyLog::addNewLogFile(string namelog)
	{
		logs.insert(namelog, getPatch() + "\logs" + namelog);
	}

	// Se añade una nueva línea de al final del fichero de log especificado.
	void myEasyLog::addLogInfo(string info, string patch)
	{
		FILE* fp = fopen(patch.c_str(), "a");
		fputs((getTime() + ":" + info).c_str(), fp);

	}
}