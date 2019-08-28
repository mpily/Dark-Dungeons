#include<string.h>
#include"Player.h"
/*Hello everyone, one of your friends messaged me about a little thing I forgot to state regarding the formulas. You should cast the power in P(x) to int as well. So the resulting formula is:

10 ^ ( int (l og_10 ( L(x) ) - 2.5))

Please pay attention to this.

Good luck with your finals!*/
//implemmentation of gven formulas
int  R_x(int level){
  int L_x = 108*level*level-60*level+152;
  double temptemp = (log10(L_x)-2.5);
  int temp = temptemp;
  double P_x = pow(10,temp);
  int r_x = int(int(L_x/P_x)*P_x);
  return r_x;
}
int E_x(int level){
  if(level == 1){
    return 0;
  }
  if (level == 2){
    return 100;
  }
  int r_x = R_x(level-1);
  int r_xx = R_x(level-2);
  return (r_x-r_xx);

}
 void Player::levelUp(){
  if(experiencePoints >= E_x(this->level+1) ){
      this->level+=1;
  }
}
void Player::collectInventory(Inventories* newInventory){
  if(this->playerInventories.size() == 10){
    std::cout<<" Inventory is full";
  }
  else{
    this->playerInventories.push_back(newInventory);
    std::cout << "Inventory Added successfully" << '\n';
  }
}
void printType(std::string type,Inventories * inventoryType){
  std::cout<<type<<" \n -------------------- \n";
  if(inventoryType)inventoryType->showStats();
  else std::cout<<"N/A";
  std::cout<<"\n";

}
void Player::displayInventory(){
  std::cout<<"========================= \n"<<"Currently Equipped \n"<<"========================= \n";
  printType("headGear", headGear);
  printType("body",body);
  printType("footGear",footGear);
  printType("weapon", weapon);
  printType("talisman", talisman);
  int count = 1;
  std::cout<<"\n\n =========================   \n Inventory  \n ========================= \n";
  for(auto & a : playerInventories){
    std::cout<<"slot #"<<count<<"\n"<<"------------------------ \n";a->showStats();std::cout<<"\n"<<"-------------\n";
    count++;
  }
  while (count < 11){
    std::cout<<"slot #"<<count<<"\n"<<"------------------------ \n "<<" Empty\n"<<"-------------\n";
    count++;
  }

}
