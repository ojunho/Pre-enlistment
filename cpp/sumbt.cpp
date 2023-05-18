/* Problems: 두 정수 사이의 모든 정수의 합 구하기.
소프트웨어학부 20191626 오준호*/

#include <iostream>
using namespace std;

int main(){
  int numCase;
  cin >> numCase;

  int num1, num2;

  for(int i=0; i<numCase; i++){
    cin >> num1;
    cin >> num2;
    int sum = 0;
    while(num1 <= num2){
      sum+=num1;
      num1++;
    }
    cout << sum << endl;
  }
  return 0;
}
