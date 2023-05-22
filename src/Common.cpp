#include "Common.h"

Common::Common(int type, string name, string ssn, string id, string password): Member(type, name, id, password) {
    this->ssn = ssn;
}