//Variable:
        //IN,OUT = 단어의 시작과 끝을 표현
        //state = 현재 탐색위치의 상태 표현
        //buffer[] = 한글자씩 저장하는 임시저장공간
        //wc = 각 줄의 단어의 개수를 세는 변수
        //total = 총 단어의 개수를 저장하는 변수



#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void wordCount(char buffer[], int &wc)
{
    int IN = 1;
    int OUT = 0;
    int i=0; int state = OUT; wc = 0;
    while (buffer[i]!='\0')
    {
        if(isalpha(buffer[i]))
        {
            if(state == OUT)
            {
                ++wc;
                state = IN;
            }
        }
        else if(buffer[i]==' '){
          state = OUT;
        }
        i++;

        }
    }
int main(void)
{
 ifstream inFile("/Users/hyunjoon/Desktop/자료구조/LAB/LAB1/lab1-1.txt");
 char buffer[100];
 int total = 0;
 int wc;
 if(inFile.fail())
 {
     cerr << "error : 파일을 열 수 없습니다." << endl;
     return 1;
  }
 while (inFile.getline(buffer,100))
 {
       cout << buffer << endl;
       wordCount(buffer,wc);
       cout << "the number of words:" << wc << endl;
       total+= wc;
     }
     cout << "Total Number of Words: " << total <<endl;
     return 0;



}
