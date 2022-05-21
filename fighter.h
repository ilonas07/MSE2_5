//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_FIGHTER_H
#define MSE2_5_FIGHTER_H

#include "npc.h"
#include <iostream>
#include "exceptions.h"

class Fighter : public NPC {
protected:
    int strength;

public:
    Fighter(Game* boss, const std::string& name, int health, int gold,
            int armor, int magicResistance, int strength)
            : NPC(boss, name, health, gold, armor, magicResistance), strength(strength) {}

    virtual void attack(Character* enemy) override;

    // Getter & Setter

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        if (strength >= 0) {
            this->strength = strength;
        } else {
            throw InvalidArgumentException("Strength may not be negative");
        }
    }
};

std::ostream& operator<<(std::ostream& out, const Fighter& f);



#endif //MSE2_5_FIGHTER_H
