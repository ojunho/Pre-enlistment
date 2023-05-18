////////////////////////////////////////////////////////////////////////////////
//me/junho/.atom/data_s/Lab01-1_20191626_오준호/Lab01-1_20191626_오준호.cpp' 
// Lab01-1: File IO Exercise
// Name : Oh jun ho(오준호)
// ID : 20191626
// Program Description : Exercising File IO
// Algorithm: 공백과 문자로 이루어져 있는 텍스트 파일에서 각 행의 문자의 개수를 파악한다.
// Variable :  buffer = storing data from data File
//             wc = 각행에서의 단어의 개수를 저장하는 변수.
//             IN/ OUT = 커서가 단어안에 있는지 아닌지를 판단하기 위한 변수들.
//             state = 움직이는 커서.
//             total = 전체 단어의 개수를 기억하는 변수.
//             tmp = 전체 단어의 개수를 구하기 위해서 도와주는 변수.
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
//#include <studio.h>

using namespace std;

// 각 행마다 단어의 개수를 세어서 그 수를(정수형)을 리턴하는 함수를 만든다.
int WordCount(char buffer[], int wc){
  int IN = 1;
  int OUT = 0;
  int i = 0;
  int state = OUT;
  int wc = 0;

  // 조건문과 반복문을 사용하여 커서가 한칸씩 움직이며 단어에 들어갔는지 안들어갔는지를 판단하며 단어를 센다.
  while(buffer[i] != '\0'){
    if(isalpha(buffer[i])){
      if(state == OUT){
        ++wc;
        state = IN;
      }
    }
    else if(buffer[i] == ''){
      state = OUT;
    }
    i++;
  }
  return wc;
}

void main(){ // 메인함수
  //초기 설정을 해준다.
  ifstream inFile("lab1-1.dat");
  //ofstream inFile("output.txt");
  char buffer[100];
  int total = 0;
  int wc;
  int tmp;

  //파일을 열 수 없으면 에러메세지를 보내도록 한다.
  if(!inFile.is_open()){
    cerr << "error : lab1-1.dat을 열 수 없습니다." << endl;
    return;
  }

  // 콘솔창에 한줄씩 글을 읽고, 단어의 개수를 보여준다.
  while(inFile.getline(buffer,100)){
    cout << buffer << endl;
    //WordCount(buffer,wc);
    tmp = WordCount(buffer,wc);
    cout << "The number of words: " << tmp << endl;
    total = total + tmp;
  }
  inFile.close();
  // 총단어의 개수를 보여준다.
  cout << "Total Number of Words: " << total << endl;
  //return 0;
}
