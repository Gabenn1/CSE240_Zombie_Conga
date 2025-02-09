/*
Name: Gabriel Clark
Date: 12/01/23
Description: Conga Function Header
Usage:
*/

#ifndef CONGA_CLARK_H
#define CONGA_CLARK_H
#include "zombie_clark.h"
#include "linkedlist_clark.hpp"

char zombie_type();

// This zombie becomes the last zombie in the conga line
void engine_action(LinkedList<Zombie> &, Zombie);

// This zombie becomes the last zombie in the conga line
void caboose_action(LinkedList<Zombie> &, Zombie);

// This zombie joins the conga line at position X where X <= length of the linked list
void jump_in_action(LinkedList<Zombie> &, Zombie);

// Remove all matching zombies from the linked list
void everyone_out_action(LinkedList<Zombie> &, Zombie);

// Remove the first matching zombie from the linked list
void you_out_action(LinkedList<Zombie> &, Zombie);

// Generate two more matching Zombies and add one to the front (engine_action), one to the end (caboose_action) and one to the middle (round down).
void brains_action(LinkedList<Zombie> &, Zombie);

// Perform an engine_action on the zombie that was generated. Add one of each zombie color to the end via caboose_action in this order: Red, Yellow, Green, Blue, Cyan, Magenta
void rainbow_action(LinkedList<Zombie> &, Zombie);

// Find the first Zombie of this color in line. Do a coin flip – if rand() % 2 == 0 then insert before, else insert after.
// If no Zombie of that color exists, then perform caboose_action on the zombie
void friends_action(LinkedList<Zombie> &, Zombie);

#endif