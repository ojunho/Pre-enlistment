////////////////////////////////////////////////////////////////////////////////
// Lab01-3-1: string Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising String length
// Algorithm: 주어진 문자열의 길이를 구하는 알고리즘이다.
// Variable :  string1 = 주어진 문자열.
//             len = string1의 길이 정보를 담는 변수이다.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  string string1 = "Hello world";
  //함수를 이용하여 int형 자료 len에 길이정보를 저장하고 출력한다.
  int len = string1.length();
  printf("length is %d", len);

  return 1;
}
