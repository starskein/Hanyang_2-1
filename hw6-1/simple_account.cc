#include "simple_account.h"
#include <stdio.h>
void Account::New(int a,int b){
	id = a;
	money =b;
}
void Admin::init(){
	account_num = 0;
}
void Admin::mkacc(Account& a){
	if(account_num>=10)
		printf("Failure: make new account");
	else{
		account_num++;
		accounts[account_num-1] = a;
		printf("Account for user %d registered\n",account_num-1);
		printf("Balance of user %d: 0\n",account_num-1);
	}
}
void Admin::deposit(int id,int money){
	if (id>account_num-1){
		printf("Account does not exist\n");
		return;
	}
	else if (accounts[id].money+money>1000000)
		printf("Failure: Deposit to user %d %d\n",id,money);
	else{
		printf("Success: Deposit to user %d %d\n",id,money);
		accounts[id].money += money;
	}
	printf("Balance of user %d: %d\n",id,accounts[id].money);
	return;
}
void Admin::withdraw(int id,int money){
	if (id>account_num-1){
                printf("Account does not exist\n");
		return;
	}
        else if(accounts[id].money-money<0)
                printf("Failure: Withdraw to user %d %d\n",id,money);
        else{
                printf("Success: Withdraw to user %d %d\n",id,money);
                accounts[id].money -= money;
        }
        printf("Balance of user %d: %d\n",id,accounts[id].money);
        return;
}       
void Admin::send(int s_id,int r_id,int money){
	if (s_id>account_num-1 || r_id>account_num-1){
                printf("Account does not exist\n");
		return;
	}
        else if(accounts[s_id].money-money<0 || accounts[r_id].money+money>1000000)
		printf("Failure: Transfer from user %d to user %d %d\n",s_id,r_id,money);
	else{
  		printf("Success: Transfer from user %d to user %d %d\n",s_id,r_id,money);
                accounts[r_id].money += money;
		accounts[s_id].money -= money;
        }
        printf("Balance of user %d: %d\n",r_id,accounts[r_id].money);
	printf("Balance of user %d: %d\n",s_id,accounts[s_id].money);
        return;
}       

	
