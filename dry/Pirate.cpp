
#include "Pirate.h"


Pirate::Pirate(const string& name,int bounty): name(name) ,bounty(bounty){}


void Pirate::setName(const string& name){
    this->name = name;
}

void Pirate::setBounty(int bounty) {
    this->bounty = bounty;
}

int Pirate::getBounty() const {
    return bounty;
}

std::string Pirate::getName(){
    return name;
}


std::ostream &operator<<(std::ostream &os, const Pirate &pirate) {
    os << "Pirate: " << pirate.name << ", Bounty: " << pirate.bounty; // Updated output
    return os;
}
