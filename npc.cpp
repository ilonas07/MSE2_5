//
// Created by ilona on 01.05.2022.
//



#include "npc.h"
#include "exceptions.h"


std::shared_ptr<Item> NPC::retrieveRandomLoot() {
    std::shared_ptr<Item> item = nullptr;
    for (int i = 0; i < this->getInventorySize(); i++) {
        int dice = std::rand() % this->getInventorySize();
        try {
            item = removeInventarItem(dice);
            break;
        } catch(InventoryEmptySlotException& e) {
        }
    }
    if (!item) {
        throw InvalidLoot();
    }
    return item;
}




