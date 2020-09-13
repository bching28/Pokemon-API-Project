#ifndef MACHINES_H
#define MACHINES_H

#include <iostream>
#include "Games.h"
#include "Items.h"
//#include "Moves.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class Machine;

class Item;         // Items.h
//class Move;         // Moves.h
class VersionGroup; // Games.h

class Machine {
private:
    int id;
    Item* item;
    //Move* move; // Moves.h
    VersionGroup* versionGroup;

public:
    Machine();
    ~Machine();
};

#endif // MACHINES_H