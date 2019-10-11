#ifndef __REPLY_ADMIN__
#define __REPLY_ADMIN__
#define NUM_OF_CHAT 200
#include <string>
#include <string.h>
using namespace std;
class ReplyAdmin{
private:
	string* chats;
public:
	int chatnum;
public:
	ReplyAdmin();
	~ReplyAdmin();
	void printChat();
	int getChatCount();
	bool addChat(string _chat);
	bool removeChat(int _index);
	bool removeChat(int _start,int _end);
};
#endif	
