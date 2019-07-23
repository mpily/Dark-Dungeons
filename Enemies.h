#pragma once
#include<vector>

#include"Actors.h"
#include"Inventories.h"

//implementation of Enemy class
class Enemy : public Actor{
  double attackStrength;
  char attackType;
  double defenseStrength;
  char defenseType;
  int percentDrop;
  int appearWeight;
  int expAward;
  int minLevel;
  int magicAttack;
  double magicResist;
public:
  // will return the damage received (not magical)
  // when calculating total damage do
  // double totDamage = damageOfAttacker(armorType)+ magicalDamage()
  double damageOfAttacker(char armorType){
    if(attackType == 'S' && armorType == 'L'){
      return 1.2*attackStrength;
    }
    else if(attackType == 'P' && armorType == 'L'){
      return 1.2 * attackStrength;
    }
    else if(attackType == 'C' && armorType =='H'){
      return 1.35 * attackStrength;
    }
  }
  double magicalDamage(){
    return magicAttack;
  }
//////////////////////////////////////////////////
  void damageTo
};
