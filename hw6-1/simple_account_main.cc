#include <iostream>
#include <stdio.h>
#include "simple_account.h"

int main(){
	Admin admin;
	admin.init();
	char job;
	int id1,id2,money;
	while(1){
		printf("Job?\n");
		scanf("\n%c",&job);
		if (job=='Q')
			break;
		else if(job=='D'){
			scanf("%d %d",&id1,&money);
			admin.deposit(id1,money);
		}
		else if(job=='W'){
			scanf("%d %d",&id1,&money);
                        admin.withdraw(id1,money);
		}
		else if(job=='N'){
			Account acc;
			acc.New(admin.account_num,0);
			admin.mkacc(acc);
		}
		else{
			scanf("%d %d %d",&id1,&id2,&money);
			admin.send(id1,id2,money);
		}
	}
	return 0;
}			
	
