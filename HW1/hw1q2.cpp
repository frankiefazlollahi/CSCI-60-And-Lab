// Starter file for Homework 1, Question 2; due before class 1/15/20
// Frankie Fazlollahi

#include <iostream>
#include <string>
using namespace std;

class MazeRacer
{
public:
  MazeRacer(string n)
  {
    name = n;
    startX = 0;
    startY = 0;
    moves = 0;
  }
  MazeRacer(string n, int sx, int sy)
  {
    name = n;
    startX = sx;
    startY = sy;
    moves = 0;
  }
  int getPosX(){return startX;}
  void setX(int x){startX = x;}
  void setY(int y){startY = y;}
  int getPosY(){return startY;}
  string getName(){return name;}
  int getMoves(){return moves;}
  void setMoves(int n) {moves = n;}

private:
  string name;
  int startX;
  int startY;
  int moves;
};

void moveRacer(MazeRacer& racer);
void checkDestination(MazeRacer racer, int tx, int ty);

int main() {
  string name1;
  string name2;
  int sX2, sY2;
  int tx, ty;
  // first get name then construct racer1 accordingly
  cout << "Enter a name for the first maze competitor: " << endl;
  cin >> name1;
  cout << name1 << " will start at (0,0).\n";
  MazeRacer racer1(name1);

  // get name and coordinates; construct racer2 accordingly
  cout << "Enter a name for the second maze competitor: " << endl;
  cin >> name2;
  cout << "Enter starting coordinates for " << name2 << " (x,y): " << endl;
  cin >> sX2;
  cin >> sY2;
  cout << "Enter the target coordinates (x,y): " << endl;
  cin >> tx;
  cin >> ty;
  MazeRacer racer2(name2, sX2, sY2);
  // implement moveRacer to get move sequence from user
  moveRacer(racer1);
  moveRacer(racer2);

  // implement checkDestination to see whether targets are reached
  checkDestination(racer1, tx, ty);
  checkDestination(racer2, tx, ty);
  return 0;
}

// get move sequence from user and move racer accordingly
void moveRacer(MazeRacer& racer) {
  cout << "Enter a sequence of moves (LRUD) for " << racer.getName() << endl;
  string seq;
  cin >> seq;
  int x = racer.getPosX();
  int y = racer.getPosY();
  for (int i=0; i<seq.length(); i++)
  {
    // move racer depending on the direction specified by seq.at(i)
    if(seq.at(i) == 'L')
    {
      x--;
    }
    else if(seq.at(i) == 'R')
    {
      x++;
    }
    else if (seq.at(i) == 'U')
    {
      y++;
    }
    else if(seq.at(i) == 'D')
    {
      y--;
    }
  }
  racer.setX(x);
  racer.setY(y);
  racer.setMoves(seq.length());
}

// report whether racer is at (tx,ty)
void checkDestination(MazeRacer racer, int tx, int ty) {
  if (racer.getPosX() == tx && racer.getPosY() == ty)
  { // replace this condition with an appropriate one
    cout << racer.getName() << " was at the target after " << racer.getMoves() << " moves." << endl;
  }
  else
   {
    cout << racer.getName() <<  " was not at the target after " << racer.getMoves() << " moves." << endl;
  }
}
