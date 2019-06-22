#pragma once
 #ifndef  PLAYER
#define PLAYER
#include <vector>// because we will have a list of inventories
#include "Inventories.h"
/*
 i am not sure  whether or not to add a variable for level here or add it in the events class
 that part did not seem completely clear from the instructions
 Also to be honest i havent fully understood polymorphism ... like in the practical sense so i am no sure how to  have this class inherit  from Actors.h
Due to the above I have left the Level up function to you to implement . Also I need to read upp on inventories before adding the list of Items here


*/
class Player{
  int maxHealth;
  int health;
  int defense;
  int attack;
  int experiencePoints;
public:
  constexpr Player(){
    maxHealth = 100;
    health = 100;
    defense = 0;
    attack = 0;
    experiencePoints = 0;
  }
  ~Player() = default;//since no memory was allocated
  void levelUp();

  constexpr int getHealth(){
    return health;
  }
  constexpr int getDefense(){
    return defense;
  }
  constexpr int getAttack(){
    return attack;
  }
  constexpr int getexperiencePoints(){
    return experiencePoints;
  }

};

#endif
/* end of include guard: Player */
