#include <iostream>
#include "reply_admin.h"

ReplyAdmin::ReplyAdmin(){
	chats = new string[NUM_OF_CHAT];
	chatnum = 0;
}
ReplyAdmin::~ReplyAdmin(){
	delete[] chats;
}
void ReplyAdmin::printChat(){
	for(int i=0;i<chatnum;i++)
		cout << i << " " << *(chats+i) << endl;
}
int ReplyAdmin::getChatCount(){
	return chatnum;
}
bool ReplyAdmin::addChat(string _chat){
	chatnum++;
	if (chatnum-1>=NUM_OF_CHAT)
		return false;
	else{
		*(chats+chatnum-1)=_chat;
		return true;
	}
}
bool ReplyAdmin::removeChat(int _index){
	if (_index>chatnum-1 || _index<0)
		return false;
	else{
		for (int i=_index;i<chatnum-1;i++)
			*(chats+i)=*(chats+i+1);
		chatnum--;
		return true;
	}
}
bool ReplyAdmin::removeChat(int _start,int _end){
	if (_start>chatnum-1 || _end <0)
		return false;
	else{
		if (_start<0)
			_start=0;
		else if(_end>chatnum-1)
			_end=chatnum-1;
		*(chats+_start)=*(chats+_end+1);
		chatnum -= _end-_start+1;
		return true;
	}
}
	
		
	
