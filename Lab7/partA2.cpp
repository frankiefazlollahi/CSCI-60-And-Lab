#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
  map<string,int> served;
  fstream input;
  input.open("names.txt");
  string s;
  while(getline(input,s))
  {
    served[s]++;
  }
  input.close();
  for (auto p : served) cout << p.second << " " << p.first << endl;

  return 0;
}
