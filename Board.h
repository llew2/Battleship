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
// A helper method that generates a ship object with
// the given length, origin and orientation
// that will allow it to fit into current board
    Ship* generateShipWithLength(int l);    
    int xRand, yRand, dirRand, shipLen;
// TempShip Pointer
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

  public:
// A constructor creates five randomly placed
// ships into the ships array of lengths: 5, 4, 3, 3, 2
    Board() {
      srand(time(NULL)); 
      hitRegistered = false;
      showOnce = false;
      justSunk = false;
      justSunkNum = -1;
      
// Setting up borders for battleship (horizontal then vertical border)
      edge1 = new Ship(point(0,10),HORIZONTAL,10);
      edge2 = new Ship(point(10,0),VERTICAL,10);
      edge3 = new Ship(point(0,-1),HORIZONTAL,10);
      edge4 = new Ship(point(-1,0),VERTICAL,10);

// Generating random ships
      for (int i = 0; i < 5; i++) {
        validShip = true;
        xRand = (int) (rand() % 10);
        yRand = (int) (rand() % 10);
        origin = new point(xRand,yRand);
// Set the direction of the ship
        dirRand = (int) (rand() % 2);
        if (dirRand == 0) {
          orientation = HORIZONTAL;
          cout << "Orientation is hori";
        }
        else {
          orientation = VERTICAL;
          cout << "Ori is vert";
        }
// Set the length of the ship
// Let's try to shorten this section
        if (i == 0) shipLen = 5;
        if (i == 1) shipLen = 4;
        if (i == 2) shipLen = 3;
        if (i == 3) shipLen = 3;
        if (i == 4) shipLen = 2;
        cout << endl;
        cout << "Ship test " << xRand << " " << yRand << " " << shipLen << " " << orientation << endl;
// Generate the random ship
        cout << "Origin True: " << origin->getX() << " " << origin->getY() << endl;
        tempShip = new Ship(*origin, orientation, shipLen);
// Check to see if collisions occur
        if(tempShip->collidesWith(*edge1) || tempShip->collidesWith(*edge2)) {
            cout << "Has hit edge EDGE ship " << endl;
            i--;
            validShip = false;
        }
/*  Ships will never reach negative edge
        if(tempShip->collidesWith(*edge3) || tempShip->collidesWith(*edge4)) {
            cout << "Has hit edge EDGE 3 4 SHIP " << endl;
            i--;
            validShip = false;
        }
*/
        for(int j = 0; j < i; j++) {
          if (tempShip->collidesWith(*(ships[j]))) {
            j = i;
            cout << "Has hit edge ship " << endl;
//            i--;
          }
          if(j == i) {
            i--;
            validShip = false;
          }
        }
        if(validShip == true){
          ships[i] = tempShip;
          cout << "Ship created succesfully: " << xRand << " " << yRand << " " << shipLen << " " << orientation << "<--------- :) " << endl; 
        }
        cout << endl;
      }

    }
      
// Updates state to account for a shot at x, y
// Returns true if the shot is a hit. False for a miss
    bool fireShot(int x, int y) {

      for (int i = 0; i < 5; i++) {
        if(ships[i]->containsPoint(point(x,y))) {	//Checks if point exist
          if(ships[i]->isHitAtPoint(point(x,y)) == false) {		//Checks if hit before
            ships[i]->shotFiredAtPoint(point(x,y));	//Registers "hit"
            cout << "You hit the ship at Point " << x << ", " << y << endl;
            shots.add(point(x,y));
            return true;
          }
          cout << "You already hit this point before!" << endl;
        }
      }
      shots.add(point(x,y));
      return false;

   }

// Returns the number of ships that are
// have not yet been sunk
    int unsunkShipCount() {
///*
      int count = 5;
      for (int i = 0; i < 5; i++) {
        if(ships[i]->isSunk())
          count--;
      }
      return count;
    }
//*/

// Draws a grid display showing hits, misses and empty squares
    void display() {
      cout << endl;
// Starts Filling in Grid (Top row to bottom)
      for (int i = 9; i >= -1; i--) {
// Left to right
        for (int j = -1; j <= 9; j++) {
// Print y coordinates on the left
// We need to print out the bottom 
    // This segment ensures the x-axis and y-axis numbers are displayed
          if(i == -1 && j == -1) {cout<< " ";}
          else if (i == -1)                 
            cout << " " << j;
//          else if (j == -1 && i >= 0) {
          else if(j == -1 && i >=0) {      
            cout << i;
          } 

// Checks shots fired and ships (Draws the board with ~, X and .)
// Code segment displays ship once in the beginning with "0"

          if(showOnce == false) {
            for(int l = 0; l < 5; l++) {
              if (ships[l]->containsPoint(point(j,i))) {
                cout << " O";
                hitRegistered = true;
              }
            }
            if (hitRegistered == false && i > -1 && j > -1)
              cout << " ~";
            hitRegistered = false; 
          }

//          if (shots.contains(point(j, 9-i))) {
// Displays the "shots" fired by player and evaluates whether it was a hit or miss
          else if(shots.contains(point(j,i))) {
            for (int k = 0; k < 5; k++) {
              if (ships[k]->containsPoint(point(j, i))) {
                cout << " X";
                hitRegistered = true;
                if (ships[k]->isSunk()) {
                // Keep track of a ship that was just sunk
                  justSunk = true;
                  justSunkNum = k;
                }
                k = 5;
              }
            }
// If there wasn't a ship shot, it must have been a miss
            if (hitRegistered == false)
              cout << " .";
          }
// If it wasn't a ship or a missed shot, it must not have been shot at yet.
          else if (i > -1 && j > -1)
            cout << " ~";
          hitRegistered = false; 
        }
        cout << endl;
      }
      if(justSunk) {
        justSunk = false;
        cout << "You sunk a ship with length " << ships[justSunkNum]->hitCount() << "!" << endl;
        justSunkNum = -1;
      }

      showOnce = true;
    }
};

#endif
