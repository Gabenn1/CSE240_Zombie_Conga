/*
Name: Gabriel Clark
Date: 12/01/23
Description: Zombie Class Header
Usage: 
*/

#include "zombie_clark.h"
#include <iostream>

// Constructors
Zombie::Zombie() : type() {}
Zombie::Zombie(char new_type) : type(new_type) {}

// Returns Zombie type
char Zombie::getType()
{
    return type;
}
// Compares zombie objects
bool Zombie::operator==(Zombie &other)
{
    return type == other.getType();
}

// Zombie print overload method
std::ostream &operator<<(std::ostream &out, const Zombie &z)
{
    out << z.type;
    return out;
}