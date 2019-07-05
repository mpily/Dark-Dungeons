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
Player::levelUp(){
  if(experiencePoints >= E_x(this->level+1) ){
      this->level+=1;
  }
}
