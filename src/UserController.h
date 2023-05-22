#pragma once
#ifndef HW3_USERCONTROLLER_H
#define HW3_USERCONTROLLER_H

#include <fstream>
#include <string>
#include <map>
using namespace std;

class UserInfoUI;
class Member;

// controll
class UserController {
private:
    UserInfoUI* uui;
    map<string, Member*> members;
    Member* currMember;

public:
    UserController(ifstream* in, ofstream* out);
    void join(int type);
    void createMember(int type, string name, string serialNumber, string id, string password);
    void deleteUser();
    void login();
    void checkIdAndPassword(string id, string password);
    void logout();
    Member* getCurrMember();
};

#endif