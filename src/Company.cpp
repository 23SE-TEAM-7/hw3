#include "Company.h"

Company::Company(int type, string companyName, string brn, string id, string password) : Member(type, companyName, id, password) {
	this->brn = brn;
}

string Company::getBrn(){
	return brn;
}