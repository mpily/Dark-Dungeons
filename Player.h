#pragma once
#ifndef  PLAYER
#define PLAYER
#include <vector>// because we will have a list of inventories
#include <math.h>//for log function
#include<iostream>// for cout function
#include "Inventories.h"
#include "Actors.h"
/*
outline of the Player class
*/
class Player : public Actor{
protected:
  int maxHealth;
  int defense;
  int attack;
  int experiencePoints;
  int level ;
  std::vector<Inventories*> playerInventories;
  Inventories * headGear;
  Inventories * body;
  Inventories  *footGear;
  Inventories * weapon;
  Inventories * talisman;
public:
   Player(){
    maxHealth = 100;
    //health = 100;
    defense = 0;
    attack = 0;
    experiencePoints = 0;
    headGear = body = footGear = weapon = talisman = NULL;
    level = 1;

  }
  ~Player() = default;//since no memory was allocated

  void displayInventory();
  void levelUp();
  void updateExperience();

  int getDefense (){
    return defense;
  }
  int getAttack (){
    return attack;
  }
  int getexperiencePoints (){
    return experiencePoints;
  }
  void collectInventory(Inventories * newInventory);


};

#endif
/* end of include guard: Player */
