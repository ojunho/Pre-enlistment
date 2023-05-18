#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Triangle{

}

class Circle{

}

class Rectangle{

}


class Angle{
private:
  int type;
public:
  int width;
  int height;
  int round;
  Angle(int inputType) : type(inputType){ width = height = round = 0;}
  double calculate(){
    switch(type){
      case 1: // triangle

      case 2: // rectangle
      case 3: // circle
    }
  }
}
