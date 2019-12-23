#include <string>
#include <iostream>
#include "Message.h"
#ifndef REPLY_H
#define REPLY_H
using namespace std;

class Reply : public Message {
   // no new member variables
    public:
     //default constructor
     Reply();

     /* Parameterized constructor - similar to Message's constructor
      */
     Reply(const string &athr, 
           const string &sbjct, 
           const string &body, 
           unsigned id);
     
     virtual bool isReply() const; // Returns true
    
     virtual string toFormattedString() const; // New !!
       
  };

  //end inc guards

#endif