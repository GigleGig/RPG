#pragma once
#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Enemy.h"
#include "Quest.h"
#include "Map.h"
#include "Item.h"
#include <vector>

class Game {
public:
    Game();
    void start();
    void displayMainMenu();
    void displayCharacterMenu();
    void displayInventoryMenu();
    void displayMap();
    void displayQuestMenu();
    void processMainMenuChoice(char choice);
    void processCharacterMenuChoice(char choice);
    void processInventoryMenuChoice(char choice);
    void processQuestMenuChoice(char choice);

private:
    Character player;
    std::vector<Enemy> enemies;
    Quest quest;
    Map gameMap;
};

#endif
