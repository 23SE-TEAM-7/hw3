#include "JobInfoUI.h"
#include "JobInfoController.h"
#include "JobInfo.h"

JobInfoUI::JobInfoUI(ifstream* in, ofstream* out, JobInfoController* jc){
	this->in = in;
	this->out = out;
	this->jc = jc;
}

void JobInfoUI::inputJobInfo(){
	string task;
	int employmentCnt;
	string deadline;
	*in >> task >> employmentCnt >> deadline;
	jc->createJobInfo(task, employmentCnt, deadline);
}

void JobInfoUI::printMessage(string message){
	*out << message << endl;
}

void JobInfoUI::printJobInfo(string task, int employmentCnt, string deadline){
	*out << "> " << task << " " << employmentCnt << " " << deadline << "\n\n";
}