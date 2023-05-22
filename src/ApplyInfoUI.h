#pragma once
#ifndef HW3_APPLYINFOUI_H
#define HW3_APPLYINFOUI_H

#include <fstream>
#include <vector>
using namespace std;

class ApplyInfoController;
class JobInfo;

class ApplyInfoUI {
private:
	ifstream* in;
	ofstream* out;
	ApplyInfoController* ac;

public:
	ApplyInfoUI(ifstream* in, ofstream* out, ApplyInfoController* ac);
	void inputCompanyName();
	void inputBrn();
	void inputCancelBrn();
	void printMessage(string message);
	void printApplyInfo(string companyName, string brn, string task);
	void printJobInfoDetail(string companyName, string brn, string task, int employmentCnt, string deadline);
	void printApplyInfoDetails(vector<pair<string, JobInfo*>> sorted);
};

#endif