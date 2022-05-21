//
// Created by ilona on 01.05.2022.
//


#include "sorcerer.h"



void Sorcerer::attack(Character* enemy) {
    int damage = 5 + std::rand() % 6 + magicPower - enemy->getMagicResistance();
    if (damage < 0) {
        damage = 0;

    }
    enemy->setHealth(enemy->getHealth() - damage);
    std::cout << *this << " hits " << *enemy << " and reduces " << *enemy << "'s health by " << damage << " points!" << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Sorcerer& s) {
    out << "Sorcerer " << s.getName() << " (" << s.getHealth() << " HP)";
    return out;
}