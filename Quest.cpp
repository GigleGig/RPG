#include "Quest.h"
#include <iostream>

Quest::Quest(const std::string& title, const std::string& description)
    : title(title), description(description) {}

const std::string& Quest::getTitle() const {
    return title;
}

const std::string& Quest::getDescription() const {
    return description;
}

void Quest::addTask(const std::string& task) {
    tasks.push_back(task);
    taskCompletion.push_back(false);
}

void Quest::completeTask(const std::string& task) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i] == task) {
            taskCompletion[i] = true;
            return;
        }
    }
    std::cout << "Task not found.\n";
}

void Quest::displayTasks() const {
    std::cout << "Tasks for " << title << ":\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "- " << tasks[i] << (taskCompletion[i] ? " (completed)" : "") << "\n";
    }
}

bool Quest::isCompleted() const {
    for (const auto& completed : taskCompletion) {
        if (!completed) {
            return false;
        }
    }
    return true;
}
