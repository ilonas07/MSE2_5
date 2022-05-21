//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_ITEM_H
#define MSE2_5_ITEM_H


#include <string>
#include <iostream>
#include "exceptions.h"

class Item {
private:
    std::string name;
    int gold;

public:
    Item(const std::string& name, int gold);

    Item();

    ~Item(){
        std::cout << "Calling " << name << "::Destructor" << std::endl;
    };

    // Getter & Setter

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
};

std::ostream& operator<<(std::ostream& out, const Item& item);



#endif //MSE2_5_ITEM_H
