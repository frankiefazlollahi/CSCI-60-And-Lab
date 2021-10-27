// Starter file for Question 1 or HW7, due Wed 2/26 before class
// Frankie Fazlollahi
// TODO: Include your hypothesis and analysis here
/*
Hypothesis: I think the Algorithm 3 approach will be the fastest to both run and code because it uses a set, which by default does not allow repeated elements and
automatically sorts its elements alphabetically, so I wouldn't have to make code to ensure those. Meanwhile, when using a vector aprroach in Algorithms 1 and 2,
I would have to make code that takes care of repeats and have to sorts the elements of the vector.
Development Process: Algorithm 1 was pretty straight forward. I first checked if the word was already in the vector, and if it isn't, then I add it to the vector.
Then I used the sort function to sort the vector, then I just outputted its contents to a file. For Algorithm 2 I skipped the step to first check if the word is
in the vector, and just added all the words. Then I sorted that vector. Lastly, checked for duplicates as I looped through the vector by checking if the next
element in the vector is the same as the current element, and if the next element was not a duplicate, I sent it to the output file. Algorithm 3 was easier
implementing than the other two because I only had to insert the words into the set and output them to the file because they were automatically sorted, and
duplicates were not inserted.
Experiments:
 -Algorithm 1: 19.3243 seconds
 -Algorithm 2: 0.893743 seconds
 -Algorithm 3: 0.638571 seconds
As I expected, Algorithm 3 is the fastest because sets automatically prevent duplicates and order their contents alphabetically. However, I wasn't expecting the
large difference between Algorithms 1 and 2 because they do the same thing but check for duplicates at different parts of the function. It makes sense though because
Algorithm 1 needs to loop through the entire vector each time to check if the next word to be added would be a duplicate, while Algorithm 2 just needed to check if the
next element is a duplicate. I also did not expect Algorithm 2 and 3 to be so close in run times. I thought 3 would be far more efficient because sets automatically
do the alphabetizing and do not allow duplicates.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono; // for timing experiments

const int EXPERIMENT = 2; // change this as you test your algorithms (1-3)
const string INFILE = "don_quixote.txt"; //"quickbrownfox.txt"; // test with DQ
const string OUTFILE = "output.txt"; // don't change this!

void timedExperiment(string filename, int exp);
void readWithVector1(string filename);
void readWithVector2(string filename);
void readWithSet(string filname);

// starts a timed experiment based on default values or command line arguments
int main(int argc, char** argv) {
  if (argc<2) timedExperiment(INFILE,EXPERIMENT); // test according to constants
  else timedExperiment(argv[1],stoi(argv[2])); // or use command line arguments

  return 0;
}

// runs specified experiment on the specified filename and reports the time

void timedExperiment(string filename, int exp) {
  auto start = high_resolution_clock::now();
  switch (exp) {
    case 1: readWithVector1(filename); break;
    case 2: readWithVector2(filename); break;
    case 3: readWithSet(filename); break;
    default: cout << "Invalid experiment number specified\n"; return;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count()/1000000.0 << " seconds for alg " << exp <<
    " to process " << filename << endl;
}

// TODO: implement these experiments!

void readWithVector1(string filename)
{
  string word;
  bool contains = false;
  vector<string> list;
  ifstream input;
  input.open(filename);
  while(input >> word)
  {
    for(int i = 0; i < list.size(); i++)
    {
      if(list[i] == word)
      {
        contains = true;
        break;
      }
    }
    if(contains == false)
    {
      list.push_back(word);
    }
    else
    {
      contains = false;
    }
  }
  sort(list.begin(), list.end());
  input.close();

  ofstream output;
  output.open(OUTFILE);
  for(int i = 0; i < list.size(); i++)
  {
    output << list[i] << endl;
  }
  output.close();

}

void readWithVector2(string filename)
{
  string word;
  //bool duplicate = false;
  vector<string> list;
  ifstream input;
  input.open(filename);
  while(input >> word)
  {
    list.push_back(word);
  }
  sort(list.begin(), list.end());
  input.close();

  ofstream output;
  output.open(OUTFILE);
  for(int i = 0; i < list.size(); i++)
  {
    if(i < list.size() -1)
    {
      if(list[i] != list[i+1])
      {
        output << list[i] << endl;
      }
    }
    else
    {
      output << list[i] << endl;
    }
  }
  output.close();

}

void readWithSet(string filename)
{
  set<string> list;
  string word;
  ifstream input;
  input.open(filename);
  while(input >> word)
  {
    list.insert(word);
  }
  input.close();

  ofstream output;
  output.open(OUTFILE);
  for (set<string>::iterator it=list.begin(); it!=list.end(); it++)
  {
    output << *it << endl;
  }
  output.close();
}
