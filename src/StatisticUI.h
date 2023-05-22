#pragma once
#ifndef HW3_STATISTICUI_H
#define HW3_STATISTICUI_H

#include <fstream>
#include <string>
#include <map>
using namespace std;

class StatisticController;

class StatisticUI {
private:
	ifstream* in;
	ofstream* out;
	StatisticController* sc;

public:
	StatisticUI(ifstream* in, ofstream* out, StatisticController* sc);
	void printMessage(string message);
	void printStatisticInfo(string task, int memberCnt);
	void printUserStatisticInfo(map<string, int> counter);
};

#endif