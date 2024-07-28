#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "Item.h"
#include "Character.h" // Include Character header

class Inventory {
public:
    void addItem(const Item& item);
    void displayItems() const;
    void useItem(const std::string& itemName, Character& character); // Accept Character reference

private:
    std::vector<Item> items;
};

#endif



