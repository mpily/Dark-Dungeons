#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::string;

class Inventories{
private:
    string name;
    vector<int> statValues;
    vector<string> statNames;
    char type;
public:
    Inventories(const string &name, const string &statName, int statValue, char type){
        this->name = name;
        statNames.push_back(statName);
        statValues.push_back(statValue);
        this->type = type;
    }

    virtual ~Inventories() = default;

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    void addStat(const string &name, int value, char type){
        statNames.push_back(name);
        statValues.push_back(value);
        this->type = type;
    }

    void showStats() const{
        cout << this->name << "\n";
        // loop through the stats. Will be necessary to show in the console
        cout << "----------------\n";
        for (int i = 0; i < statValues.size(); ++i) {
            cout << statNames[i] << ": " << statValues[i] << "\n";
        }
    }

};