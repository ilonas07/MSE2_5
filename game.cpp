//
// Created by ilona on 01.05.2022.
//

#include "game.h"
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"

void Game::play() {
    std::srand(time(0));

    //adding characters
    std::shared_ptr<Hero> annina(new Hero(this, "Annina", 300, 100, 0, 0));
    addCharacter(annina);

    std::shared_ptr<Sorcerer> pascal(new Sorcerer(this, "Pascal", 50, 10000, 0, 0, 0));
    addCharacter(pascal);

    std::shared_ptr<Fighter> matthias(new Fighter(this, "Matthias", 50, 10000, 0, 0, 0));
    addCharacter(matthias);

    std::cout << "--------------------" << std::endl;

    //adding inventories
    pascal->addInventarItem(std::shared_ptr<Item>(new Item("Sparkly Diamond", 1000)));
    pascal->addInventarItem(std::shared_ptr<Item>(new Item("Magic Wand", 100)));

    matthias->addInventarItem(std::shared_ptr<Item>(new Item("Shiny Ruby", 800)));
    matthias->addInventarItem(std::shared_ptr<Item>(new Item("Hefty Sword", 200)));

    printCharacter();

    //try&catch block

    try {
        annina->setGold(-1000);
    } catch(InvalidArgumentException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

/*    try {
        annina->getInventory(1000);
    } catch(InvalidIndexException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }*/

    try {
        annina->setArmor(-10);
    } catch(InvalidArgumentException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    /*try {
        annina->removeInventarItem(11);
    } catch(InvalidIndexException& e) {
        std::cerr << "Exception caught (handler1): " << e.what() << std::endl;
    } catch(InventoryEmptySlotException& e) {
        std::cerr << "Exception caught (handler2): " << e.what() << std::endl;
    }
    try {
        annina->removeInventarItem(1);
    } catch(InvalidIndexException& e) {
        std::cerr << "Exception caught (handler1): " << e.what() << std::endl;
    } catch(InventoryEmptySlotException& e) {
        std::cerr << "Exception caught (handler2): " << e.what() << std::endl;
    }*/
    try {
        addCharacter(annina);
    } catch(NonUninqueName& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try {
        removeCharacter("Hans");
    } catch(NonExistingName& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }



    //fightblock
    if (annina->fight(pascal.get())) {
        pascal.reset();
        //removeCharacter("Pascal");
        std::cout << "--------------------" << std::endl;
        if(annina->fight(matthias.get())){
            matthias.reset();
            std::cout << "--------------------" << std::endl;
        }
    }
    printCharacter();

    if (annina->getHealth() > 0) {
        for (int i = annina->getInventorySize()-1; i >= 0; --i) {
            try {
                annina->sellItem(i);
                std::cout << "--------------------" << std::endl;
            } catch(InventoryEmptySlotException& e) {
            }
        }

    }
}

void Game::addCharacter(std::shared_ptr<Character> character) {
    if (players.find(character->getName()) == players.end()){ //wenn in der ganzen Map der Name nicht vorkommt, dann hinzufügen
        players.insert({character->getName(), character});
    } else {
        throw NonUninqueName();
    }
}

void Game::removeCharacter(const std::string &name) {
    if (players.find(name) != players.end()){
        players.erase(name);
    } else {
        throw NonExistingName();
    }

}

void Game::printCharacter() {
    for (const auto &c: players){
        std::cout << "Key: " << c.first << " = " << "HP: " << c.second->getHealth() << "; " << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

void Game::addItem(std::shared_ptr<Item> item) {
    stuffs.push_back(item);
}