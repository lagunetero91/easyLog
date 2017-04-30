#include "pch.h"
#include "easyLog.h"
#define GetCurrentDir
bool easyLog::addLogRow(string namelog, string newLogRow)
{
	// Se comprueba si existe ya un fichero con ese nombre.
	if (logs.count(namelog) == 0)
	{
		easyLog::addNewLogFile(namelog);
	}
	easyLog::addLogInfo(newLogRow, logs.at(namelog));
	
}

//Hora actual del sistema.
string easyLog::getTime()
{
	time_t rawtime;
	struct tm* stime;
	time(&rawtime);
	stime = localtime(&rawtime);
	return asctime(stime);
}

// Función que devuelve el directorio actual del proyecto
string easyLog::getPatch()
{
	wchar_t buffer[1024];
	GetModuleFileName(NULL,buffer,1024);
	wstring ws(buffer);
	string patch(ws.begin(), ws.end());
	return patch;
}

// Añadimos un nuevo log a la lista de logs que se están usando en la ejecución actual.
void easyLog::addNewLogFile(string namelog)
{
	logs.insert(namelog, getPatch() + "\logs" + namelog);
}

// Se añade una nueva línea de al final del fichero de log especificado.
void easyLog::addLogInfo(string info, string patch)
{
	FILE* fp = fopen(patch.c_str(), "a");
	fputs((getTime() + ":" + info).c_str(), fp);

}
