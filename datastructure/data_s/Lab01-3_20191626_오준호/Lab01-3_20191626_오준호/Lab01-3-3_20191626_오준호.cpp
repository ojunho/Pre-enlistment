////////////////////////////////////////////////////////////////////////////////
// Lab01-3-3: String Concatenation Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising String Concatenation
// Algorithm: 문자열 두개를 사용자로부터 입력받고, 두 문자열을 합하는 알고리즘이다.
// Variable :  string1/ string2 = 사용자로부터 입력받을 두 문자열.
//             len = string1의 길이 정보를 담는 변수이다.
//             myconcat = string1의 뒤에 string2를 더하는 함수이다.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  //사용자로부터 입력받음.
  string string1;
  cin >> string1;

  string string2;
  cin >> string2;

  // 함수를 사용해 string1의 뒤에 string2를 더해 변경한다.
  myconcat(string1, string2);

  cout << "String Concatenation : " << string1;

  return 1;
}

void myconcat(string &string1, string &string2){
  int i = 0;
  while(string1[i] != NULL){
    i++;
  }
  int j = 0;
  while(string2[j] != NULL){
    i++;
    string1[i] = string2[j];
    j++;
  }
  string1[i] = NULL;
}

// cat rat
