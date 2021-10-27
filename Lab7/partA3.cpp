#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  vector<string> nameList;
  fstream input;
  input.open("names.txt");
  string s;
  int count = 0;
  while(getline(input,s))
  {
    nameList.push_back(s);
    count++;
  }
  input.close();
  for (vector<string>::size_type i=0; i<nameList.size(); i++)
   {
     cout << nameList[i] << endl;
   }

  return 0;
}
