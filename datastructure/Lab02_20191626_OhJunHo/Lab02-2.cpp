////////////////////////////////////////////////////////////////////////////////
// Lab02-2: Recursive Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising Recursive Algorithm
// Algorithm: 사용자가 입력한 두 수의 합과 차를 구하고, 또 다른 입력한 숫자를 factorial개념
//             에서 곱하기가 아닌 더하기로 값을 구하는 알고리즘. (처음 숫자에서 1씩 빼가면서
//             모든 숫자를 합한 값을 구하는 알고리즘.)
// Variable :  num1, num2, num = 사용자가 입력하는 각각 첫번째, 두번째, 마지막 숫자.
//             result1, result2, result3 = num1과 num2의 합과 차, 그리고 마지막 숫자의 합산.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

// 재귀적 호출을 통해서 num2의 값을 1씩 증가, num1의 값을 1씩 감소 시키면서 마지막엔 num2의 값을 리턴하도록 한다.

int Add(int num1, int num2){
  if(num1 == 0){
    return num2;
  }
  else{
    return Add(num1 - 1, num2 + 1);
  }
}

// 차는 뭐가 더 클지 모르니 조건문 두개를 사용하여 각각의 경우를 대비한다.
// num1과 num2의 값을 1씩 감소 시키며, 어떤 하나가 0이 되면 다른 하나의 값을 리턴하도록 한다.
int Diff(int num1, int num2){
  if(num1 == 0){
    return num2;
  }
  else if(num2 == 0){
    return num1;
  }
  else{
    return Diff(num1 - 1, num2 - 1);
  }
}

// 처음 주어진 숫자에서 1씩 빼가며 나온 수들을 전부 합한다.
int Sum(int num){
  if(num == 1){
    return 1;
  }
  else{
    cout << "+" << num - 1;
    return num + Sum(num - 1);
  }
}

int main(){
  int result1;
  int result2;
  int result3;

  int num1;
  cout << "Enter number 1: ";
  cin >> num1;

  int num2;
  cout << "Enter number 2: ";
  cin >> num2;

  result1 = Add(num1, num2);
  result2 = Diff(num1, num2);

  cout << "  Addition Result is " << result1 << endl;
  cout << "  Difference Result is " << result2 << endl;


  int num;
  cout << "Enter a number: ";
  cin >> num;

  // 함수를 실행하기 전에 미리 출력할 부분, 함수를 실행하며 출력되는부분, 함수가 실행된 후에 출력
  // 되는 부분을 활용하여 보기 좋게 출력되도록 한다.
  cout << "  Result is: " << num;
  result3 = Sum(num);
  cout << " = " << result3 << endl;
}
