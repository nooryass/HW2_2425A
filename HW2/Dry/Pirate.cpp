#include "Pirate.h"

const char* const devilFruitNames[] = {
        "Gum Gum",
        "Smoke Smoke",
        "Flame Flame",
        "Rumble Rumble",
        "String String",
        "Ice Ice",
        "None"
};

// Constructor
Pirate::Pirate(const string& name, int bounty, DEVIL_FRUIT devilFruit)
        : name(name), bounty(bounty), devilFruit(devilFruit) {}

// Getters
std::string Pirate::getName() {
    return name;
}

int Pirate::getBounty() const {
    return bounty;
}

DEVIL_FRUIT Pirate::getDevilFruit() {
    return devilFruit;
}

// Setters
void Pirate::setName(const string& name) {
    this->name = name;
}

void Pirate::setBounty(int bounty) {
    this->bounty = bounty;
}

void Pirate::setDevilFruit(DEVIL_FRUIT devilFruit) {
    this->devilFruit = devilFruit;
}

// Operator overload
std::ostream &operator<<(std::ostream &os, const Pirate &pirate) {
    os << pirate.name << ", Bounty: " << pirate.bounty
       << " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")";
    return os;
}
