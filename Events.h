#pragma once
#include<vector>
#include "RNG.h"
//description of a class that will keep track of the events
class Event{
bool hasEnemy;
int areaLoc;//will have the pointer of which area it is located
public:
  static int totalEvents;//so as to know how many events are in the game
  static int eventCount =0;//so as to keep track of the event number
  Event();//constructor
  ~Event();//destructors

};
