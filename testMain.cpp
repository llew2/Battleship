#include <iostream>
#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"

using namespace std;

int main() {
  bool runAgain = true;
  int x = 0, y = 0;

  Board b;
  b.display();
  cout << "Welcome to Battleship\n\n";
  do {
    if(b.unsunkShipCount() == 0) {
      runAgain = false;
    }

    b.display();

    cout << "Enter a coordinate: ";
    cin >> x >> y;
    if (b.fireShot(x,y))
      cout << "Hit!" << endl;
    else
      cout << "Miss." << endl;



  }while (runAgain);


  return 0;
}
