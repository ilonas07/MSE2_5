//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_GAME_H
#define MSE2_5_GAME_H


#include <map>
#include <string>
#include <memory>
#include <vector>

class Character;
class Item;

class Game {
protected:
    std::map<std::string, std::shared_ptr<Character>> players;
    std::vector<std::shared_ptr<Item>> stuffs;

public:
    void play();

    //Add Characters
    void addCharacter(std::shared_ptr<Character> character);

    //Delete Characters
    void removeCharacter(const std::string& name);

    //Print Characters
    void printCharacter();

    //Add Items
    void addItem(std::shared_ptr<Item> item);

    //Delete Items
    void removeItem(std::shared_ptr<Item> item);

    //Print Items
};


#endif //MSE2_5_GAME_H
