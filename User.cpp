#include <iostream>
#include <string>
#include <vector>
#include "User.h"
using namespace std;

User::User() {
    username = "";
    password = "";
}

User::User(const string& uname, const string& pass) {
    username = uname;
    password = pass;
}

string User::getUsername() const {
    return username;
}

bool User::check(const string &uname, const string &pass) const {
    if ((uname == "") || (pass == "")) {
        return false;
    }
    if ((uname == username) && (pass == password)) {
        return true;
    }
    return false;
}

bool User::setPassword(const string &oldpass, const string &newpass) {
    if(oldpass == "") {
        return false;
    }
    else if (oldpass == password) {
        password = newpass;
        return true;
    }
    return false;
}