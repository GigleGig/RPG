#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

class Item; // Forward declaration

class Character {
public:
    Character(const std::string& name, int health, int attack, int defense);

    void takeDamage(int damage);
    bool isAlive() const;
    void displayStats() const;
    const std::string& getName() const;
    int getAttack() const;
    void addItem(const Item& item);
    void displayInventory() const;
    void useItem(const std::string& itemName);
    void levelUp();
    void gainExperience(int amount);
    void heal(int amount);
    void increaseDefense(int amount);

private:
    std::string name;
    int health;
    int maxHealth;
    int attack;
    int defense;
    int level;
    int experience;
    std::vector<Item> inventory;
};

#endif
