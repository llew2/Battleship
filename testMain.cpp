#include <iostream>
#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <cstdlib>

using namespace std;

int main() {
  bool runAgain = true;
  char ai = 'n';
  int x = 0, y = 0;
  srand(time(NULL));
  int aiX, aiY;

  Board b;

  cout << "\nWelcome to Battleship\n\n";

  cout << "Do you want to play with the AI?(y/n): ";
  cin >> ai;

  if(ai == 'n') {
    cout << "\nWe've set up your ships for you below!\n\n";
    b.display();

    do {
      if(b.unsunkShipCount() == 0) {
        runAgain = false;
        cout << "Congratulations! You sunk all the ships! " << endl;
      }

      b.display();

      cout << "Enter a coordinate: ";
      cin >> x >> y;
      if (b.fireShot(x,y))
        cout << "Hit!" << endl;
      else
        cout << "Miss." << endl;

    }while (runAgain && ai != 'y');
  }
//----------------------------------AI----------------
// This is the segment to enable ai
  else {
    b.aiHide();
    cout << "You have chosen to enable AI. Setting up now.\n";
    Board aiPlayer;
    aiPlayer.display();
// Supress b's board, diplay aiPlayer display first one, not second
// Turns on AI
    aiPlayer.aiActivate();
// Shows where user's ships are placed
    b.display();

    do {
// Evaluate Victory Conditions
      if(b.unsunkShipCount() == 0) {
        runAgain = false;
        cout << "Congratulations! You sunk all the ships! " << endl;
      }
      else if(aiPlayer.unsunkShipCount() == 0) {
        runAgain = false;
        cout << "Sorry... You lost. " << endl;
      }

      if(runAgain) {
        cout << "Enter a coordinate: ";
        cin >> x >> y;
        if (b.fireShot(x,y))
          cout << "Hit!" << endl;
        else
          cout << "Miss." << endl;

        cout << "\nThis is the AI's Board you are shooting at.\n";
        b.display();
        cout << "\n-----------------Computer's turn!----------------\n\n";

//  Time to generate random ai ships shots
        aiX = int(rand() % 10);
        aiY = int(rand() % 10); 
        aiPlayer.fireShot(aiX,aiY); 

        cout << "\nThis is your board which the AI is shooting at.\n";
        aiPlayer.display();

        cout << "\n-----------------User's turn!--------------------\n\n";
      }
    }while (runAgain && ai == 'y');
  }
  return 0;
}
