//
// Created by ilona on 01.05.2022.
//

#include "character.h"
#include <iostream>
#include <cstring>
#include "exceptions.h"
#include "game.h"

Character::Character(Game* boss, const std::string& name, int health, int gold,
                     int armor, int magicResistance)
        : boss(boss), name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {

    std::cout << "Calling " << *this <<"::Constructor" << std::endl;
}


Character::~Character() {
    for (int i = this->getInventorySize()-1; i >= 0; --i) {
        if (inventory[i]){
            inventory.erase(inventory.begin() + i);
        }
    }
    std::cout << "Calling " << *this <<"::Destructor" << std::endl;
}

int Character::addInventarItem(std::shared_ptr<Item> item) {
    if (item) {
        inventory.push_back(item);
    }
    return 0;
}

std::shared_ptr<Item> Character::removeInventarItem(int slot) {
    if (inventory[slot]) {
        auto retval = inventory[slot];
        inventory.erase(inventory.begin() + slot);
        return retval;
    } else {
        throw InvalidItemException();
    }

}

std::ostream &operator<<(std::ostream &out, const Character &ch) {
    out << ch.getName();
    return out;
}