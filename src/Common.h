#pragma once
#ifndef HW3_COMMON_H
#define HW3_COMMON_H

#include "Member.h"
#include <string>
using namespace std;

// entity
class Common : public Member {
private:
    string ssn;

public:
    Common(int type, string name, string ssn, string id, string password);
};

#endif