//
//  PointCollection.h
//  Battleship
//

#ifndef POINT_COLLECTION_H
#define POINT_COLLECTION_H

#include "Point.h"

class PointCollection
{
private:
    int size;
    int capacity;
    point* data;
    
    void doubleArraySize();
    
public:
    PointCollection();
    PointCollection(const PointCollection& c);
    ~PointCollection();

    
    void add(const point &p);
    point& get(int index) const;
    
    int getSize() const;
    
    bool contains(const point &p) const;
    
    PointCollection& operator<<(const point &p);
    point& operator[](int index) const;
    const PointCollection& operator=(const PointCollection &c);
};

#endif
