////////////////////////////////////////////////////////////////////////////////
// Lab01-3-2: string Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising Comparing between String
// Algorithm: 사용자가 입력한 문자열 두개를 비교하는 알고리즘이다.
// Variable :  mystring1/mystring2 = 사용자로부터 입력받는 두 문자열.
//             result = mystrcmp의 리턴값을 받아 할당받는 정수형 변수
//             mystrcmp() = 두 문자열을 인자로 받아 인덱싱하며 두 문자열을 비교하는 함수.
//             tmp = mystrcmp()함수 안에서 비교를 통해 나온 결과를 저장하기 위한 정수형 변수.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  char mystring1[80];
  char mystring2[80];

  cin >> mystring1;
  cin >> mystring2;

  int result = mystrcmp(mystring1, mystring2);
  printf("result is %d\n", result);

  return 1;
}

int mystrcmp(char s1[], char s2[]){
  int i = 0;
  int tmp;
  // 같을때동안, 혹은 어느 하나의 문자열이 끝나기 전동안.
  while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
    i++;
  }
  if(s1[i] > s2[i]){
    tmp = 1;
  }
  else if(s1[i] < s2[i]){
    tmp = -1;
  }
  else{
    tmp = 0;
  }
  return tmp;
}
