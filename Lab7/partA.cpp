#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main()
{
  set<string> names;
  ifstream input;
  input.open("names.txt");
  string s;
  int count = 0;
  while(getline(input,s))
  {
    names.insert(s);
    count++;
  }
  input.close();
  for (set<string>::iterator it=names.begin(); it!=names.end(); it++)
  {
    cout << *it << endl;  
  }

  return 0;
}
