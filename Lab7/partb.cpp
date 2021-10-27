#include <iostream>
#include <fstream>
#include <set>
#include<vector>

using namespace std;

int main()
{
  set<string> names;
  ifstream input;
  input.open("names.txt");
  string s;

  while(getline(input,s))
  {
    names.insert(s);
  }
  input.close();
  int diffPeople = names.size();
  vector<string> nameList;
  fstream input2;
  input2.open("names.txt");
  string s2;
  while(getline(input2,s2))
  {
    nameList.push_back(s2);

  }
  input2.close();
  int totalMeals = nameList.size();
  double average = (double)totalMeals / diffPeople;
  cout <<totalMeals << " / " << diffPeople<< " = " << average;

return 0;
}
