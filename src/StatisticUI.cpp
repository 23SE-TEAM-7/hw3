#include "StatisticUI.h"

StatisticUI::StatisticUI(ifstream* in, ofstream* out, StatisticController* sc){
	this->in = in;
	this->out = out;
	this->sc = sc;
}

void StatisticUI::printMessage(string message){
	*out << message << endl;
}

void StatisticUI::printStatisticInfo(string task, int memberCnt){
	*out << "> " << task << " " << memberCnt << "\n\n";
}

void StatisticUI::printUserStatisticInfo(map<string, int> counter){
	map<string, int>::iterator it;
	for (it = counter.begin(); it != counter.end(); it++) {
		string task = it->first;
		int cnt = it->second;
		*out << "> " << task << " " << cnt << "\n";
	}
	*out << "\n";
}
