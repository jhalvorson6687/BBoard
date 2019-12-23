#include <string>
#include <iostream>
#include "Message.h"
#ifndef TOPIC_H
#define TOPIC_H
using namespace std;

class Topic : public Message {
   public:
     Topic();
     Topic(const string &athr, 
           const string &sbjct, 
           const string &body, 
           unsigned id);
	virtual bool isReply() const;
    virtual string toFormattedString() const;  // New !!

  };
#endif