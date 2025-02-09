#ifndef ZOMBIE_CLARK_H
#define ZOMBIE_CLARK_H

#include <iostream>
#include <string>

using namespace std;

class Zombie
{
private:
    char type;

public:
    // Constructors
    Zombie();
    Zombie(char new_type);
    // Get zombie type
    char getType();
    // Object compare
    bool operator==(Zombie &);
    // Object print
    friend ostream &operator<<(ostream &, const Zombie &);
};
#endif