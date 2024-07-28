#include "Game.h"
#include <iostream>

Game::Game()
    : player("Hero", 100, 20, 5), quest("Save the Village", "Defeat the goblin and save the village."), gameMap(10, 10) {
    // Add some initial items to the player's inventory
    Item potion("Health Potion", "Restores 20 health points", [](Character& c) { c.heal(20); });
    Item armor("Armor", "Increases defense by 5 points", [](Character& c) { c.increaseDefense(5); });
    player.addItem(potion);
    player.addItem(armor);

    // Add enemies
    enemies.push_back(Enemy("Goblin", 50, 10));

    // Add quest tasks
    quest.addTask("Find the goblin");
    quest.addTask("Defeat the goblin");

    // Add player to map
    gameMap.addCharacter(0, 0, 'P');
}

void Game::start() {
    char choice;
    do {
        displayMainMenu();
        std::cin >> choice;
        processMainMenuChoice(choice);
    } while (choice != 'q');
}

void Game::displayMainMenu() {
    std::cout << "\nMain Menu\n";
    std::cout << "1. Character\n";
    std::cout << "2. Inventory\n";
    std::cout << "3. Map\n";
    std::cout << "4. Quest\n";
    std::cout << "q. Quit\n";
    std::cout << "Enter your choice: ";
}

void Game::displayCharacterMenu() {
    player.displayStats();
    std::cout << "\nCharacter Menu\n";
    std::cout << "b. Back\n";
    std::cout << "Enter your choice: ";
}

void Game::displayInventoryMenu() {
    player.displayInventory();
    std::cout << "\nInventory Menu\n";
    std::cout << "1. Use item\n";
    std::cout << "b. Back\n";
    std::cout << "Enter your choice: ";
}

void Game::displayMap() {
    gameMap.display();
}

void Game::displayQuestMenu() {
    quest.displayTasks();
    std::cout << "\nQuest Menu\n";
    std::cout << "b. Back\n";
    std::cout << "Enter your choice: ";
}

void Game::processMainMenuChoice(char choice) {
    switch (choice) {
    case '1':
        displayCharacterMenu();
        std::cin >> choice;
        processCharacterMenuChoice(choice);
        break;
    case '2':
        displayInventoryMenu();
        std::cin >> choice;
        processInventoryMenuChoice(choice);
        break;
    case '3':
        displayMap();
        break;
    case '4':
        displayQuestMenu();
        std::cin >> choice;
        processQuestMenuChoice(choice);
        break;
    case 'q':
        std::cout << "Quitting game...\n";
        break;
    default:
        std::cout << "Invalid choice, try again.\n";
    }
}

void Game::processCharacterMenuChoice(char choice) {
    if (choice == 'b') {
        return;
    }
    else {
        std::cout << "Invalid choice, try again.\n";
    }
}

void Game::processInventoryMenuChoice(char choice) {
    if (choice == '1') {
        std::string itemName;
        std::cout << "Enter item name to use: ";
        std::cin >> itemName;
        player.useItem(itemName);
    }
    else if (choice == 'b') {
        return;
    }
    else {
        std::cout << "Invalid choice, try again.\n";
    }
}

void Game::processQuestMenuChoice(char choice) {
    if (choice == 'b') {
        return;
    }
    else {
        std::cout << "Invalid choice, try again.\n";
    }
}
