// Interface starter file for Homework 2; due 5pm 1/23/20
// Frankie Fazlollahi

#ifndef SKITTLESBAG_H
#define SKITTLESBAG_H

#include "skittlesdish.h"
#include <iostream>

using std::cout;

class SkittlesBag {
public:
  //Default Constructor
  SkittlesBag();
  //Constructor that takes in the amount of each color skittle to make a bag object
  SkittlesBag(int r, int y, int g, int o, int p);
  //return the total amount of skittles in the entire bag
  int size();
  //return the amount of skittles that are of a particular color in the bag
  int count(char color);
  //prints a histogram of the amount of each color skittle
  void printHistogram();
  //adds 1 skittle to the specified color
  void addOne(char color);
  //removes an amount of skittles of a specific color, if the amount is more than how many skittles there are
  //the amount of skittles of that color is set to 0
  void eat(int amount, char color);
  //finds the skittle color with the least amount of skittles and eats the amount of skittles
  //of each color to make all of the skittles colors the same amount as the one with the least skittles
  //also prints the amount of skittles eaten of each color and the amount of skittles each color has remaining
  void evenOut();
  //adds the amount of skittles of the dish into the matching color of the bag and empties the dish
  void pourInDish(SkittlesDish& dish);
  //empties the contents of the rhs skittles bag into the lhs skittles bag
  void operator +=(SkittlesBag& rhs);
  //checks if the lhs and rhs skittles bags have the same amount of skittles for each of their colors
  bool operator ==(const SkittlesBag& rhs) const;

private:
  SkittlesDish red;
  SkittlesDish yellow;
  SkittlesDish green;
  SkittlesDish orange;
  SkittlesDish purple;
};

#endif
