//
//  Board.cpp
//  Battleship
//

#include "Board.h"

Board::Board() {
    srand(time(NULL));
    hitRegistered = false;
    showOnce = false;
// Checks to see if a ship just sunk and display it's length based on index - justSunkNum
    justSunk = false;
    justSunkNum = -1;
// Dummy assignment to check if shot was valid (i.e. was not shot at before)
    shotValid = false;
// Assumes no AI until manually activated
    isAI = false;
    aiNextShotsTracker = 0;
    getOut = false;

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
      }
      else {
        orientation = VERTICAL;
      }
// Set the length of the ship
// Let's try to shorten this section
      if (i == 0) shipLen = 5;
      if (i == 1) shipLen = 4;
      if (i == 2) shipLen = 3;
      if (i == 3) shipLen = 3;
      if (i == 4) shipLen = 2;
// Generate the random ship
      tempShip = new Ship(*origin, orientation, shipLen);

// Check to see if collisions with edges will occur
      if(tempShip->collidesWith(*edge1) || tempShip->collidesWith(*edge2)) {
          i--;
          validShip = false;
      }
// Ships will reach negative edge when dealing with ai
      if(tempShip->collidesWith(*edge3) || tempShip->collidesWith(*edge4)) {
          i--;
          validShip = false;
      }

// Checks collision with each ship
      for(int j = 0; j < i; j++) {
        if (tempShip->collidesWith(*(ships[j]))) {
          j = i;
        }
// If ships collide, immediately remove it and generate another random ship
        if(j == i) {
          i--;
          validShip = false;
        }
      }
// If this ship is valid, assign it to the pointer ships
      if(validShip == true){
        ships[i] = tempShip;
      }
    }
  }


// Updates state to account for a shot at x, y
// Returns true if the shot is a hit. False for a miss
bool Board::fireShot(int x, int y) {
// If the point has already been chosen, reprompt user for another
// AI's method for generating shot if shot has already been called

    do {
      if (aiNextShotsTracker < aiNextShots.getSize()) {
// If there are good next shots to take, the ai will take them!
        aiPoint = aiNextShots.get(aiNextShotsTracker);
        x = aiPoint.getX();
        y = aiPoint.getY();
// Increment so we use a different "hunting/good shot" next time.
        aiNextShotsTracker++;
        cout << "HERE'S SOME PROOF!!: " << aiNextShotsTracker << "  " << aiNextShots.getSize();
      }
      if (aiNextShotsTracker >= aiNextShots.getSize())
        getOut = true;
    } while (shots.contains(point(x,y)) && isAI == true && !(getOut == true));
// Resets Escape variable
    getOut = false;

    while ((shots.contains(point(x,y)) && isAI == true) || x < 0 || x >= 10 || y < 0 || y >= 10) {
      do {
// If there are good next shots to take, the ai will take them!
        if (aiNextShotsTracker < aiNextShots.getSize()) {
          aiPoint = aiNextShots.get(aiNextShotsTracker);
          x = aiPoint.getX();
          y = aiPoint.getY();
// Increment so we use a different "hunting/good shot" next time.
          aiNextShotsTracker++;
        }
// Allows AI to get out if it runs out of next shots, with the last one being invalid
        if (aiNextShotsTracker > aiNextShots.getSize())
          getOut = true;
      } while ((x < 0 || x >= 10 || y < 0 || y >= 10) && !(getOut == true));

// If there are no good shots to select from, FIRE AWAY!
      if ((aiNextShotsTracker + 1) >= aiNextShots.getSize()) {
        x = (int)(rand() % 10);
        y = (int)(rand() % 10);
      }      
    }
// Resets the escape variable so the AI can use it again the next time
    getOut = false;
// ---------------------------fireShot for user------------------------
    while ((shots.contains(point(x,y))) || (x < 0 || x >= 10 || y < 0 || y >= 10)) {
      if(x < 0 || x >=10 || y < 0 || y >=10) {
        cout << "You can't select points outside the board. Pick another!:";
        cin >> x >> y;
      }
      else {
        cout << "You already hit this point before! Pick another!: ";
        cin >> x >> y;
      }
    }

// ---------------------------fireShot for all----------------------------
    cout << "Checking shot fired\n";
    for (int i = 0; i < 5; i++) {
      if(ships[i]->containsPoint(point(x,y))) {               //Checks if any ship has this point
        if(ships[i]->isHitAtPoint(point(x,y)) == false) {     //Checks if ship has been hit
            ships[i]->shotFiredAtPoint(point(x,y));           //Registers "hit" if not hit
            if (isAI == false)
              cout << "You hit the ship at Point " << x << ", " << y << endl;
// If there is an AI, we register the new sets of possible nextshots
            if (isAI == true) {
              aiNextShots.add(point(x+1,y));
              aiNextShots.add(point(x,y+1));
              aiNextShots.add(point(x-1,y));
              aiNextShots.add(point(x,y-1));
              cout << "Computer Hit!\n   Shots fired at: " << x << ", " << y << endl;
              cout << x+1 << y << x << y+1 << x-1 << y << x << y-1 << " have been added." << endl;
            }
            shots.add(point(x,y));
// Informs user if ship has been successfully sunk
            if (ships[i]->isSunk()) {
              cout << "You sunk a ship with length " << ships[i]->hitCount() << "!" << endl;
            }
            return true;
        }
      }
    }
  shots.add(point(x,y));
  if(isAI == true)
    cout << "Computer Miss.\n   Shots fired at: " << x << ", " << y << endl;
  return false;
}

// ---------------------------------unsunkShipCount---------------------------
// Returns the number of ships that are have not yet been sunk
int Board::unsunkShipCount() {
    int count = 5;
    for (int i = 0; i < 5; i++)
      if(ships[i]->isSunk())
        count--;
    return count;
}

// -----------------------------display--------------------------------------
// Draws a grid display showing hits, misses and empty squares
void Board::display() {
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

// Displays the "shots" fired by player and evaluates whether it was a hit or miss
        else if(shots.contains(point(j,i))) {
          for (int k = 0; k < 5; k++) {
            if (ships[k]->containsPoint(point(j, i))) {
              cout << " X";
              hitRegistered = true;
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
    showOnce = true;
}
