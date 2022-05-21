//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_NPC_H
#define MSE2_5_NPC_H


#include "character.h"
#include "item.h"


class NPC : public Character {
public:
    using Character::Character;

    virtual ~NPC() {
        if (health > 0) {
            std::cout << *this << " claimed victory and is off to other adventures." << std::endl;
        } else {
            std::cout << *this << " was defeated and is left behind. #yaay #nosad #heroforpresident" << std::endl;
        }
    }

    std::shared_ptr<Item> retrieveRandomLoot();
};




#endif //MSE2_5_NPC_H
