//Frankie Fazlollahi
//The parent class is Cat. Every cat has a name, fur color, gender, and age. Cats are able to "speak" and sleep.
//Lion is the child class of Cat because Lions are a specific type of cat.
//Lions have the same variables as cats, but they also have a variable "isAdult" because male adult lions have a mane.
//Lions sleep like cats do, but they "speak" differently than ordinary cats, so the speak() function is redefined in the Lion class.
//Lions have the exclusive functions eatHuman and hasMane which are not in the base Cat class.
//This is an example of inheritance because the Lion class inherits from the Cat class, giving the Lion class access to the public functions in the Cat class.
//The Lion class also has an additional member variable isAdult which is not present in the Cat class because it is not necessary information for an ordinary
//Cat but is for a Lion because of their manes.
//The Lion class also has functions that are not present in the Cat class because Lions have additional functions that they can perform that Cats cannot.

#include <iostream>
using namespace std;

class Cat
{
public:
  //Constructors
  Cat() : name("Unnamed") , furColor("Black"), gender("none"), age(0) {}
  Cat(string name, string furColor, string gender, int age) : name(name), furColor(furColor), gender(gender), age(age) {}
  //getter functions
  string getName() {return name;}
  string getFurColor() {return furColor;}
  string getGender() {return gender;}
  int getAge() {return age;}
  //other member functions
  void speak() {
    cout << name << ": Meow" << endl;
  }
  void sleep(){
    cout << name << ": zZzzzZZzz" << endl;
  }

private:
  string name;
  string furColor;
  string gender;
  int age;
};

class Lion : public Cat
{
public:
  //Constructors
  Lion() : Cat() {
    if(Cat::getAge() >= 4)
      isAdult = true;
    else
      isAdult = false;
  }
  Lion (string theName, string theFurColor, string theGender, int theAge) : Cat(theName, theFurColor, theGender, theAge) {
    if(Cat::getAge() >= 4)
      isAdult = true;
    else
      isAdult = false;
  }
  //Redefined function of speak()
  void speak() {
    if(isAdult)
    {
      cout << Cat::getName() << ": ROOOAAAR!" << endl;
    }
    else {
      cout << Cat::getName() << ": rawr" << endl;
    }
  }
  //member functions not included in Cat class
  void eatHuman()
  {
    if(isAdult)
    {
      cout << "The adult lion named " << Cat::getName() << " ate a human." << endl;
    }
    else
    {
      cout << "The lion named " << Cat::getName() << " could not eat a human because it is too young." << endl;
    }
  }
  void hasMane(){
    if((Cat::getGender() == "male" && isAdult == true))
    {
      cout << Cat::getName() << " has a mane." << endl;
    }
    else
    {
      cout << Cat::getName() << " doesn't have a mane." << endl;
    }
  }

private:
  bool isAdult;
};

void catDescription(Cat aCat);
void lionDescription(Lion aLion);
void escape(Lion aLion);

int main()
{
  Cat theCat = Cat("Milo", "white and gray", "male", 2);
  catDescription(theCat);
  cout << "Say hi kitty." << endl;
  theCat.speak();
  cout << "Time for " << theCat.getName() << " to go to bed." << endl;
  theCat.sleep();
  cout << endl;

  Lion adult = Lion("Leo", "tan", "male", 5);
  lionDescription(adult);
  cout << "Say hi kitty." << endl;
  adult.speak();
  escape(adult);
  cout << "Time for " << adult.getName() << " to go to bed." << endl;
  adult.sleep();
  cout << endl;

  Lion child = Lion("Simba", "brownish gold", "male", 3);
  lionDescription(child);
  cout << "Say hi kitty." << endl;
  child.speak();
  escape(child);
  cout << "Time for " << child.getName() << " to go to bed." << endl;
  child.sleep();
  cout << endl;

  return 0;
}

void catDescription(Cat aCat)
{
  cout << aCat.getName() << " is a " << aCat.getAge() << " year old " << aCat.getGender() << " cat, and has " << aCat.getFurColor() << " colored fur." << endl;
}

void lionDescription(Lion aLion)
{
  cout << aLion.getName() << " is a " << aLion.getAge() << " year old " << aLion.getGender() << " lion, and has " << aLion.getFurColor() << " colored fur and ";
  aLion.hasMane();
}
void escape(Lion aLion)
{
  cout << "Oh no! " << aLion.getName() << " has broken out of the zoo!" << endl;
  aLion.eatHuman();
  cout <<aLion.getName() << " was caught by authorities." << endl;
}
