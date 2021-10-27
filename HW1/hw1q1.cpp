// Starter file for Homework 1, Question 1; due before class 1/15/20
// Frankie Fazlollahi

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int N_ROLLS = 200; // how many rolls to simulate
const string DATA_FILENAME = "data.txt";
const string HIST_FILENAME = "hist.txt";

int getRoll() {return (rand()%6+rand()%6+2);}
// returns the value (between 2 and 12) of a toss of a pair of random dice

void simulateAndRecord();
// Pre:  No meaningful data is in either file
// Post: Results of simulation of N_ROLLS pairs of dice are in DATA_FILENAME

void produceHistogram();
// Pre:  DATA_FILE contains (at most) N_ROLLS values 2-12;
//       HIST_DATA has no meaningful info; both files are closed
// Post: For each val 2-12, HIST_FILE contains a line of stars
//       counting the # times that val appears in DATA_FILE

void writeLineOfStars(int rolls[], int nRolls, int val, ostream& out);
// Pre:  rolls array contains nRolls simulations; out is an opened output file
// Post: The val line of the histogram has been appended to out, e.g., if val=3
//       and 3 occured 5 times, the line would be "3: *****"

int main()
{
  simulateAndRecord();
  produceHistogram();
  return 0;
}

// simulate rolling N_ROLLS pairs of dice; record values in DATA_FILENAME
void simulateAndRecord() {
  ofstream datafile(DATA_FILENAME); // open DATA_FILENAME
  for (int i=0; i<N_ROLLS; i++) {
    datafile << getRoll() << endl; // simulate 1 roll and output it to datafile
  }
  datafile.close(); // close the file
}

void writeLineOfStars(int rolls[], int nRolls, int val, ostream& out)
{
  out << val << ": ";
  int occurence = 0;
  for(int i = 0; i < nRolls; i++)
  {
    if(rolls[i] == val)
    {
      occurence++;
    }
  }
  for(int j = 0; j < occurence; j++)
  {
    out << "*";
  }
  out << endl;
}

void produceHistogram() {
  /* TODO: implement this function; define writeLineOfStars helper */
  int rolls[N_ROLLS];
  ifstream input (DATA_FILENAME);
  int x = 0;
  //puts data from data.txt into rolls array
  while(input >> rolls[x])
  {
    x++;
  }
  input.close();
  ofstream histfile(HIST_FILENAME);
  for(int i = 2; i < 13; i++)
  {
    writeLineOfStars(rolls, N_ROLLS, i, histfile);
  }
  histfile.close();
}
