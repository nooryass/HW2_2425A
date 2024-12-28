
#pragma once

#include <iostream>

using std::string;

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


public:

    Pirate() = default;
    DEVIL_FRUIT devilFruit;

public:
    Pirate(const string& name,int bouty, DEVIL_FRUIT devilFruit = DEVIL_FRUIT::NONE);

    ~Pirate() = default;

    void setName(const string& name);
    void setDevilFruit(DEVIL_FRUIT devilFruit);

    string getName();
    void setBounty(int bounty);
    DEVIL_FRUIT getDevilFruit();

    int getBounty() const;
    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
