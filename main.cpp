#include <iostream>
#include "Inventories.h"
#include "Names.h"
#include "RNG.h"

#include <vector>
using std::vector;
int main() {
    // testing inventories
    vector<Inventories*> playerInventories;
    string inventoryName;

    int statValue;
    char type;
    RNG randomizer;
    int randValue = randomizer.pick(0, 37);
    int level = 1;

    inventoryName = Item_Names[randValue];

    if(0 <= randValue && randValue <= 14){
        type = 'W';
    } else if(randValue <= 20){
        type = 'H';
    } else if(randValue <= 26){
        type = 'B';
    } else if(randValue <= 31){
        type = 'F';
    } else if(randValue <= 36){
        type = 'T';
    } else { // P for health potion
        type = 'P';
    }

    


    return 0;
}