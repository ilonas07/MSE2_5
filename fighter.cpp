//
// Created by ilona on 01.05.2022.
//

#include "fighter.h"



void Fighter::attack(Character* enemy) {
    int damage = 5 + std::rand() % 6 + strength - enemy->getArmor();
    if (damage < 0) {
        damage = 0;
    }
    enemy->setHealth(enemy->getHealth() - damage);
    std::cout << *this << " hits " << *enemy << " and reduces " << *enemy << "'s health by " << damage << " points!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fighter& f) {
    out << "Fighter " << f.getName() << " (" << f.getHealth() << " HP)";
    return out;
}