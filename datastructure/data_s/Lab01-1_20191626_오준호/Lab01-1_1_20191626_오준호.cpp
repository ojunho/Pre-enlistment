#include <iostream>
#include <fstream>
#include <string>
//#include <studio.h>

using namespace std;

void WordCount(char buffer[], int wc){


}

int main(void){
  ifstream inFile("lab1-1.dat");
  //ofstream inFile("output.txt");
  char buffer[100];
  int total = 0;
  int wc;

  if(!inFile.is_open()){
    cerr << "error : lab1-1.dat을 열 수 없습니다." << endl;
    return 1;
  }

  while(inFile.getline(buffer,100)){
    cout << buffer << endl;
    WordCount(buffer,wc);
    cout << "The number of words: " << wc << endl;
    total = total + wc;
  }
  inFile.close();
  cout << "Total Number of Words: " << total << endl;
  return 0;
}
