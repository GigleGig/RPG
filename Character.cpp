#include "Character.h"
#include "Item.h" // Include Item header
#include <iostream>

Character::Character(const std::string& name, int health, int attack, int defense)
    : name(name), health(health), maxHealth(health), attack(attack), defense(defense), level(1), experience(0) {}

void Character::takeDamage(int damage) {
    int actualDamage = damage - defense;
    if (actualDamage > 0) {
        health -= actualDamage;
    }
    if (health < 0) {
        health = 0;
    }
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::displayStats() const {
    std::cout << "Name: " << name << "\n"
        << "Health: " << health << "/" << maxHealth << "\n"
        << "Attack: " << attack << "\n"
        << "Defense: " << defense << "\n"
        << "Level: " << level << "\n"
        << "Experience: " << experience << "\n";
}

const std::string& Character::getName() const {
    return name;
}

int Character::getAttack() const {
    return attack;
}

void Character::addItem(const Item& item) {
    inventory.push_back(item);
}

void Character::displayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << "- " << item.getName() << " (" << item.getDescription() << ")\n";
    }
}

void Character::useItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getName() == itemName) {
            it->use(*this);
            inventory.erase(it);
            return;
        }
    }
    std::cout << "Item not found in inventory.\n";
}

void Character::levelUp() {
    level++;
    maxHealth += 10;
    health = maxHealth;
    attack += 5;
    defense += 3;
    std::cout << name << " leveled up to level " << level << "!\n";
}

void Character::gainExperience(int amount) {
    experience += amount;
    if (experience >= 100) {
        levelUp();
        experience -= 100;
    }
}

void Character::heal(int amount) {
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
    std::cout << name << " healed by " << amount << " points.\n";
}

void Character::increaseDefense(int amount) {
    defense += amount;
    std::cout << name << "'s defense increased by " << amount << " points.\n";
}
