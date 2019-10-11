#ifndef __SIMPLE_ACCOUNT__
#define __SIMPLE_ACCOUNT__

class Account{
public:
	int id;
	int money;
public:
	void New(int a,int b);
};
class Admin{
public:
	Account accounts[10];
	int account_num;
public:
	void init();
	void mkacc(Account& a);
	void deposit(int id,int money);
	void withdraw(int id,int money);
	void send(int s_id,int r_id,int money);
};
#endif
	
