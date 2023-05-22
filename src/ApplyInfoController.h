#pragma once
#ifndef HW3_APPLYINFOCONTROLLER_H
#define HW3_APPLYINFOCONTROLLER_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class ApplyInfoUI;
class UserController;
class JobInfoController;
class JobInfo;

class ApplyInfoController {
private:
	ApplyInfoUI* aui;
	UserController* uc;
	JobInfoController* jc;
	JobInfo* selectedJobInfo;
	map<string, vector<JobInfo*>> applyInfos;
	
public:
	ApplyInfoController(ifstream* in, ofstream* out, UserController* uc, JobInfoController* jc);
	void searchJob();
	void getCompanyJobInfo(string companyName);
	void applyJob();
	void createApplyInfo(string brn);
	void inquiryApplyInfo();
	void cancelApplyJob();
	void deleteApplyInfo(string brn);
	vector<JobInfo*> getApplyInfo(string id);
};

#endif