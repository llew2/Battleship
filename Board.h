//
//  Board.h
//  Battleship
//

#ifndef Battleship__Board_H
#define Battleship__Board_H

#include <iostream>
#include "Ship.h"
#include "Point.h" 
#include "PointCollection.h"
#include <cstdlib>
using namespace std;

class Board
{
  private:
// The ship array. Five pointers to ships
    Ship *ships[5];
    Ship *edge1, *edge2, *edge3, *edge4;
// A PointCollection to store shots fired
    PointCollection shots;
// A helper method: generates ship object with given length, origin and orientation
// that will allow it to fit into current board (Checks for conflicts)
    Ship* generateShipWithLength(int l);   
// Used to generate Ships 
    int xRand, yRand, dirRand, shipLen;
// TempShip Pointer - Use it to check for ship collisions
    Ship *tempShip;
    bool validShip;
    direction orientation;
    point *origin;

// Checks to see if hit was already counted once
    bool hitRegistered;
// Shows all the ships at the initial array
    bool showOnce;
// Checks if a ship was just sunk and what index it was at
    bool justSunk;
    int justSunkNum;
// Checks if point was already shot at previously
    bool shotValid;
// Notifies alert that board that an ai will be playing
//    The subsequent 4 variables power the ai.
    bool isAI;
    PointCollection aiNextShots;
    int aiNextShotsTracker;
    point aiPoint;
    bool getOut;
	
  public:
// A constructor creates five randomly placed
// ships into the ships array of lengths: 5, 4, 3, 3, 2
    Board();
// Updates state to account for a shot at x, y
// Returns true if the shot is a hit. False for a miss
    bool fireShot(int x, int y);

// Returns the number of ships that are
// have not yet been sunk
    int unsunkShipCount();

// Draws a grid display showing hits, misses and empty squares
    void display();

// Alerts the board to the presence of an ai
    void aiActivate() { isAI = true; }
// Stores ai's successive shots
    void aiNextFire(int xList, int yList); 
// Hide from player
    void aiHide() { showOnce = true; };

};

#endif
