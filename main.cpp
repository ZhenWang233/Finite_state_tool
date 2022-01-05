#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "CommandShell/Dispatcher/CommandDispatcher.h"
#include <algorithm>
using namespace std;


void trim(std::string& str)
{
	size_t endpos = str.find_last_not_of(" \t");
	size_t startpos = str.find_first_not_of(" \t");
	if (std::string::npos != endpos)
	{
		str = str.substr(0, endpos + 1);
		str = str.substr(startpos);
	}
	else 
	{
		str.erase(std::remove(std::begin(str), std::end(str), ' '), std::end(str));
	}
}

bool loadConfiguration(CommandDispatcher& dispatcher, const std::string& configFile, std::string& dispatcherFinalResponse)
{
	ifstream infile(configFile);

	if (!infile.is_open())
	{
		dispatcherFinalResponse = "The file doesn't exists!";
		return false;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		trim(line);
		std::string request = line.substr(0, line.find("//", 0)); //remove comments

		if (request.length() == 0)
			continue;
		std::string response = dispatcher.dispatch(request);

		if (response.find("Error", 0) == 0)
		{
			dispatcherFinalResponse = response;
			return false;
		}
	}
	dispatcherFinalResponse = "Configuration file successfuly loaded!";
	return true;
}
void runAFL()
{
	CommandDispatcher dispatcher;
	while (1)
	{
		cout << ">";
		std::string request;
		std::getline(cin, request);
		
		std::string response;
		trim(request);

		if (request.rfind("load", 0) == 0) //load saved configuration
		{
			loadConfiguration(dispatcher, request.substr(5), response);
			cout << response << endl;
			continue;
		}
		response = dispatcher.dispatch(request);
		cout << response << endl;


	}
}
int main() 
{
	runAFL();
}
 
