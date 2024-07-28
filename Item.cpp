#include "Item.h"

Item::Item(const std::string& name, const std::string& description, void (*useFunction)(Character& character))
    : name(name), description(description), useFunction(useFunction) {}

const std::string& Item::getName() const {
    return name;
}

const std::string& Item::getDescription() const {
    return description;
}

void Item::use(Character& character) const {
    useFunction(character);
}
