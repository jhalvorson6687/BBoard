#include "Reply.h"
#include "Topic.h"
#include <sstream>
#include <iostream>

Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned id):Message(athr, sbjct, body, id)
{}

bool Topic::isReply() const {
    return false;
}

string Topic::toFormattedString() const {
    
    ostringstream converter;
    
    converter << "<begin_topic>\n:id: " << id << "\n:subject: " << subject << "\n:from: " << author << "\n";

    
    if(childList.size() != 0)
    {
        converter << ":children: "; 
        
        for(size_t i = 0; i < childList.size(); i++)
        {
            if(i == childList.size() - 1)
            converter << childList.at(i)->getID();
            else
            converter << childList.at(i)->getID() << ' ';
        }
        converter << '\n';
    }
    
    converter << ":body: " << this->body;
    
    if(body.at(body.size()-1) != '\n')
    converter << '\n';
    
    converter << "<end>" << '\n';
    
    return converter.str();
    
}