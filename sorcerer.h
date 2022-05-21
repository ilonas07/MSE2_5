//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_SORCERER_H
#define MSE2_5_SORCERER_H



#include "npc.h"
#include <iostream>

class Sorcerer : public NPC {
protected:
    int magicPower;

public:
    Sorcerer(Game* boss, const std::string& name, int health, int gold,
             int armor, int magicResistance, int magicPower)
            : NPC(boss, name, health, gold, armor, magicResistance), magicPower(magicPower) {}

    virtual void attack(Character* hero) override;

    // Getter & Setter

    int getMagicPower() const {
        return magicPower;
    }

    void setMagicPower(int magicPower) {
        if (magicPower >= 0) {
            this->magicPower = magicPower;
        } else {
            throw InvalidArgumentException("Magic Power may not be negative");
        }
    }
};

std::ostream& operator<<(std::ostream& out, const Sorcerer& s);


#endif //MSE2_5_SORCERER_H
