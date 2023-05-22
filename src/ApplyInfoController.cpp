#include "ApplyInfoController.h"
#include "ApplyInfoUI.h"
#include "JobInfoController.h"
#include "UserController.h"
#include "Member.h"
#include "JobInfo.h"

ApplyInfoController::ApplyInfoController(ifstream* in, ofstream* out, UserController* uc, JobInfoController* jc){
	this->aui = new ApplyInfoUI(in, out, this);
	this->uc = uc;
	this->jc = jc;
}

void ApplyInfoController::searchJob(){
	aui->inputCompanyName();
}

void ApplyInfoController::getCompanyJobInfo(string companyName){
	JobInfo* jobInfo = jc->getCompanyJobInfo(companyName);
	selectedJobInfo = jobInfo;
	if (jobInfo != NULL) {
		string brn = jobInfo->getBrn();
		string task = jobInfo->getTask();
		int employmentCnt = jobInfo->getEmploymentCnt();
		string deadline = jobInfo->getDeadline();
		aui->printMessage("4.1. 채용 정보 조회");
		aui->printJobInfoDetail(companyName, brn, task, employmentCnt, deadline);
	}
}

void ApplyInfoController::applyJob() {
	aui->inputBrn();
}

void ApplyInfoController::createApplyInfo(string brn){
	string targetBrn = selectedJobInfo->getBrn();
	string id = uc->getCurrMember()->getId();
	if (brn == targetBrn) {
		applyInfos[id].push_back(selectedJobInfo);
		aui->printMessage("4.2. 채용 지원");
		string companyName = selectedJobInfo->getCompanyName();
		string task = selectedJobInfo->getTask();
		selectedJobInfo->increaseApplyCnt();
		aui->printApplyInfo(companyName, brn, task);
	}
}

void ApplyInfoController::inquiryApplyInfo(){
	string id = uc->getCurrMember()->getId();
	if (applyInfos.count(id)) {
		vector<JobInfo*> jobInfos = applyInfos[id];
		vector<pair<string, JobInfo*>> sorted;
		for (int i = 0; i < jobInfos.size(); i++){
			sorted.push_back({jobInfos[i]->getCompanyName(), jobInfos[i]});
		}
		sort(sorted.begin(), sorted.end());
		aui->printMessage("4.3. 지원 내역 조회");
		aui->printApplyInfoDetails(sorted);
	}
}

void ApplyInfoController::cancelApplyJob(){
	aui->inputCancelBrn();
}

void ApplyInfoController::deleteApplyInfo(string brn){
	string id = uc->getCurrMember()->getId();
	if (applyInfos.count(id)) {
		vector<JobInfo*> jobInfos = applyInfos[id];
		for (int i = 0; i < jobInfos.size(); i++) {
			if (jobInfos[i]->getBrn() == brn) {
				jobInfos[i]->decreaseApplyCnt();
				applyInfos[id].erase(applyInfos[id].begin() + i);
				aui->printMessage("4.4. 지원 취소");
				string companyName = jobInfos[i]->getCompanyName();
				string task = jobInfos[i]->getTask();
				aui->printApplyInfo(companyName, brn, task);
				break;
			}
		}
	}
}

vector<JobInfo*> ApplyInfoController::getApplyInfo(string id){
	if (applyInfos.count(id)) {
		return applyInfos[id];
	}
}