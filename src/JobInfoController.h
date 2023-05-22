#pragma once
#ifndef HW3_JOBINFOCONTROLLER_H
#define HW3_JOBINFOCONTROLLER_H

#include <fstream>
#include <map>
using namespace std;

class JobInfoUI;
class JobInfo;
class UserController;

class JobInfoController {
private:
	JobInfoUI* jui;
	UserController* uc;
	map<string, JobInfo*> jobInfos;

public:
	JobInfoController(ifstream* in, ofstream* out, UserController* uc);
	void registerJobInfo();
	void createJobInfo(string task, int employmentCnt, string deadline);
	void inquiryJobInfo();
	JobInfo* getCompanyJobInfo(string companyName);
};

#endif