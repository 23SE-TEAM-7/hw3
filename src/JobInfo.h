#pragma once
#ifndef HW3_JOBINFO_H
#define HW3_JOBINFO_H

#include <string>
using namespace std;

class JobInfo {
private:
	string companyName;
	string brn;
	string task;
	int employmentCnt;
	string deadline;
	int applyCnt; // 지원자 수

public:
	JobInfo(string companyName, string brn, string task, int employmentCnt, string deadline);
	string getCompanyName();
	string getBrn();
	string getTask();
	int getEmploymentCnt();
	string getDeadline();
	void increaseApplyCnt();
	void decreaseApplyCnt();
	int getApplyCnt();
};

#endif