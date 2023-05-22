#include "JobInfoController.h"
#include "JobInfoUI.h"
#include "JobInfo.h"
#include "UserController.h"
#include "Member.h"
#include "Company.h"

JobInfoController::JobInfoController(ifstream* in, ofstream* out, UserController* uc){
	this->jui = new JobInfoUI(in, out, this);
	this->uc = uc;
}

void JobInfoController::registerJobInfo(){
	jui->inputJobInfo();
}

void JobInfoController::createJobInfo(string task, int employmentCnt, string deadline){
	string companyName = uc->getCurrMember()->getName();
	Company* company = (Company*)(uc->getCurrMember());
	string brn = company->getBrn();
	JobInfo* jobInfo = new JobInfo(companyName, brn, task, employmentCnt, deadline);
	jobInfos.insert({ companyName, jobInfo });
	jui->printMessage("3.1. 채용 정보 등록");
	jui->printJobInfo(task, employmentCnt, deadline);
}

void JobInfoController::inquiryJobInfo(){
	string companyName = uc->getCurrMember()->getName();
	JobInfo* jobInfo = jobInfos[companyName];
	jui->printMessage("3.2. 등록된 채용 정보 조회");
	string task = jobInfo->getTask();
	int employmentCnt = jobInfo->getEmploymentCnt();
	string deadline = jobInfo->getDeadline();
	jui->printJobInfo(task, employmentCnt, deadline);
}

JobInfo* JobInfoController::getCompanyJobInfo(string companyName){
	if (jobInfos.count(companyName)){
		return jobInfos[companyName];
	}
	return NULL;
}