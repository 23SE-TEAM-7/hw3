#include "UserInfoUI.h"
#include "UserController.h"

UserInfoUI::UserInfoUI(ifstream* in, ofstream* out, UserController* uc) {
    this->in = in;
    this->out = out;
    this->uc = uc;
}

void UserInfoUI::inputMemberInfo(int type) {
    string name;
    string serialNumber;
    string id;
    string password;
    *in >> name >> serialNumber >> id >> password;
    uc->createMember(type, name, serialNumber, id, password);
}

void UserInfoUI::printMessage(string message) {
    *out << message << "\n";
}

void UserInfoUI::printUserDetail(int type, string name, string serialNumber, string id, string password) {
    *out << "> " << type << " ";
    *out << name << " " << serialNumber << " " << id << " " << password << "\n\n";
}

void UserInfoUI::printUserID(string id){
	*out << "> " << id << "\n\n";
}

void UserInfoUI::printUserIdAndPassword(string id, string password){
	*out << "> " << id << " " << password << "\n\n";
}

void UserInfoUI::inputIdAndPassword(){
    string id, password;
    *in >> id >> password;
    uc->checkIdAndPassword(id, password);
}
