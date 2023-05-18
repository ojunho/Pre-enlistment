////////////////////////////////////////////////////////////////////////////////
// Lab02-2: Recursive Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising Class and Struct
// Algorithm: 구조체를 사용하여 삼각형, 직사각형, 그리고 원의 넓이를 구하는 알고리즘.
// Variable :  num1, num2 = 세 개의 클래스에서 인자값으로 받은 길이들을 저장하는 변수.
//             Triangle = 삼각형 클래스
//             Rectangle = 직사각형 클래스
//             Circle = 원 클래스
//             n, m = 클래스에서 인자로 받아오는 값들.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

// Triangle class를 정의한 부분.
class Triangle{
private:
  int num1;
  int num2;
public:
  Triangle(int n, int m){
    num1 = n;
    num2 = m;
  }

  void calculate(){
    cout << "triangle " << num1 << " " << num2 << " " << 0.5*num1*num2 << endl;
  }
};

// Circle class를 정의한 부분
class Circle{
private:
  int num1;
public:
  Circle(int n){
    num1 = n;
  }
  void calculate(){
    cout << "circle " << num1 << " " << 3.14*num1*num1 << endl;
  }
};

// Rectangle class를 정의한 부분
class Rectangle{
private:
  int num1;
  int num2;
public:
  Rectangle(int n, int m){
    num1 = n;
    num2 = m;
  }
  void calculate(){
    cout << "rectangle " << num1 << " " << num2 << " " << num1*num2 << endl;
  }
};

int main(){
  Triangle t1(20, 40);
  t1.calculate();

  Rectangle r1(40, 80);
  r1.calculate();

  Circle c1(50);
  c1.calculate();

  Rectangle r2(30, 60);
  r2.calculate();

  Triangle t2(10, 20);
  t2.calculate();

  Triangle t3(50, 30);
  t3.calculate();

  Circle c2(20);
  c2.calculate();
}
