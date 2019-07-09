#pragma once
class Actor{
  int health;
  void takeDamage();
public:
  constexpr int getHealth(){
    return health;
  }
};
