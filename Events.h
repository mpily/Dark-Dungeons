#pragma once
#include<vector>
#include <time.h>
#include "RNG.h"
#include"Inventories.h"
#include"Enemies.h"
#include "Player.h"
//description of a class that will keep track of the events
//an event will be created by paassing in a given player
//the event will then keep track of what the player can do; the enemies he has to fight etc.
class Event{
Inventories * anInventory;
int areaLoc;//will have the pointer of which area it is located

public:
  Player * playerOne;//I chose to use a pointer because we want the class to modify the object i.e. when he picks inventories;
  static int totalEvents ;//so as to know how many events are in the game//set at default to 99
  static int eventCount ;//so as to keep track of the event number
  Enemy myEnemy;
  bool hasEnemy = false;
  Event(Player & aPlayer){
      RNG ran(time(0));

      if(ran.chance(100)){
          int weight = ran.pick(0, 385);
            Enemy newEnemy(weight);
            myEnemy = newEnemy;
            hasEnemy = true;
      } else if(ran.chance(25)){
          std::cout << "Inventory";
      }


    playerOne = &(aPlayer);
    std::cout << "Welcome "<<playerOne->name<< '\n';
  }//constructor

  ~Event()= default;//destructors

  void setTotalEvents(int tot ){
    totalEvents = tot;
  }

  bool play(){//this function will basically be the description of the game play
    char selection;
    std::cout<<"What shall you do? \n \t I - View Inventory \n \t Q  - Quit game \n";
      if(hasEnemy)std::cout<<"V - View Enemy Details \n";
    std::cin >> selection;
    switch (selection) {
      case 'I' :
        playerOne->displayInventory();
        return 1;
      case 'Q':
        return 0;
        case 'V':
            if(hasEnemy) myEnemy.printDetails();
    }


  }
};
