#include "ApplyInfoUI.h"
#include "ApplyInfoController.h"
#include "JobInfo.h"

ApplyInfoUI::ApplyInfoUI(ifstream* in, ofstream* out, ApplyInfoController* ac){
	this->in = in;
	this->out = out;
	this->ac = ac;
}

void ApplyInfoUI::inputCompanyName(){
	string companyName;
	*in >> companyName;
	ac->getCompanyJobInfo(companyName);
}

void ApplyInfoUI::inputBrn(){
	string brn;
	*in >> brn;
	ac->createApplyInfo(brn);
}

void ApplyInfoUI::inputCancelBrn(){
	string brn;
	*in >> brn;
	ac->deleteApplyInfo(brn);
}

void ApplyInfoUI::printMessage(string message){
	*out << message << endl;
}

void ApplyInfoUI::printApplyInfo(string companyName, string brn, string task){
	*out << "> " << companyName << " " << brn << " " << task << "\n\n";
}

void ApplyInfoUI::printJobInfoDetail(string companyName, string brn, string task, int employmentCnt, string deadline) {
	*out << "> " << companyName << " " << brn << " " << task << " " << employmentCnt << " " << deadline << "\n\n";
}

void ApplyInfoUI::printApplyInfoDetails(vector<pair<string, JobInfo*>> sorted){
	for (int i = 0; i < sorted.size(); i++) {
		string companyName = sorted[i].first;
		string brn = sorted[i].second->getBrn();
		string task = sorted[i].second->getTask();
		int employmentCnt = sorted[i].second->getEmploymentCnt();
		string deadline = sorted[i].second->getDeadline();
		*out << "> " << companyName << " " << brn << " " << task << " " << employmentCnt << " " << deadline << "\n";
	}
	*out << "\n";
}