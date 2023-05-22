#include "Member.h"

Member::Member(int type, string name, string id, string password) {
	this->type = type;
	this->name = name;
	this->id = id;
	this->password = password;
}

bool Member::comparePassword(string password) {
	if (this->password == password) {
		return true;
	}
	return false;
}

string Member::getId() {
	return id;
}

string Member::getName(){
	return name;
}

int Member::getMemberType(){
	return type;
}
