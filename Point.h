//
//  Point.h
//  Battleship
//

#ifndef Battleship_Point_H
#define Battleship_Point_H

class point
{
  private:
    
    int x;
    int y;
    
  public:
    point() {
        x = 0;
        y = 0;
    }
    
    point(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }
    
    bool operator==(const point &p) const {
//        return (x == p.x) && (y == p.y);
        return (x == p.getX()) && (y == p.getY());
    }
    
    void setX(int value) {
        x = value;
    }
    
    int getX() const {
        return x;
    }
    
    void setY(int value) {
        y = value;
    }
    
    int getY() const {
        return y;
    }
    
};

#endif
