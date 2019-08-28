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
    Enemy () = default;
    Enemy(int weight){
        if (weight <= 75){
            std::cout<<"there is a goblin \n";
            this->setHealth(15);
            this->attackStrength = 3.0;
            this->attackType = 'S';
            this->defenseStrength = 0;
            this->defenseType = 'L';
            this->percentDrop = 10;
            this->expAward = 30;
            this->minLevel = 1;
            this->magicAttack = 0;
            this->magicResist = 0;
        } else if( weight <= 135){
            std::cout<<"there is a orc \n";

            this->setHealth(25);
            this->attackStrength = 5.0;
            this->attackType = 'S';
            this->defenseStrength = 1;
            this->defenseType = 'L';
            this->percentDrop = 15;
            this->expAward = 60;
            this->minLevel = 1;
            this->magicAttack = 0;
            this->magicResist = 0;
        } else if(weight <= 185){
            std::cout<<"there is a troll \n";

            this->setHealth(35);
            this->attackStrength = 8.0;
            this->attackType = 'S';
            this->defenseStrength = 0;
            this->defenseType = 'L';
            this->percentDrop = 20;
            this->expAward = 85;
            this->minLevel = 3;
            this->magicAttack = 0;
            this->magicResist = 0;
        }
        else if(weight <= 215){
            std::cout<<"there is a golem \n";

            this->setHealth(60);
            this->attackStrength = 6.0;
            this->attackType = 'C';
            this->defenseStrength = 1;
            this->defenseType = 'M';
            this->percentDrop = 30;
            this->expAward = 125;
            this->minLevel = 6;
            this->magicAttack = 0;
            this->magicResist = 3.0;
        }
        else if(weight <= 260){
            std::cout<<"there is a skeleton \n";

            this->setHealth(35);
            this->attackStrength = 6.0;
            this->attackType = 'S';
            this->defenseStrength = 2;
            this->defenseType = 'H';
            this->percentDrop = 25;
            this->expAward = 100;
            this->minLevel = 6;
            this->magicAttack = 0;
            this->magicResist = 0;
        }
        else if(weight <= 320){
            std::cout<<"there is a spider \n";

            this->setHealth(20);
            this->attackStrength = 4.0;
            this->attackType = 'P';
            this->defenseStrength = 1;
            this->defenseType = 'L';
            this->percentDrop = 20;
            this->expAward = 55;
            this->minLevel = 4;
            this->magicAttack = 0;
            this->magicResist = 0;
        }
        else if(weight <= 340){
            std::cout<<"there is a dragon \n";

            this->setHealth(100);
            this->attackStrength = 16.0;
            this->attackType = 'P';
            this->defenseStrength = 5;
            this->defenseType = 'H';
            this->percentDrop = 60;
            this->expAward = 550;
            this->minLevel = 10;
            this->magicAttack = 10;
            this->magicResist = 1;
        }
        else if(weight <= 365){
            std::cout<<"there is a giant \n";

            this->setHealth(125);
            this->attackStrength = 12.0;
            this->attackType = 'C';
            this->defenseStrength = 1;
            this->defenseType = 'M';
            this->percentDrop = 50;
            this->expAward = 500;
            this->minLevel = 10;
            this->magicAttack = 0;
            this->magicResist = 0;
        }
        else if(weight <= 385){
            std::cout<<"there is a necromancer \n";

            this->setHealth(100);
            this->attackStrength = 16.0;
            this->attackType = 'M';
            this->defenseStrength = 1;
            this->defenseType = 'L';
            this->percentDrop = 60;
            this->expAward = 600;
            this->minLevel = 10;
            this->magicAttack = 0;
            this->magicResist = 5.0;
        } // Dark night do later...


    }


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
    Enemy&operator=(Enemy rhs){
        this->setHealth(rhs.getHealth());
        this->attackStrength = rhs.attackStrength;
        this->attackType = rhs.attackType;
        this->defenseStrength = rhs.defenseStrength;
        this->defenseType = rhs.defenseType;
        this->percentDrop = rhs.percentDrop;
        this->expAward = rhs.expAward;
        this->minLevel = rhs.minLevel;
        this->magicAttack = rhs.magicAttack;
        this->magicResist = rhs.magicResist;
    }
//////////////////////////////////////////////////
  void damageTo();

    void printDetails() {
        std::cout<<this->getHealth()<<"\n";
        std::cout<<this->defenseStrength<<this->defenseType<<"\n";
        std::cout<<this->attackStrength<<this->attackType<<"\n";
    }
};
