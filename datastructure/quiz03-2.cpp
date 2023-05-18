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
