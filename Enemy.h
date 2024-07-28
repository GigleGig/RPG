#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health, int attack);

    void takeDamage(int damage);
    bool isAlive() const;
    int getAttack() const;
    const std::string& getName() const;

private:
    std::string name;
    int health;
    int attack;
};

#endif

