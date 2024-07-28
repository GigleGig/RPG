#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int attack)
    : name(name), health(health), attack(attack) {}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Enemy::isAlive() const {
    return health > 0;
}

int Enemy::getAttack() const {
    return attack;
}

const std::string& Enemy::getName() const {
    return name;
}
