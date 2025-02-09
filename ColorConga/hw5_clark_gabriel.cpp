/*
Name: Gabriel Clark
Date: 12/01/23
Description:
Usage:
*/
#include <cstring>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <iostream>
#include "termcolor.hpp"
#include <string>
#include <cmath>
#include "linkedlist_clark.hpp"
#include "zombie_clark.h"
#include "conga_clark.h"
using namespace std;

void congaGame(int);
// void continueGame();
void zombieFight();

int main(int argc, char *argv[])
{
  int rounds;
  std::cout << termcolor::colorize;

  // If incorrect usage is input
  if (argc != 1 && argc != 3 && argc != 4)
  {
    cout << "Usage error: ./exe <-s> <seed number> <-EC>";
    exit(-1);
  }
  // Seeding prompt
  if (argc == 3 && (strcmp(argv[1], "-s") == 0))
  {
    srand(atoi(argv[2]));
  }
  else
  {
    srand(time(0));
  }
  // Zombie fight argv
  if (argc == 4 && strcmp(argv[3], "-EC") == 0)
  {
    cout << "LETS GET READY TO RUMBLE!!!";
    zombieFight();
    return 0;
  }
  // Promt user for how many round they want to play, run game with that many rounds
  cout << "How many rounds would you like to run?" << endl;
  cin >> rounds;
  congaGame(rounds);

  return 0;
}

void congaGame(int rounds)
{
  int nextRound;
  string roundName;
  char newZombie;
  int currentRound = 0;
  Zombie randZombie = zombie_type();
  LinkedList<Zombie> lst;

  // Intializing game
  rainbow_action(lst, randZombie);
  for (int i = 0; i < 3; i++)
  {
    Zombie randZombie = zombie_type();
    brains_action(lst, randZombie);
    lst.PrintList();
    cout << endl;
  }
  // Playing each round
  while (currentRound <= rounds)
  {
    // If the list ever empties
    if (lst.Length() == 0)
    {
      cout << "The Party is Over!";
      exit(1);
    }

    // Remove front and end if round % 5 == 0
    if (currentRound % 5 == 0)
    {
      lst.RemoveFromFront();
      lst.RemoveFromEnd();
    }
    cout << "Round: " << currentRound << endl;
    cout << "Size: " << lst.Length() << " :: ";
    lst.PrintColorList();
    // Rolling for next round
    nextRound = rand() % 8;

    switch (nextRound)
    {
    case 0: // if roll is 0, Engine!
    {
      roundName = "Engine!";
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      engine_action(lst, randZombie);
      break;
    }
    case 1: // if roll is 1, Caboose!
    {
      roundName = "Caboose!";
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      caboose_action(lst, randZombie);
      break;
    }
    case 2: // if roll is 2, Jump in!
    {
      roundName = "Jump in!";
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      jump_in_action(lst, randZombie);
      break;
    }
    case 3: // if roll is 3, Everyone Out!
    {
      roundName = "Everyone Out!";
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      everyone_out_action(lst, randZombie);
      break;
    }
    case 4: // if roll is 4, You out!
    {
      roundName = "You out!";
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      you_out_action(lst, randZombie);
      break;
    }
    case 5: // if roll is 5, Brains!
    {
      roundName = "Brains!";
      //Create new zombie
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      brains_action(lst, randZombie);
      break;
    }
    case 6: // if roll is 6, Rainbow!
    {
      roundName = "Rainbow!";
      //Create new zombie
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      rainbow_action(lst, randZombie);
      break;
    }
    case 7: // if roll is 7, Making New Friends!
    {
      roundName = "Making New Friends!";
      //Create new zombie
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      friends_action(lst, randZombie);
      break;
    }
      //Zombie randZombie = zombie_type();
    }
    // Print game outline
    cout << endl;
    cout << "New Zombie:  "
         << "[" << newZombie << "]"
         << " -- Action: "
         << "[" << roundName << "]" << endl;
    cout << "The conga line is now:" << endl;
    cout << "Size: " << lst.Length() << " :: ";
    lst.PrintColorList();
    cout << endl;
    cout << "**************************************************" << endl;
    // Increment the round
    currentRound++;
  }
  // Empty the list when number of rounds is reached
  lst.Empty();
  // continueGame();
}

// void continueGame()
// {
//   int rounds;
//   char status;

//   cout << "Play Again?  Y/N?" << endl;
//   cin >> status;

//   if (status == 'Y' || status == 'y')
//   {
//     cout << "How many rounds would you like to run?" << endl;
//     cin >> rounds;
//     congaGame(rounds);
//   }
//   else if (status == 'N' || status == 'n')
//   {
//     cout << "Thanks for Playing ZOMBIE CONGA!";
//     exit(1);
//   }
//   else if (status != 'Y' && status != 'N' && status != 'y' && status != 'n')
//   {
//     cout << "Please Enter Y or N" << endl;
//     continueGame();
//   }
// }

void zombieFight()
{
  int nextRound;
  string roundName;
  char newZombie;
  int currentRound = 0;
  Zombie randZombie = zombie_type();
  LinkedList<Zombie> lst;

  // Intializing game
  rainbow_action(lst, randZombie);
  for (int i = 0; i < 3; i++)
  {
    Zombie randZombie = zombie_type();
    brains_action(lst, randZombie);
  }

  while (currentRound < 1000)
  {
    // Remove front and end if round % 5 == 0
    if (currentRound % 5 == 0)
    {
      lst.RemoveFromFront();
      lst.RemoveFromEnd();
    }
    nextRound = rand() % 8;

    switch (nextRound)
    {
    case 0:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      engine_action(lst, randZombie);
      break;
    }
    case 1:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      caboose_action(lst, randZombie);
      break;
    }
    case 2:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      jump_in_action(lst, randZombie);
      break;
    }
    case 3:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      everyone_out_action(lst, randZombie);
      break;
    }
    case 4:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      you_out_action(lst, randZombie);
      break;
    }
    case 5:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      brains_action(lst, randZombie);
      break;
    }
    case 6:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      rainbow_action(lst, randZombie);
      break;
    }
    case 7:
    {
      Zombie randZombie = zombie_type();
      newZombie = randZombie.getType();
      friends_action(lst, randZombie);
      break;
    }
    }
    currentRound += 1;
  }
  cout << "made it this far" << endl;
  lst.CountList();
}
