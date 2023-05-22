#pragma once
#ifndef HW3_STATISTICCONTROLLER_H
#define HW3_STATISTICCONTROLLER_H

#include <fstream>
#include <vector>
using namespace std;

class StatisticUI;
class UserController;
class JobInfoController;
class ApplyInfoController;

class StatisticController {
private:
	StatisticUI* sui;
	UserController* uc;
	JobInfoController* jc;
	ApplyInfoController* ac;

public:
	StatisticController(ifstream* in, ofstream* out, UserController* uc, JobInfoController* jc, ApplyInfoController* ac);
	void showStatistic();
};

#endif