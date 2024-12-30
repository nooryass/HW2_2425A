#pragma once

#include <iostream>
using std::string;

// Enum for Devil Fruits
enum DEVIL_FRUIT {
    GUM_GUM_FRUIT,
    SMOKE_SMOKE_FRUIT,
    FLAME_FLAME_FRUIT,
    RUMBLE_RUMBLE_FRUIT,
    STRING_STRING_FRUIT,
    ICE_ICE_FRUIT,
    NONE
};

class Pirate {
private:
    string name;
    int bounty;
    DEVIL_FRUIT devilFruit;

public:
    // Constructors and Destructor
    Pirate(); // Default constructor
    Pirate(const string& name, int bounty, DEVIL_FRUIT devilFruit = DEVIL_FRUIT::NONE);
    ~Pirate() = default;

    // Getters
    string getName();
    int getBounty() const;
    DEVIL_FRUIT getDevilFruit();

    // Setters
    void setName(const string& name);
    void setBounty(int bounty);
    void setDevilFruit(DEVIL_FRUIT devilFruit);

    // Operator Overload
    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
