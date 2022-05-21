//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_HERO_H
#define MSE2_5_HERO_H


#include <string>
#include "character.h"
#include "item.h"
#include <iostream>

// forward declaration
class NPC;

#define HERO_INVENTORY_SIZE		10
#define HERO_GEAR_SIZE			2


class Hero : public Character {
protected:
    std::shared_ptr<Item> gear[HERO_GEAR_SIZE];

public:
    Hero(Game* boss, const std::string& name, int health, int gold,
         int armor, int magicResistance);

    virtual ~Hero();

    virtual void attack(Character* enemy) override;

    bool fight(NPC* enemy);

    void sellItem(int index);

    int addGearItem(std::shared_ptr<Item> item);

    std::shared_ptr<Item> removeGearItem(int slot);
};

std::ostream& operator<<(std::ostream& out, const Hero& hero);




#endif //MSE2_5_HERO_H
