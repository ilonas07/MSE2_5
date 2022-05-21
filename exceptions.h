//
// Created by ilona on 01.05.2022.
//

#ifndef MSE2_5_EXCEPTIONS_H
#define MSE2_5_EXCEPTIONS_H
#include <stdexcept>

class GameException : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

class InventoryException : public GameException {
public:
    using GameException::GameException;
};

/*class InventoryFullException : public InventoryException {
public:
    InventoryFullException() : InventoryException("Inventory is full") {}
};*/
class GearFullException : public InventoryException {
public:
GearFullException() : InventoryException("Gear is full") {}
};

class InventoryEmptySlotException : public InventoryException {
public:
    InventoryEmptySlotException() : InventoryException("Inventory slot is empty") {}
};

class InvalidArgumentException : public GameException {
public:
    using GameException::GameException;
};

class InvalidIndexException : public InvalidArgumentException {
public:
    InvalidIndexException() : InvalidArgumentException("Invalid Array Index") {}
};

class InvalidItemException : public InvalidArgumentException {
public:
    InvalidItemException() : InvalidArgumentException("Invalid Item") {}
};

class InvalidLoot : public GameException {
public:
    InvalidLoot() : GameException("Invalid Loot") {}
};

class NonUninqueName : public GameException {
public:
    NonUninqueName() : GameException("Name is not unique") {}
};

class NonExistingName : public GameException {
public:
    NonExistingName() : GameException("Name does not exist") {}
};
#endif //MSE2_5_EXCEPTIONS_H
