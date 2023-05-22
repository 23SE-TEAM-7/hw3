#pragma once
#ifndef HW3_COMPANY_H
#define HW3_COMPANY_H

#include "Member.h"
#include <string>
using namespace std;

// entity
class Company: public Member {
private:
    string brn; // business registration number

public:
    Company(int type, string companyName, string brn, string id, string password);
    string getBrn();
};

#endif