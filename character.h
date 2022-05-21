//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_CHARACTER_H
#define MSE2_5_CHARACTER_H

#include <string>
#include <vector>
#include <memory>
#include "item.h"
#include "exceptions.h"
#include "game.h"

#define CHARACTER_INVENTORY_SIZE	10



class Character {
protected:
    Game* boss;
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    std::vector<std::shared_ptr<Item>> inventory;


public:
    Character(Game* boss, const std::string& name, int health, int gold,
              int armor, int magicResistance);

    virtual ~Character();

    virtual void attack(Character* hero) = 0;

    int addInventarItem(std::shared_ptr<Item> item);

    std::shared_ptr<Item> removeInventarItem(int slot);

    // Getter & Setter

    std::shared_ptr<Item> getInventory(int slot) {
        auto item = this->inventory[slot];
        return item;
    }

    int getInventorySize() {
        return inventory.size();
    }

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        } else {
            throw InvalidArgumentException("Gold may not be negative");
        }
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        if (health < 0) {
            health = 0;
        }
        this->health = health;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if (!name.empty()) {
            this->name = name;
        } else {
            throw InvalidArgumentException("Name may not be empty");
        }
    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        if (armor >= 0) {
            this->armor = armor;
        } else {
            throw InvalidArgumentException("Armor may not be negative");
        }
    }

    int getMagicResistance() const {
        return magicResistance;
    }

    void setMagicResistance(int magicResistance) {
        if (magicResistance >= 0) {
            this->magicResistance = magicResistance;
        } else {
            throw InvalidArgumentException("Magic Resistance may not be negative");
        }
    }
};


std::ostream& operator<<(std::ostream& out, const Character& ch);





#endif //MSE2_5_CHARACTER_H
