#include "UserController.h"
#include "UserInfoUI.h"
#include "Member.h"
#include "Common.h"
#include "Company.h"

UserController::UserController(ifstream* in, ofstream* out) {
    currMember = NULL;
    uui = new UserInfoUI(in, out, this);
}

void UserController::join(int type) {
    uui->inputMemberInfo(type);
}

void UserController::createMember(int type, string name, string serialNumber, string id, string password) {
    uui->printMessage("1.1. 회원가입");
    if (type == 1) { // 회사 회원
        Company* cp = new Company(1, name, serialNumber, id, password);
        members.insert(make_pair(id, cp));
        uui->printUserDetail(2, name, serialNumber, id, password);
    }
    else if (type == 2) { // 일반 회원
        Common* cp = new Common(2, name, serialNumber, id, password);
        members.insert(make_pair(id, cp));
        uui->printUserDetail(1, name, serialNumber, id, password);
    }
}

void UserController::deleteUser(){
    string id = currMember->getId();
    if (members.count(id)){
        members.erase(id);
        delete currMember;
        currMember = NULL;
    }
    uui->printMessage("1.2. 회원탈퇴");
    uui->printUserID(id);
}

Member* UserController::getCurrMember(){
    return currMember;
}

void UserController::login(){
    uui->inputIdAndPassword();
}

void UserController::checkIdAndPassword(string id, string password){
    if (members.count(id)) {
        if (members[id]->comparePassword(password)) {
            currMember = members[id];
            uui->printMessage("2.1. 로그인");
            uui->printUserIdAndPassword(id, password);
        }
    }
}

void UserController::logout() {
	uui->printMessage("2.2. 로그아웃");
    if (currMember != NULL) {
		uui->printUserID(currMember->getId());
		currMember = NULL;
	}
}