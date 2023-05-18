////////////////////////////////////////////////////////////////////////////////
// Lab01-2: File IO Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising File IO
// Algorithm: 가장 큰 수와 가장 작은 수를 찾아 각각의 위치와 그 값을 출력한다.
// Variable :  number = 파일에서 숫자를 받는 변수
//             count = 숫자의 개수를 세는 변수
//             data = 주어지는 숫자를 저장하는 변수
//             min/max = 최댓값과 최솟값의 위치(인덱스)를 저장하는 정수값을 가지는 변수.
//             tmp1/tmp2 = 최대 최소를 찾는 함수 안에서 최댓값(혹은 최솟값)의 위치를 저장하는 변수
//
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>

using namespace std;

int main(){ // 메인 함수 시작.
  // 변수들을 지정해준다.
  int number,count,data[10];
  int position;
  ifstream infile("lab01-2.txt");
  while(infile >> number){ //데이터를 파일에서 읽은 후에
    data[count++] = number; // 배열 데이터에 저장한다.
  }
  int min = findMin(data, count); // 함수를 사용해 min에 가장 작은 수의 위치정보를 저장한다.
  int max = findMax(data, count); // 함수를 사용해 max에 가장 큰 수의 위치정보를 저장한다.
  // 인덱싱을 통해서 다음과 같이 출력한다.
  cout << "Minimum number is " << data[min] << " at position " << min + 1 << endl;
  cout << "Maximum number is " << data[max] << " at position " << max + 1 << endl;
  return 0;
}

// 함수에서는 tmp1과 반복문, 조건문을 사용하여 가장작은 수의 인덱스를 기억하여 리턴하도록 한다.
int findMin(int data[], int n){
  int min = data[0];
  int tmp1 = 0;
  for(int i = 1; i < n; i++){
    if(data[i] < min){
      min = data[i];
      tmp1 = i;
    }
  }
  return tmp1;
}

// 함수에서는 tmp2과 반복문, 조건문을 사용하여 가장 큰 수의 인덱스를 기억하여 리턴하도록 한다.
int findMax(int data[], int n){
  int max = data[0];
  int tmp2 = 0;
  for(int i = 1; i < n; i++){
    if(data[i] > max){
      max = data[i];
      tmp2 = i;
    }
  }
  return tmp2;
}
