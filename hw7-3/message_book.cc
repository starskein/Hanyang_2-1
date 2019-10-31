#include "message_book.h"
#include <stdio.h>
#include <iostream>
#include <string>
const string SS = " ";
MessageBook::MessageBook(){
}
MessageBook::~MessageBook(){
}
void MessageBook::AddMessage(int number, const string& message){
	messages_[number] = message;
}
void MessageBook::DeleteMessage(int number){
	messages_.erase(number);
}
vector<int> MessageBook::GetNumbers(){
	vector<int> num_list;
	for(map<int,string>::iterator it = messages_.begin();it!=messages_.end();it++){
		num_list.push_back(it->first);
	}
	return num_list;
}
const string& MessageBook::GetMessage(int number){
	if (messages_.count(number) == 0) return SS;
	return messages_.find(number)->second;
}
