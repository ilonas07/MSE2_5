//
// Created by ilona on 01.05.2022.
//

#include "hero.h"
#include <cstdlib>
#include <iostream>
#include "character.h"
#include "npc.h"
#include <cstring>


Hero::Hero(Game* boss, const std::string& name, int health, int gold,
           int armor, int magicResistance)
        : Character(boss, name, health, gold, armor, magicResistance), gear() {
    //std::memset(gear, 0, sizeof(Item*)*HERO_GEAR_SIZE);
}

Hero::~Hero() {

    if (health > 0){
        std::cout << *this << " claimed victory and is off to other adventures." << std::endl;
    } else {
        std::cout << *this << " was defeated. Game over. #muchsad #suchtragic" << std::endl;
    }
}

void Hero::attack(Character* enemy) {
    int damage = 15 + std::rand() % 11 - enemy->getArmor();
    if (damage < 0) {
        damage = 0;
    }
    std::cout << *this << " hits " << *enemy << " and reduces " << *enemy << "'s health by " << damage << " points!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}


void Hero::sellItem(int index) {
    if (inventory[index]) {
        gold += inventory[index]->getGold();
        std::cout << *inventory[index] << " was sold. "
                  << getName() << " now owns " << gold << " Gold." << std::endl;
        inventory.erase(inventory.begin() + index);
        //inventory[index] = nullptr;
    } else {
        throw InventoryEmptySlotException();
    }
}

bool Hero::fight(NPC* enemy) {
    while (health > 0 && enemy->getHealth() > 0) {
        attack(enemy);
        if (enemy->getHealth() > 0) {
            enemy->attack(this);
        }
    }
    if (health > 0) {
        std::cout << *enemy << " was knocked out! " << name
                  << " has " << health << " healthpoints remaining!" << std::endl;
        boss->removeCharacter(enemy->getName());
        std::cout << "--------------------" << std::endl;
        try {
            std::shared_ptr<Item> item = enemy->retrieveRandomLoot();
            addInventarItem(item);
            std::cout << *item << " was added to "
                      << getName() << "'s inventory." << std::endl;

        } catch(InvalidLoot& e) {
        }
    }
    return health > 0;
}



int Hero::addGearItem(std::shared_ptr<Item> item) {
    if (item) {
        for (int i = 0; i < HERO_GEAR_SIZE; i++) {
            if (!gear[i]) {
                gear[i] = item;
                return i;
            }
        }
    }
    throw GearFullException();
}

std::shared_ptr<Item> Hero::removeGearItem(int slot) {
    if (slot >= 0 && slot < HERO_GEAR_SIZE) {
        if (!gear[slot]) {
            throw InventoryEmptySlotException();
        }
        std::shared_ptr<Item> retval = gear[slot];
        gear[slot] = nullptr;
        return retval;
    }
    throw InvalidIndexException();
}

std::ostream& operator<<(std::ostream& out, const Hero& hero) {
    out << "Heroine " << hero.getName() << " (" << hero.getHealth() << " HP)";
    return out;
}