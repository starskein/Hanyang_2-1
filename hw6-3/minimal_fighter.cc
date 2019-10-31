#include "minimal_fighter.h"
#include <iostream>
MinimalFighter::MinimalFighter(){
	mHp = 0;
	mPower = 0;
	mStatus= Invalid;
}
MinimalFighter::MinimalFighter(int _hp, int _power){
	mHp = _hp;
	mPower = _power;
	mStatus= Alive;
}
int MinimalFighter::hp() const {
	return mHp;
}
int MinimalFighter::power() const {
	return mPower;
}
FighterStatus MinimalFighter::status() const{
	return mStatus;
}
void MinimalFighter::setHp(int _hp){
	mHp = _hp;
}
void MinimalFighter::setStatus(){
	mStatus=Dead;
}
void MinimalFighter::hit(MinimalFighter* _enemy){
	mHp -= _enemy->hp();
	_enemy->setHp(_enemy->hp()-mPower);
	if (mHp<=0)
		mStatus=Dead;
	if (_enemy->hp()<=0)
		_enemy->setStatus();
}
void MinimalFighter::attack(MinimalFighter* _target){
	_target->setHp(_target->hp()-mPower);
	mPower = 0;
	if (_target->hp()<=0)
                _target->setStatus();
}
void MinimalFighter::fight(MinimalFighter* _enemy){
	while(1){
		 mHp -= _enemy->hp();
        	_enemy->setHp(_enemy->hp()-mPower);
		if (mHp<=0){
                	mStatus=Dead;
			break;
		}
        	if (_enemy->hp()<=0){
                	_enemy->setStatus();
			break;
		}
	}
}

