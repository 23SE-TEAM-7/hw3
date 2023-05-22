#include "StatisticController.h"
#include "StatisticUI.h"
#include "UserController.h"
#include "JobInfoController.h"
#include "ApplyInfoController.h"
#include "Member.h"
#include "JobInfo.h"

StatisticController::StatisticController(ifstream* in, ofstream* out, UserController* uc, JobInfoController* jc, ApplyInfoController* ac){
	sui = new StatisticUI(in, out, this);
	this->uc = uc;
	this->jc = jc;
	this->ac = ac;
}

void StatisticController::showStatistic(){
	Member* member = uc->getCurrMember();
	int type = member->getMemberType();
	sui->printMessage("5.1. ���� ���� ���");
	if (type == 1){ // ȸ�� ȸ��
		string companyName = member->getName();
		JobInfo* jobinfo = jc->getCompanyJobInfo(companyName);
		string task = jobinfo->getTask();
		int applyCnt = jobinfo->getApplyCnt();
		sui->printStatisticInfo(task, applyCnt);
	} else if (type == 2) { // �Ϲ� ȸ��
		string id = member->getId();
		vector<JobInfo*> applyinfos = ac->getApplyInfo(id);
		map<string, int> counter;
		for (int i = 0; i < applyinfos.size(); i++) {
			string task = applyinfos[i]->getTask();
			if (!counter.count(task)) {
				counter[task] = 1;
			} else {
				counter[task] = counter[task] + 1;
			}
		}
		sui->printUserStatisticInfo(counter);
	}
}