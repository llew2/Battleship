//Lawrence Lew
//CS 110B
//Assignment ? - Ship.cpp
//DC: 4/26/2014

#include "Ship.h"
#include <iostream>
using namespace std;

// PointCollection points;
// PointCollection hits;

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) {
  origin = originPoint;
  orientation = o;
  length = l;

  int originX = origin.getX();
  int originY = origin.getY();

// Ship for Horizontal
  if (orientation == HORIZONTAL) {
    for (int i = 0; i < length; i++) {
      points.add(point(originX + i,originY));
    }
  }
// Ship for Vertical
  if (orientation == VERTICAL) {
    for (int i = 0; i < length; i++) {
      points.add(point(originX,originY + i));
    }
  }

/*// Getting Inner Coordinates (Debugging)
  for (int j = 0; j < length; j++) {
    cout << points.get(j).getX() << ", " << points.get(j).getY() << "   |   " ;
  }
  cout << endl;
*/
}

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(const Ship& s) {
  length = s.length;
  orientation = s.orientation;
  origin = s.origin;
  points = s.points;
  hits = s.hits;
}

//*******************************************************************************************
// Contains Point
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const {
// returns true if contains point
  for (int i = 0; i < length; i++)
    if (points.get(i) == p)
      return true;
  return false;
}

//*******************************************************************************************
// Collides With
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const {
// if it returns false, we can place a ship
// if it returns true, we can't place the ship

// We loop through all the points in "our" ship and check against theirs
  // This requires either 2 for loops in either one function or across 2 functions
    // We decided to place 2 for loops across 2 functions
  for (int i = 0; i < length; i++)
    if(s.containsPoint(points.get(i)))
      return true;
//--------------------------------Added------------------------
  return false;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p) {
// if the ship contains this point, we must add it to "hit" list
  if(points.contains(p)) {
    hits.add(p);
    cout << "Ship has been hit" << endl;
  }
  else
    cout << "Missed" << endl;
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p) {
  if (hits.contains(p))
    return true;
  return false;
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const {
  return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s) {
  length = s.length;
  orientation = s.orientation;
  origin = s.origin;
  points = s.points;
  hits = s.hits;
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk() {
//  if (points.getSize() == hits.getSize())
//    cout << "You sunk a ship of length " << length << endl;
  return (points.getSize() == hits.getSize());	
}
