#pragma once

class Actor{
  int health;

public:
  void takeDamage(double regularDamage, double magicDamage,double magicResist, double defense){
      int totalDamage = 0;
      if(1 > (regularDamage-defense))totalDamage+=1;
      else totalDamage+=(regularDamage-defense);
      if(magicDamage){
        if(1 > (magicDamage - defense*magicResist))totalDamage+=1;
        else totalDamage+=(magicDamage - defense*magicResist);
      }

      health-=(totalDamage);
    }
  constexpr int getHealth(){
    return health;
  }
};
