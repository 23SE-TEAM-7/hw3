#include "JobInfo.h"

JobInfo::JobInfo(string companyName, string brn, string task, int employmentCnt, string deadline) {
	this->companyName = companyName;
	this->brn = brn;
	this->task = task;
	this->employmentCnt = employmentCnt;
	this->deadline = deadline;
	this->applyCnt = 0;
}

string JobInfo::getCompanyName(){
	return companyName;
}

string JobInfo::getBrn(){
	return brn;
}

string JobInfo::getTask(){
	return task;
}

int JobInfo::getEmploymentCnt()
{
	return employmentCnt;
}

string JobInfo::getDeadline(){
	return deadline;
}

void JobInfo::increaseApplyCnt(){
	applyCnt++;
}

void JobInfo::decreaseApplyCnt(){
	applyCnt--;
}

int JobInfo::getApplyCnt(){
	return applyCnt;
}