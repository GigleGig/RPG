#include "Inventory.h"
#include "Character.h" // Include Character header
#include <iostream>

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::displayItems() const {
    std::cout << "Inventory:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << " (" << item.getDescription() << ")\n";
    }
}

void Inventory::useItem(const std::string& itemName, Character& character) { // Pass Character reference
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) {
            it->use(character); // Use the item on the character
            items.erase(it);
            return;
        }
    }
    std::cout << "Item not found in inventory.\n";
}
