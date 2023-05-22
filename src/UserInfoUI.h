#pragma once
#ifndef HW3_USERINFOUI_H
#define HW3_USERINFOUI_H

#include <fstream>
#include <string>
using namespace std;

class UserController;

class UserInfoUI {
private:
    ifstream* in; 
    ofstream* out;
    UserController* uc;

public:
    UserInfoUI(ifstream* in, ofstream* out, UserController* uc);
    void inputMemberInfo(int type);
    void printUserDetail(int type, string name, string serialNumber, string id, string password);
    void printMessage(string message);
    void printUserID(string id);
    void printUserIdAndPassword(string id, string password);
    void inputIdAndPassword();
};

#endif