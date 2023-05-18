////////////////////////////////////////////////////////////////////////////////
// Lab02-1: Recursive Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising Recursive Algorithm
// Algorithm: 주어진 배열에서 사용자가 찾고싶은 숫자를 이진탐색으로 찾는데, 사용자가 반복적 알고리즘으로
//                구할것인지, 혹은 재귀 알고리즘으로 구할 것인지를 선택하도록 하는 알고리즘.
// Variable :  list = 주어진 배열.
//             size = 배열의 크기.
//             obj = 사용자가 찾으려는 숫자.
//             start, end, mid = 반복적 알고리즘에서 사용할 시작점, 끝점, 중간점.
//             left, right, mid = 재귀적 알고리즘에서 사용할 왼쪽점, 오른쪽점, 중간점.
//             route = 사용자가 반복적, 재귀적 중에서 선택하게 되는 방향.
//             result = 리턴받은 함수값을 저장하는 변수.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

// 반복적 알고리즘
int binarySearch(int list[], int size, int obj){
  // 시작점, 끝점, 중간점을 인자를 통해 설정한다.
  int start = 0;
  int end = size - 1;
  int mid;
  // 반복문을 통하여 끝까지 안나오면 -1이 리턴되도록, 값을 찾는다면 값의 위치를 리턴하도록 한다.
  while(start<=end){
    mid = (start + end)/2;
    if(list[mid] == obj){
      return mid;
    }
    // 반복문 안에서 범위를 좁혀나가는 조건문.
    else if (list[mid] > obj){
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  return -1;
}

// 재귀적 알고리즘.
int reSearch(int list[], int obj, int left, int right){
  if(right >= left){
    // 중간점을 설정해준다.
    int mid = (left + right)/2;

    if(list[mid] == obj){
      return mid;
    }
    // 영역에 따라서 다시 검사할 부분을 인자로 넣어 재귀함수를 호출한다.
    if(list[mid] > obj){
      return reSearch(list, obj, left, mid - 1);
    }
    return reSearch(list, obj, mid + 1, right);
  }
  return -1;
}


int main(){
  int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  // 크기 값을 변수에 할당해준다.
  int size = sizeof(list)/ sizeof(list[0]);

  // 찾을 숫자와, 방향을 입력받고 저장한다.
  int obj;
  cout << "Enter an integer to search: ";
  cin >> obj;

  int route;
  cout << "Enter method of search: (1. Binary Search    2. Recursive binary search): ";
  cin >> route;

  // 방향에 따라서 움직이는 조건문을 설정해준다.
  // 그 안에서 함수를 호출하여 값을 구해준다.
  if(route == 1){
    int result = binarySearch(list, size, obj);
    if(result == -1){
      cout << obj << " is NOT FOUND" << endl;
    }
    else{
      cout << obj << " is at position " << result << endl;
    }
  }
  else{
    int result = reSearch(list, obj, 0, size - 1);
    if(result == -1){
      cout << obj << " is NOT FOUND" << endl;
    }
    else{
      cout << obj << " is at position " << result << endl;
    }
  }
}
