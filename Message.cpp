#include <iostream>
#include <string>
using namespace std;

#include "Message.h"

Message::Message() {
    author = "";
    subject = "";
    body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id) {
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}

// void Message::display() const {
//     cout << subject << endl;
//     cout << "from " << author << ": " << body;
//     return;
// }

Message::~Message() {
    
}

void Message::print(unsigned indentation) const {
    string space = "";
    string temp = this->body;
    
    for (unsigned i = 0; i < indentation; ++i) {
        space += " ";
    }
    for (unsigned i = 0; i < temp.size() - 1; ++i) {
        if (temp.at(i) == '\n') {
            temp.insert(i + 1, space);
            i += space.size();
        }
    }
    cout << space << "Message #" << id << ": " << subject << endl << space << "from " << author << ": " << temp;
    if(childList.size()) {
	    cout << endl;
    }
    for(unsigned i = 0; i < childList.size(); ++i) {
        childList.at(i)->print(indentation + 2);
        if(i != childList.size() - 1) {
		    cout << endl;
        }
    }
}

const string & Message::getSubject() const {
    return this->subject;
}

unsigned Message::getID() const {
    return this->id;
}

void Message::addChild(Message *child) {
    childList.push_back(child);
}