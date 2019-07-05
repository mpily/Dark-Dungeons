#include <iostream>
#include <vector>
#include <time.h>

#include"Player.h"
#include "Inventories.h"
#include "Names.h"
#include "RNG.h"



using std::vector;

int main() {
    // testing inventories
    vector<Inventories*> playerInventories;
    string inventoryName;

    int statValue = 0, numStats = 1;
    char type;
    RNG randomizer(time(0)); // try catch is needed here for std::bad_alloc
    int randValue = randomizer.pick(0, 37);
    int level = 1;

    inventoryName = Item_Names[randValue];

    if(0 <= randValue && randValue <= 14){
        type = 'W'; // weapon
    } else if(randValue <= 20){
        type = 'H'; // helmet
    } else if(randValue <= 26){
        type = 'B'; // Body armor
    } else if(randValue <= 31){
        type = 'F'; // Foot gear
    } else if(randValue <= 36){
        type = 'T'; // Talisman
    } else { // P for health potion
        type = 'P'; // Health potion
    }

    // still need to set value according to the stat name
    if(randomizer.chance(35)){
        numStats = 2; // number of stats an inventory item can have
    }
    vector<string> statNames = {"Health", "Defense", "Magic Resistance", "Damage", "Special"};
    // randValue to pick stat
    randValue = randomizer.pick(0, 5);
    playerInventories.push_back(new Inventories(inventoryName)); // create an object without stats
    // add stats
    string statName;
    for (int i = 0; i < numStats; ++i) {
        if(randValue == 4){
            cout << "No special implementation yet...\n";
        } else{
            statName = statNames[randValue];
            // picking the statvalue according to the table in the pdf, This code may be useful later on. Or we may improve on it.
            if(randValue == 0 && (type == 'H' || type == 'B' || type == 'F')){
                statValue = randomizer.pick(1, 2 * level);
            } else if(randValue == 1 && (type == 'H' || type == 'B' || type == 'F' || type == 'T')){
                if(type == 'T'){ // if defense is rolled on talisman make it magic resistance instead
                    statValue = randomizer.pick(0,level/4);
                }else{
                    statValue = randomizer.pick(1, 1 + level/3);
                }
            }
            else if(randValue == 2 && (type == 'T')){
                statValue = randomizer.pick(0,level/4);
            }
            else if(randValue == 3 && (type == 'W' || type == 'T')){
                statValue = randomizer.pick(6, 1 + 3 * level);
            }else{
                //continue;
            }
            // for special I haven't yet thought of a  good way of implementing
            playerInventories[0]->addStat(statName, statValue, type);
            randValue = randomizer.pick(0, 5);
        }

    }

    playerInventories[0]->showStats();


    return 0;
}
