#pragma once
#ifndef QUEST_H
#define QUEST_H

#include <string>
#include <vector>

class Quest {
public:
    Quest(const std::string& title, const std::string& description);

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    void addTask(const std::string& task);
    void completeTask(const std::string& task);
    void displayTasks() const;
    bool isCompleted() const;

private:
    std::string title;
    std::string description;
    std::vector<std::string> tasks;
    std::vector<bool> taskCompletion;
};

#endif

