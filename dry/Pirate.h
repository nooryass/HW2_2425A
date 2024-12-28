
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int bounty;


public:
    Pirate(const string& name,int bounty);

    Pirate() = default;

    ~Pirate() = default;

    void setName(const string& name);

    string getName();
    void setBounty(int bounty);

    int getBounty() const;
    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
