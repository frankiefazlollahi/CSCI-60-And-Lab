// Implementation starter file for Homework 2; due 5pm 1/23/20
// Frankie Fazlollahi

#include "skittlesbag.h"

SkittlesBag::SkittlesBag() : red(0, "red"), yellow(0,"yellow"), green(0,"green"), orange(0,"orange"), purple(0,"purple"){}

SkittlesBag::SkittlesBag(int r, int y, int g, int o, int p): red(r, "red"), yellow(y, "yellow"), green(g, "green"), orange(o,"orange"), purple(p,"purple"){}

int SkittlesBag::size()
{
  return (red.getCount() + yellow.getCount() + green.getCount() + orange.getCount() + purple.getCount());
}

int SkittlesBag::count(char color)
{
  if(color == 'r')
  {
    return red.getCount();
  }
  else if(color == 'y')
  {
    return yellow.getCount();
  }
  else if(color == 'g')
  {
    return green.getCount();
  }
  else if(color == 'o')
  {
    return orange.getCount();
  }
  else if(color == 'p')
  {
    return purple.getCount();
  }
  else
  {
    return 0;
  }
}

void SkittlesBag::printHistogram()
{
  cout << "r: ";
  for(int i = 0; i < red.getCount(); i++)
  {
    cout << "*";
  }
  cout << endl;
  cout << "y: ";
  for(int i = 0; i < yellow.getCount(); i++)
  {
    cout << "*";
  }
  cout << endl;
  cout << "g: ";
  for(int i = 0; i < green.getCount(); i++)
  {
    cout << "*";
  }
  cout << endl;
  cout << "o: ";
  for(int i = 0; i < orange.getCount(); i++)
  {
    cout << "*";
  }
  cout << endl;
  cout << "p: ";
  for(int i = 0; i < purple.getCount(); i++)
  {
    cout << "*";
  }
  cout << endl;
}

void SkittlesBag::addOne(char color){
  if(color == 'r')
  {
    red.addSkittles(1);
  }
  else if(color == 'y')
  {
    yellow.addSkittles(1);
  }
  else if(color == 'g')
  {
    green.addSkittles(1);
  }
  else if(color == 'o')
  {
    orange.addSkittles(1);
  }
  else if(color == 'p')
  {
    purple.addSkittles(1);
  }
  /*else
  {
    cout << "Error: Invalid color (r/g/y/o/p)" << endl;
  }*/
}

void SkittlesBag::eat(int amount, char color)
{
  if(color == 'r')
  {
    if(red.getCount() < amount)
    {
      red.eatSkittles(red.getCount());
    }
    else
    {
      red.eatSkittles(amount);
    }
  }
  else if(color == 'y')
  {
    if(yellow.getCount() < amount)
    {
      yellow.eatSkittles(yellow.getCount());
    }
    else
    {
      yellow.eatSkittles(amount);
    }
  }
  else if(color == 'g')
  {
    if(green.getCount() < amount)
    {
      green.eatSkittles(green.getCount());
    }
    else
    {
      green.eatSkittles(amount);
    }
  }
  else if(color == 'o')
  {
    if(orange.getCount() < amount)
    {
      orange.eatSkittles(orange.getCount());
    }
    else
    {
      orange.eatSkittles(amount);
    }
  }
  else if(color == 'p')
  {
    if(purple.getCount() < amount)
    {
      purple.eatSkittles(purple.getCount());
    }
    else
    {
      purple.eatSkittles(amount);
    }
  }
  /*else
  {
      cout << "Error: Invalid color (r/g/y/o/p)" << endl;
  }*/
}

void SkittlesBag::evenOut()
{
  int rEaten, yEaten, gEaten, oEaten, pEaten;
  int min = red.getCount();
  if(min > yellow.getCount())
  {
    min = yellow.getCount();
  }
  if(min > green.getCount())
  {
    min = green.getCount();
  }
  if(min > orange.getCount())
  {
    min = orange.getCount();
  }
  if(min > purple.getCount())
  {
    min = purple.getCount();
  }
  rEaten = red.getCount() - min;
  red.eatSkittles(rEaten);
  yEaten = yellow.getCount() - min;
  yellow.eatSkittles(yEaten);
  gEaten = green.getCount() - min;
  green.eatSkittles(gEaten);
  oEaten = orange.getCount() - min;
  orange.eatSkittles(oEaten);
  pEaten = purple.getCount() - min;
  purple.eatSkittles(pEaten);
  cout << rEaten << " red eaten" << endl;
  cout << yEaten << " yellow eaten" << endl;
  cout << gEaten << " green eaten" << endl;
  cout << oEaten << " orange eaten" << endl;
  cout << pEaten << " purple eaten" << endl;
  cout << min << " of each remaining" << endl;
}

void SkittlesBag::pourInDish(SkittlesDish& dish)
{
  if(dish.getColor() == "red")
  {
    red+=dish;
  }
  else if(dish.getColor() == "yellow")
  {
    yellow+=dish;
  }
  else if(dish.getColor() == "green")
  {
    green+=dish;
  }
  else if(dish.getColor() == "orange")
  {
    orange+=dish;
  }
  else if(dish.getColor() == "purple")
  {
    purple+=dish;
  }
}

void SkittlesBag::operator +=(SkittlesBag& rhs)
{
  red.addSkittles(rhs.red.getCount());
  rhs.red.eatSkittles(rhs.red.getCount());
  yellow.addSkittles(rhs.yellow.getCount());
  rhs.yellow.eatSkittles(rhs.yellow.getCount());
  green.addSkittles(rhs.green.getCount());
  rhs.green.eatSkittles(rhs.green.getCount());
  orange.addSkittles(rhs.orange.getCount());
  rhs.orange.eatSkittles(rhs.orange.getCount());
  purple.addSkittles(rhs.purple.getCount());
  rhs.purple.eatSkittles(rhs.purple.getCount());
}

bool SkittlesBag::operator ==(const SkittlesBag& rhs) const
{
  if(red.getCount() == rhs.red.getCount() && yellow.getCount() == rhs.yellow.getCount() && green.getCount() == rhs.green.getCount()
  && orange.getCount() == rhs.orange.getCount() && purple.getCount() == rhs.purple.getCount())
  {
    return true;
  }
  return false;
}
