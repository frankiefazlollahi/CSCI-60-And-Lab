#include <iostream>
using namespace std;

struct Time{//military time, no am/pm
int hour;
int minute;
};
Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

class Carpool{
public:
  string names[5];
  int numOfPeople;
  Time arrive;
  Carpool combineCarpool(Carpool car2)
  {
    Carpool newCar;
    int x = 0;
    newCar.numOfPeople = numOfPeople + car2.numOfPeople;
    if(numOfPeople + car2.numOfPeople <= 5) //make sure not more than 5 people in carpool
    {
      for(int i = 0; i < numOfPeople; i++) //puts names of first car in newCar carpool
      {
        newCar.names[i] = names[i];
      }
      for(int j = numOfPeople; j < numOfPeople + car2.numOfPeople; j++) //put names of 2nd car in newCar carpool
      {
        newCar.names[j] = car2.names[x];
        x++;
      }
      newCar.arrive = earlier(arrive, car2.arrive);
    }
    else
    {
      newCar.numOfPeople = 0;
      return newCar;
    }
    return newCar;
  }

  void printNames()
  {
    for(int i = 0; i < numOfPeople; i++)
    {
      cout << names[i] << " ";
    }
  }
};


  int main()
  {
    Carpool car1;
    car1.names[0] = "Kyle";
    car1.names[1] = "Sally";
    car1.numOfPeople = 2;
    car1.arrive.hour = 1;
    car1.arrive.minute = 30;
    Carpool car2;
    car2.names[0] = {"John"};
    car2.numOfPeople = 1;
    car2.arrive.hour = 2;
    car2.arrive.minute = 30;

    Carpool car = car1.combineCarpool (car2);
    car.printNames();
  }
