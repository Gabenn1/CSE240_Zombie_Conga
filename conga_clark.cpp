#include "zombie_clark.h"
#include "linkedlist_clark.hpp"
#include "conga_clark.h"
#include <math.h>

using namespace std;

char zombie_type()
{
    char color;
    int zombieType = (rand() % 6);
    switch (zombieType)
    {
    case 0: color = 'R'; break;
    case 1: color = 'Y'; break;
    case 2: color = 'G'; break;
    case 3: color = 'B'; break;
    case 4: color = 'C'; break;
    case 5: color = 'M'; break;
    }
    return color;
}

void engine_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.AddToFront(randZombie);
}

void caboose_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.AddToEnd(randZombie);
}

void jump_in_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    int index = rand() % (lst.Length() + 1);
    lst.AddAtIndex(randZombie, index);
}

void everyone_out_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.RemoveAllOf(randZombie);
}

void you_out_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    lst.RemoveTheFirst(randZombie);
}

void brains_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    Zombie z1 = randZombie.getType();
    Zombie z2 = randZombie.getType();
    int index = floor(lst.Length() / 2);
    lst.AddToFront(z1); 
    lst.AddToEnd(z2);  
    lst.AddAtIndex(randZombie, index); 
}

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

void friends_action(LinkedList<Zombie> &lst, Zombie randZombie)
{
    if (lst.ElementExists(randZombie.getType()))
    {
        Node<Zombie>* found = lst.Find(randZombie);
        if (found != nullptr)
        {
            if (rand() % 2 == 0)
            {
                lst.AddBefore(found, randZombie);
            }
            else
            {
                lst.AddAfter(found, randZombie);
            }
        }
        else
        {
            lst.AddToEnd(randZombie);
        }
    }
    else
    {
        lst.AddToEnd(randZombie);
    }
}
