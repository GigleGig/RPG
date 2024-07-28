#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Character.h" // Include Character header

class Character; // Forward declaration

class Item {
public:
    Item(const std::string& name, const std::string& description, void (*useFunction)(Character& character));

    const std::string& getName() const;
    const std::string& getDescription() const;
    void use(Character& character) const;

private:
    std::string name;
    std::string description;
    void (*useFunction)(Character& character);
};

#endif

