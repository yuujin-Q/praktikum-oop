// 13521074 Eugene Yap Jin Quan\

#include "Tool.hpp"
#include "Pickaxe.hpp"
#include "ReinforcedAxe.hpp"
#include <iostream>
using namespace std;

bool debug = false;
void printDebug() {
    if (debug) {
        cout << endl;
    }
}

int main() {
    Tool *t1;
    // tool crafted! 3 2
    // pickaxe crafted! 3 2
    // swing! swing! diamonds found!
    // pickaxe enchanted!
    Pickaxe p1;
    p1.use();
    p1.enchant();
    printDebug();

    // tool copy crafted! 3 2
    // pickaxe copy crafted! 3 2
    // tool crafted! 3 2
    // pickaxe crafted! 3 2
    // pickaxe copied! 3 2
    Pickaxe p2(p1);
    t1 = new Pickaxe();
    p2 = p1;
    printDebug();

    // tool crafted! 3 4
    // reinforced axe crafted! 3 4
    // chip chop chip chop! 3 4
    ReinforcedAxe *r1 = new ReinforcedAxe();
    r1->use();
    printDebug();

    // tool crafted! 3 4
    // reinforced axe copy crafted! 3 4
    // reinforced axe's grip enchanted! 3 4
    ReinforcedAxe *r2 = new ReinforcedAxe(*r1);
    r2->enchant();
    printDebug();

    // tool crafted! 3 4
    // reinforced axe copy crafted! 3 4
    // reinforcing axe! 6 8
    // tool crafted! 6 8
    // reinforced axe copy crafted! 6 8
    // reinforced axe is repaired! 6 8
    ReinforcedAxe *r3 = new ReinforcedAxe(*r1 + *r2);
    r3->repair();
    printDebug();

    // reinforced axe destroyed! 3 4
    // tool destroyed! 3 4
    // reinforced axe destroyed! 3 4
    // tool destroyed! 3 4
    // reinforced axe destroyed! 6 8
    // tool destroyed! 6 8
    // pickaxe destroyed! 3 2
    // tool destroyed! 3 2
    // pickaxe destroyed! 3 2
    // tool destroyed! 3 2
    delete r1;
    delete r2;
    delete r3;
    return 0;
}