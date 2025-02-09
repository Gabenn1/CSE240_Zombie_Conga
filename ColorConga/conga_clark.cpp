#include "zombie_clark.h"
#include "linkedlist_clark.hpp"
#include "conga_clark.h"
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>

using namespace std;

// Randomly give Zombie type based on D6 roll
char zombie_type()
{
    char color;
    int zombieType = (rand() % 6);
    switch (zombieType)
    {
    case 0: // if 0, red
    {
        color = 'R';
        break;
    }
    case 1: // if 1, yellow
    {
        color = 'Y';
        break;
    }
    case 2: // if 2, green
    {
        color = 'G';
        break;
    }
    case 3: // if 3, blue
    {
        color = 'B';
        break;
    }
    case 4: // if 4, cyan
    {
        color = 'C';
        break;
    }
    case 5: // if 5, magenta
    {
        color = 'M';
        break;
    }
    }
    return color;
}
// This zombie becomes the first zombie in the conga line
void engine_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.AddToFront(randZombie);
}

// This zombie becomes the last zombie in the conga line
void caboose_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.AddToEnd(randZombie);
}

// This zombie joins the conga line at position X where X <= length of the linked list
void jump_in_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    int index = (rand() % (lst.Length() + 1));
    lst.AddAtIndex(randZombie, index);
}

// Remove all matching zombies from the linked list
void everyone_out_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.RemoveAllOf(randZombie);
}

// Remove the first matching zombie from the linked list
void you_out_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.RemoveTheFirst(randZombie);
}

// Generate two more matching Zombies and add one to the front (engine_action), one to the end (caboose_action) and one to the middle (round down).
void brains_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    Zombie z1 = randZombie.getType();
    Zombie z2 = randZombie.getType();
    int index = floor(lst.Length() / 2);     // add to middle of list rounded down
    lst.AddToFront(z1);                      // Engine Action
    lst.AddToEnd(z2);                        // Caboose Action
    lst.AddAtIndex(randZombie, (index + 1)); // Middle of list rounded down
}

// Perform an engine_action on the zombie that was generated. Add one of each zombie color to the end via caboose_action in this order: Red, Yellow, Green, Blue, Cyan, Magenta
void rainbow_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    Zombie zombieR('R');
    Zombie zombieY('Y');
    Zombie zombieG('G');
    Zombie zombieB('B');
    Zombie zombieC('C');
    Zombie zombieM('M');
    lst.AddToFront(randZombie);
    lst.AddToEnd(zombieR);
    lst.AddToEnd(zombieY);
    lst.AddToEnd(zombieG);
    lst.AddToEnd(zombieB);
    lst.AddToEnd(zombieC);
    lst.AddToEnd(zombieM);
}

// Find the first Zombie of this color in line. Do a coin flip – if rand() % 2 == 0 then insert before, else insert after. If no Zombie of that color exists, then perform caboose_action on the zombie
void friends_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    // If the passed zombie exists in the list, flip the coin
    if (lst.ElementExists(randZombie.getType()) == true)
    {
        if (rand() % 2 == 0)
        {
            lst.AddBefore(lst.Find(randZombie), randZombie);
        }
        else
        {
            lst.AddAfter(lst.Find(randZombie), randZombie);
        }
    }
    // if zombie doesnt exist in list, add to the end
    else
    {
        lst.AddToEnd(randZombie);
    }
}
