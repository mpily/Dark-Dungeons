#pragma once
 #ifndef  PLAYER
#define PLAYER
#include <vector>// because we will have a list of inventories
#include <math.h>//for log function
#include "Inventories.h"
#include "Actors.h"
/*
 i am not sure  whether or not to add a variable for level here or add it in the events class
 that part did not seem completely clear from the instructions
 Also to be honest i havent fully understood polymorphism ... like in the practical sense so i am no sure how to  have this class inherit  from Actors.h
Due to the above I have left the Level up function to you to implement . Also I need to read upp on inventories before adding the list of Items here


*/
class Player : public Actor{
protected:
  int maxHealth;
  int defense;
  int attack;
  int experiencePoints;
  int level ;
public:
   Player(){
    maxHealth = 100;
    //health = 100;
    defense = 0;
    attack = 0;
    experiencePoints = 0;
    level = 1;
  }
  ~Player() = default;//since no memory was allocated

  void levelUp();
  void updateExperience();

  int getDefense(){
    return defense;
  }
  int getAttack(){
    return attack;
  }
  int getexperiencePoints(){
    return experiencePoints;
  }

};

#endif
/* end of include guard: Player */
