#include "Reply.h"
#include <sstream>

Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id):Message(athr, sbjct, body, id) 
{}

bool Reply::isReply() const {
    return true;
}

string Reply::toFormattedString() const {
    ostringstream converter;
    
    converter << "<begin_reply>\n:id: " << id << "\n:subject: " << subject << "\n:from: " << author << "\n";
    
    if(childList.size() != 0) {
        
        converter << ":children: ";
        
        for(size_t i = 0; i < childList.size(); i++) {
            
            if (i == childList.size() - 1) {
                converter << childList.at(i) ->getID();
            }
            else {
                converter << childList.at(i) ->getID() << ' ';
            }
        }
        converter << "\n";
    }
    
    converter << ":body: " << this->body;
    
    if (body.at(body.size()-1) != '\n') {
        converter << "\n";
    }
    converter << "<end>" << "\n";
    
    return converter.str();
}