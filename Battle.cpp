#include "Battle.h"
#include <iostream>

void battle(Character& character, Enemy& enemy) {
    std::cout << "Battle starts between " << character.getName() << " and " << enemy.getName() << "!\n";

    while (character.isAlive() && enemy.isAlive()) {
        enemy.takeDamage(character.getAttack());
        if (enemy.isAlive()) {
            character.takeDamage(enemy.getAttack());
        }
    }

    if (character.isAlive()) {
        std::cout << character.getName() << " has won the battle!\n";
    }
    else {
        std::cout << character.getName() << " has been defeated.\n";
    }
}
