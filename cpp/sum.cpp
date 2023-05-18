/* Problems: 주어진 정수들의 합 구하기.
소프트웨어학부 20191626 오준호 */

#include <iostream>
using namespace std;

int main(){
  int numCase;
  cin >> numCase;

  int numData;
  for(int i=0; i<numCase; i++){
    cin >> numData;
    int sum = 0;
    for(int j=0; j<numData; j++){
      int Data;
      cin >> Data;
      sum += Data;
    }
    cout << sum << endl;
  }
  return 1;
}
