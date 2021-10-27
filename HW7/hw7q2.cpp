// Starter file for Question 2 or HW7, due Wed 2/26 before class
// Frankie Fazlollahi

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const string INFILE = "records.txt";

class Records{
public:
  Records(): name("None"), password("None"), gpa(0.0){}
  Records(string n, string pass, double g): name(n), password(pass), gpa(g){}
  string getName() const {return name;}
  string getPassword() const {return password;}
  double getGPA() const {return gpa;}

private:
  string name;
  string password;
  double gpa;
};
void databaseProgram(map<int,Records> database);
int main() {
  map<int, Records> database;
  string name;
  int id;
  string password;
  double gpa;
  ifstream input;
  input.open(INFILE);
  while(input >> name)
  {
    input >> id;
    input >> password;
    input >> gpa;
    database[id] = Records(name,password,gpa);
  }
  databaseProgram(database);

  return 0;
}
void databaseProgram(map<int,Records> database)
{
  int id;
  string password;
  do{
    cout << "Enter an ID number (Enter 0 to quit):" << endl;
    cin >> id;
    if(id == 0)
    {
      break;
    }
    cout << "Enter password." << endl;
    cin >> password;
    if(database[id].getPassword() == password)
    {
      cout << "Name: " << database[id].getName() << endl;
      cout << "GPA: " << database[id].getGPA() << endl;
    }
    else
    {
      cout << "That was the wrong password." << endl;
    }
  }while(id != 0);
  cout << "Goodbye!" << endl;
}
