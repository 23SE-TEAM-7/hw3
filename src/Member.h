#pragma once
#ifndef HW3_MEMBER_H
#define HW3_MEMBER_H

#include <string>
using namespace std;

class Member {
private:
	int type;
	string name;
	string id;
	string password;

public:
	Member(int type, string name, string id, string password);
	bool comparePassword(string password);
	string getId();
	string getName();
	int getMemberType();
};

#endif