#pragma once
#ifndef HW3_JOBINFOUI_H
#define HW3_JOBINFOUI_H

#include <fstream>
#include <vector>
using namespace std;

class JobInfoController;
class JobInfo;

class JobInfoUI {
private:
	ifstream* in;
	ofstream* out;
	JobInfoController* jc;

public:
	JobInfoUI(ifstream* in, ofstream* out, JobInfoController* jc);
	void inputJobInfo();
	void printMessage(string message);
	void printJobInfo(string task, int employmentCnt, string deadline);
};

#endif